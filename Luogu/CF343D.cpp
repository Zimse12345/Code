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

#define int long long
#define Lid (id<<1)
#define Rid ((id<<1)|1)

using namespace std;

int read(){int qrx=0,qry=1;char qrc=getchar();
while(qrc<'0'||qrc>'9'){if(qrc=='-'){qry=-1,qrc=getchar();}else qrc=getchar();}
while(qrc>='0'&&qrc<='9')qrx=qrx*10+qrc-48,qrc=getchar();return qrx*qry;}

const int N=1e6+7,Mod=998244353,INF=1e9+7;
int n,m,dfn[N],cnt[N],fa[N],dep[N],son[N],top[N],ct,sum[N*4],tag[N*4];
vector<int> g[N];

void dfs1(int u,int from,int d){
	fa[u]=from,dep[u]=d,cnt[u]=1;
	for(int i=0,v;i<signed(g[u].size());i++){
		v=g[u][i];
		if(v==from)continue;
		dfs1(v,u,d+1),cnt[u]+=cnt[v];
		if(cnt[v]>cnt[son[u]])son[u]=v;
	}
	return;
}

void dfs2(int u,int from,int tp){
	dfn[u]=++ct,top[u]=tp;
	if(son[u])dfs2(son[u],u,tp);
	for(int i=0,v;i<signed(g[u].size());i++){
		v=g[u][i];
		if(v==fa[u]||v==son[u])continue;
		dfs2(v,u,v);
	}
	return;
}

void pushdown(int id){
	if(tag[id]){
		sum[id]=tag[id]-1;
		tag[Lid]=tag[Rid]=tag[id],tag[id]=0;
	}
	return;
}

void update(int L,int R,int id,int l,int r,int x){
	pushdown(id);
	if(l<=L&&r>=R)tag[id]=x+1,pushdown(id);
	else{
		int M=(L+R)>>1;
		if(l<=M)update(L,M,Lid,l,r,x);
		if(r>M)update(M+1,R,Rid,l,r,x);
	}
	return;
}

int query(int L,int R,int id,int p){
	pushdown(id);
	if(L==R)return sum[id];
	int M=(L+R)>>1;
	if(p<=M)return query(L,M,Lid,p);
	else return query(M+1,R,Rid,p);
}

signed main(){
	n=read();
	for(int i=1,u,v;i<n;i++){
		u=read(),v=read();
		g[u].push_back(v),g[v].push_back(u);
	}
	dfs1(1,0,0),dfs2(1,0,1);
	m=read();
	for(int i=1,op,u;i<=m;i++){
		op=read(),u=read();
		if(op==1)update(1,n,1,dfn[u],dfn[u]+cnt[u]-1,1);
		if(op==2)while(u)update(1,n,1,dfn[top[u]],dfn[u],0),u=fa[top[u]];
		if(op==3)printf("%lld\n",query(1,n,1,dfn[u]));
	}
	return 0;
}
