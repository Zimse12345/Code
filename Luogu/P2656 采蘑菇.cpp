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

const int N=2e5+7,Mod=998244353,INF=1e9+7;
int n,m,a[N],f[N],vis[N],s;
struct edge{
	int to,w,r;
	edge(int to=0,int w=0,int r=0):to(to),w(w),r(r){};
};
vector<edge> g[N];
vector<edge> G[N];

int dfn[N],low[N],st[N],top,ins[N],ind;
int sc,scc[N];
void tarjan(int u){
	dfn[u]=low[u]=++ind,st[++top]=u,ins[u]=1;
	for(int i=0;i<int(g[u].size());i++){
		int v=g[u][i].to;
		if(!dfn[v])tarjan(v),low[u]=min(low[u],low[v]);
		else if(ins[v])low[u]=min(low[u],dfn[v]);
	}
	if(low[u]==dfn[u]){
		++sc;
		while(st[top]!=u)scc[st[top]]=sc,ins[st[top]]=0,--top;
		scc[u]=sc,ins[u]=0,--top;
	}
	return;
}

int dfs(int u){
	if(vis[u]++)return f[u];
	for(int i=0;i<int(G[u].size());i++)f[u]=max(f[u],G[u][i].w+dfs(G[u][i].to));
	f[u]+=a[u];
	return f[u];
}

int main(){
	n=read(),m=read();
	for(int i=1,u,v,w;i<=m;i++){
		u=read(),v=read(),w=read();
		double r;
		cin>>r;
		g[u].push_back(edge(v,w,int(r*10)));
	}
	for(int i=1;i<=n;i++)if(!dfn[i])tarjan(i);
	for(int u=1;u<=n;u++){
		for(int i=0,v;i<int(g[u].size());i++){
			v=g[u][i].to;
			int val=g[u][i].w;
			if(scc[u]==scc[v]){
				while(val>0)a[scc[u]]+=val,val=val*g[u][i].r/10;//printf("(%d %d %d)\n",val,g[u][i].r,0);
			}
			else G[scc[u]].push_back(edge(scc[v],val,1));
		}
	}
	s=read();
	dfs(scc[s]);
	printf("%d\n",f[scc[s]]);
	return 0;
}
