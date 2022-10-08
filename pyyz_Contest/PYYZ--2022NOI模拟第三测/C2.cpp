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
#include <bitset>

#define ll long long
#define ull unsigned long long

using namespace std;

inline int read(){int qrx=0,qry=1;char qrc=getchar();
while(qrc<'0'||qrc>'9'){if(qrc=='-')qry=-1;qrc=getchar();}
while(qrc>='0'&&qrc<='9')qrx=qrx*10+qrc-48,qrc=getchar();return qrx*qry;}

const int N=3e5+7,M=1e6+7,Mod=998244353,INF=1e9+7;
int n,m,x[N],y[N],v[N],hd[M],nxt[M],to[M],ec=1,vis[N],tag[M];
int dfn1[N],dfn2[N],Time1,Time2,p[N],col[N],mn[N],ans[N],tr[N];
inline void add(int u,int v){nxt[++ec]=hd[u],hd[u]=ec,to[ec]=v;return;}
inline void ins(int x,int v){for(;x<=n;x+=(x&(-x)))tr[x]+=v;return;}
inline int qsum(int x){int res=0;for(;x;x-=(x&(-x)))res+=tr[x];return res;}

void dfs0(int u){
	if(vis[u]++)return;
	for(int i=hd[u],v,p=0;i;i=nxt[i]){
		v=to[i];
		if(y[v]>y[u]){
			dfs0(v);
			tag[p^1]=0,tag[i^1]=1,p=-1;
		}
		if(x[v]>x[u]){
			dfs0(v);
			if(p!=-1)p=i,tag[i^1]=1;
		}
	}
	return;
}

void dfs1(int u,int Tag){
	if(Tag)dfn1[u]=++Time1;
	else dfn2[u]=++Time2;
	for(int i=hd[u],v;i;i=nxt[i])if(tag[i]){
		v=to[i];
		if(y[v]<y[u])dfs1(v,Tag);
	}
	for(int i=hd[u],v;i;i=nxt[i])if(tag[i]){
		v=to[i];
		if(x[v]<x[u])dfs1(v,Tag);
	}
	return;
}

signed main(){
	n=read(),m=read();
	for(int i=1;i<=n;i++)x[i]=read(),y[i]=read(),v[i]=read();
	for(int i=1,u,v;i<=m;i++){
		u=read(),v=read();
		add(u,v),add(v,u);
	}
	dfs0(1);
	dfs1(n,1);
	for(int i=1;i<=ec;i++)tag[i]=0;
	for(int i=1;i<=n;i++)vis[i]=0,swap(x[i],y[i]);
	dfs0(1);
	dfs1(n,0);
	for(int i=1;i<=n;i++)p[dfn1[i]]=dfn2[i],col[dfn1[i]]=v[i];
	for(int i=1;i<=n;i++){
		if(!mn[col[i]])mn[col[i]]=p[i],ins(p[i],1);
		else if(p[i]<mn[col[i]])ins(mn[col[i]],-1),mn[col[i]]=p[i],ins(p[i],1);
		ans[i]=qsum(p[i]);
	}
	for(int i=1;i<=n;i++)printf("%d\n",ans[dfn1[i]]);
	return 0;
}

