#include <cstdio>
#include <algorithm>
#include <cstring>
#include <vector>
#include <cmath>
#include <set>
#include <map>
#include <queue>
#include <stack>
#include <iostream>
#include <cstdlib>
#include <ctime>

#define ll long long
#define ull unsigned long long

using namespace std;

int read(){int qrx=0,qry=1;char qrc=getchar();
while(qrc<'0'||qrc>'9'){if(qrc=='-'){qry=-1,qrc=getchar();}else qrc=getchar();}
while(qrc>='0'&&qrc<='9')qrx=qrx*10+qrc-48,qrc=getchar();return qrx*qry;}

const int N=1e5+7,Mod=998244353,INF=1e9+7;
int n,ans,hd[N],nxt[N],to[N],ec;
int sz,rs,rt,cnt[N],vis[N];
int lc,rc,t1[N],t2[N],r1[N],c1,r2[N],c2;
char s[N];
struct node{int x,y,z;node(int x=0,int y=0,int z=0):x(x),y(y),z(z){}}L[N],R[N];
inline void add(int u,int v){nxt[++ec]=hd[u],hd[u]=ec,to[ec]=v;return;}

void findrt(int u,int from){
	cnt[u]=1;
	int ms=0;
	for(int i=hd[u],v;i;i=nxt[i]){
		v=to[i];
		if(vis[v]||v==from)continue;
		findrt(v,u),cnt[u]+=cnt[v];
		ms=max(ms,cnt[v]);
	}
	ms=max(ms,sz-cnt[u]);
	if(ms<rs)rs=ms,rt=u;
	return;
}

void dfs(int u,int from,node l,node r){
	if(s[u]=='('){
		if(l.y)--l.y;
		else ++l.x,++l.z;
	}
	else ++l.y,l.z=max(l.z,l.y);
	L[++lc]=l;
	if(s[u]==')'){
		if(r.y)--r.y;
		else ++r.x,++r.z;
	}
	else ++r.y,r.z=max(r.z,r.y);
	R[++rc]=r;
	for(int i=hd[u],v;i;i=nxt[i]){
		v=to[i];
		if(vis[v]||v==from)continue;
		dfs(v,u,l,r);
	}
	return;
}

void calc(int u){
	node l=node(1,0,1);
	if(s[u]==')')l=node(0,1,1);
	if(l.y==0)t1[1]=1,r1[++c1]=1;
	for(int i=hd[u],v;i;i=nxt[i]){
		v=to[i];
		if(vis[v])continue;
		lc=rc=0,L[++lc]=l,dfs(v,u,l,node(0,0,0));
		for(int j=1;j<=lc;j++)if(L[j].y==0&&t2[L[j].x])ans=max(ans,max(t2[L[j].x],L[j].z));
		for(int j=1;j<=rc;j++)if(R[j].y==0&&t1[R[j].x])ans=max(ans,max(t1[R[j].x],R[j].z));
		for(int j=1;j<=lc;j++)if(L[j].y==0){
			t1[L[j].x]=max(t1[L[j].x],L[j].z),r1[++c1]=L[j].x;
			if(L[j].x==0)ans=max(ans,L[j].z);
		}
		for(int j=1;j<=rc;j++)if(R[j].y==0){
			t2[R[j].x]=max(t2[R[j].x],R[j].z),r2[++c2]=R[j].x;
			if(R[j].x==0)ans=max(ans,R[j].z);
		}
	}
	for(int i=1;i<=c1;i++)t1[r1[i]]=0;
	for(int i=1;i<=c2;i++)t2[r2[i]]=0;
	c1=c2=0;
	return;
}

void divide(int u){
	vis[u]=1;
	calc(u);
	for(int i=hd[u],v;i;i=nxt[i]){
		v=to[i];
		if(vis[v])continue;
		sz=cnt[v],rs=INF,findrt(v,u);
		divide(rt);
	}
	return;
}

signed main(){
	n=read();
	for(int i=2,f;i<=n;i++)f=read(),add(i,f),add(f,i);
	for(int i=1;i<=n;i++)do{s[i]=getchar();}while(s[i]!='('&&s[i]!=')');
	sz=n,rs=INF,findrt(1,0);
	divide(rt);
	printf("%d\n",ans);
	return 0;
}

