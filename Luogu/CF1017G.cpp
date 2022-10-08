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

#define Lid (id<<1)
#define Rid ((id<<1)|1)

using namespace std;

int read(){int qrx=0,qry=1;char qrc=getchar();
while(qrc<'0'||qrc>'9'){if(qrc=='-'){qry=-1,qrc=getchar();}else qrc=getchar();}
while(qrc>='0'&&qrc<='9')qrx=qrx*10+qrc-48,qrc=getchar();return qrx*qry;}

const int N=4e5+7,Mod=998244353,INF=1e9+7;
int n,q,fa[N],cnt[N],dep[N],dfn[N],ct,top[N],hv[N];
int len[N<<2],sum[N<<2],nx[N<<2],tag[N<<2];
vector<int> g[N];
struct node{int x,y;node(int x=0,int y=0):x(x),y(y){}};
node p[N];

int dfs1(int u){
	for(int i=0;i<int(g[u].size());i++){
		cnt[u]+=dfs1(g[u][i]);
		if(cnt[g[u][i]]>cnt[hv[u]])hv[u]=g[u][i];
	}
	return cnt[u];
}

void dfs2(int u,int pr){
	top[u]=pr,dfn[u]=++ct;
	if(hv[u])dfs2(hv[u],pr);
	for(int i=0,v;i<int(g[u].size());i++){
		v=g[u][i];
		if(v!=hv[u])dfs2(v,v);
	}
	return;
}

void pushdown(int id){
	if(tag[id]){
		sum[id]=-len[id],nx[id]=-1,tag[id]=0;
		if(len[id]>1)tag[Lid]=tag[Rid]=1;
	}
	return;
}

void build(int L,int R,int id){
	len[id]=R-L+1,sum[id]=-len[id],nx[id]=-1;
	if(L!=R)build(L,(L+R)/2,Lid),build((L+R)/2+1,R,Rid);
	return;
}

void update1(int L,int R,int id,int x,int p){
	pushdown(id);
	if(L==R)sum[id]+=p,nx[id]+=p;
	else{
		int M=(L+R)>>1;
		if(x<=M)update1(L,M,Lid,x,p);
		else pushdown(Lid);
		if(x>M)update1(M+1,R,Rid,x,p);
		else pushdown(Rid);
		sum[id]=sum[Lid]+sum[Rid],nx[id]=max(nx[Rid],sum[Rid]+nx[Lid]);
	}
	return;
}

void update2(int L,int R,int id,int l,int r){
	pushdown(id);
	if(l<=L&&r>=R)tag[id]=1,pushdown(id);
	else{
		int M=(L+R)>>1;
		if(l<=M)update2(L,M,Lid,l,r);
		else pushdown(Lid);
		if(r>M)update2(M+1,R,Rid,l,r);
		else pushdown(Rid);
		sum[id]=sum[Lid]+sum[Rid],nx[id]=max(nx[Rid],sum[Rid]+nx[Lid]);
	}
	return;
}

node query(int L,int R,int id,int l,int r){
	pushdown(id);
	if(l<=L&&r>=R)return node(nx[id],sum[id]);
	int M=(L+R)>>1;
	if(r<=M)return query(L,M,Lid,l,r);
	if(l>M)return query(M+1,R,Rid,l,r);
	node lc=query(L,M,Lid,l,r),rc=query(M+1,R,Rid,l,r);
	return node(max(rc.x,rc.y+lc.x),lc.y+rc.y);
}

int maxsuf(int x){
	int t=0;
	while(x){
		p[++t]=query(1,n,1,dfn[top[x]],dfn[x]);
		x=fa[top[x]];
	}
	int res=p[1].x,s=p[1].y;
	for(int i=2;i<=t;i++)res=max(res,s+p[i].x),s+=p[i].y;
	return res;
}

int main(){
	n=read(),q=read(),cnt[1]=1;
	for(int i=2,u;i<=n;i++){
		u=read();
		g[u].push_back(i),fa[i]=u,cnt[i]=1,dep[i]=dep[u]+1;
	}
	dfs1(1),dfs2(1,1),build(1,n,1);
	for(int i=1,op,x;i<=q;i++){
		op=read(),x=read();
		if(op==1)update1(1,n,1,dfn[x],1);
		if(op==2)update2(1,n,1,dfn[x],dfn[x]+cnt[x]-1),update1(1,n,1,dfn[x],-1-maxsuf(x));
		if(op==3){
			if(maxsuf(x)>=0)printf("black\n");
			else printf("white\n");
		}
	}
	return 0;
}
