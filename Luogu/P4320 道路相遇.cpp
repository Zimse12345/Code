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

inline int read(){int qrx=0,qry=1;char qrc=getchar();
while(qrc<'0'||qrc>'9'){if(qrc=='-'){qry=-1,qrc=getchar();}else qrc=getchar();}
while(qrc>='0'&&qrc<='9')qrx=qrx*10+qrc-48,qrc=getchar();return qrx*qry;}

const int N=1e6+7,Mod=998244353,INF=1e9+7;
int n,m,q,hd[N*2],to[N*2],nxt[N*2],ec;
int Hd[N*2],To[N*2],Nxt[N*2],Ec,_n;
int dfn[N],low[N],Time,stk[N],top;
int fa[N],dep[N],cnt[N],son[N],tp[N];
inline void add(int u,int v){nxt[++ec]=hd[u],hd[u]=ec,to[ec]=v;return;}
inline void Add(int u,int v){Nxt[++Ec]=Hd[u],Hd[u]=Ec,To[Ec]=v;return;}

void tarjan(int u){
	dfn[u]=low[u]=++Time,stk[++top]=u;
	for(int i=hd[u],v;i;i=nxt[i]){
		v=to[i];
		if(!dfn[v]){
			tarjan(v),low[u]=min(low[u],low[v]);
			if(low[v]>=dfn[u]){
				++_n;
				Add(_n,u),Add(u,_n);
				int x=0;
				do{
					x=stk[top--];
					Add(_n,x),Add(x,_n);
				}while(x!=v);
			}
		}
		else low[u]=min(low[u],dfn[v]);
	}
	return;
}

void dfs1(int u,int from,int d){
	fa[u]=from,dep[u]=d,cnt[u]=1;
	for(int i=Hd[u],v;i;i=Nxt[i]){
		v=To[i];
		if(v==from)continue;
		dfs1(v,u,d+1),cnt[u]+=cnt[v];
		if(cnt[son[u]]<cnt[v])son[u]=v;
	}
	return;
}

void dfs2(int u,int from,int d){
	tp[u]=d;
	if(son[u])dfs2(son[u],u,d);
	for(int i=Hd[u],v;i;i=Nxt[i]){
		v=To[i];
		if(v==from||v==son[u])continue;
		dfs2(v,u,v);
	}
	return;
}

signed main(){
	_n=n=read(),m=read();
	for(int i=1,u,v;i<=m;i++)u=read(),v=read(),add(u,v),add(v,u);
	tarjan(1);
	dfs1(1,0,1);
	dfs2(1,0,1);
	q=read();
	while(q--){
		int u=read(),v=read();
		int x=u,y=v;
		while(tp[x]^tp[y]){
			if(dep[tp[x]]<dep[tp[y]])swap(x,y);
			x=fa[tp[x]];
		}
		if(dep[y]<dep[x])x=y;
		int dis=dep[u]+dep[v]-2*dep[x];
		printf("%d\n",dis/2+1);
	}
	return 0;
}

