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

using namespace std;

inline int read(){int qrx=0,qry=1;char qrc=getchar();
while(qrc<'0'||qrc>'9'){if(qrc=='-'){qry=-1,qrc=getchar();}else qrc=getchar();}
while(qrc>='0'&&qrc<='9')qrx=qrx*10+qrc-48,qrc=getchar();return qrx*qry;}
inline void write(int x){if(x<0){putchar('-'),x=-x;}if(x>9)write(x/10);putchar(x%10+'0');}

const int N=1e6+7,Mod=998244353,INF=1e9+7;
int n,m,fa[N],dep[N],cnt[N],son[N],top[N];
int ct,hd[N],to[N],nxt[N];

inline void add(int u,int v){
	to[++ct]=v,nxt[ct]=hd[u],hd[u]=ct;
	return;
}

void dfs1(int u,int from,int d){
	fa[u]=from,dep[u]=d,cnt[u]=1;
	for(int i=hd[u],v;i;i=nxt[i]){
		v=to[i];
		if(v==from)continue;
		dfs1(v,u,d+1),cnt[u]+=cnt[v];
		if(cnt[v]>cnt[son[u]])son[u]=v;
	}
	return;
}

void dfs2(int u,int from,int pr){
	top[u]=pr;
	if(son[u])dfs2(son[u],u,pr);
	for(int i=hd[u],v;i;i=nxt[i]){
		v=to[i];
		if(v==from||v==son[u])continue;
		dfs2(v,u,v);
	}
	return;
}

int LCA(int a,int b){
	while(top[a]!=top[b]){
		if(dep[top[a]]<dep[top[b]])swap(a,b);
		a=fa[top[a]];
	}
	if(dep[a]<dep[b])return a;
	return b;
}

int Dis(int a,int b){
	int c=LCA(a,b);
	return dep[a]+dep[b]-dep[c]*2;
}

signed main(){
	n=read(),m=read();
	for(int i=1,u,v;i<n;i++)u=read(),v=read(),add(u,v),add(v,u);
	dfs1(1,0,0),dfs2(1,0,1);
	for(int i=1,x,y,z,ans,ans2;i<=m;i++){
		x=read(),y=read(),z=read();
		int xy=LCA(x,y),yz=LCA(y,z),zx=LCA(z,x);
		ans=INF;
		if(Dis(x,y)+Dis(xy,z)<ans)ans=Dis(x,y)+Dis(xy,z),ans2=xy;
		if(Dis(y,z)+Dis(yz,x)<ans)ans=Dis(y,z)+Dis(yz,x),ans2=yz;
		if(Dis(z,x)+Dis(zx,y)<ans)ans=Dis(z,x)+Dis(zx,y),ans2=zx;
		printf("%d %d\n",ans2,ans);
	}
	return 0;
}
