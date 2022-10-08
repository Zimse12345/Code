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
#define ull unsigned long long

using namespace std;

int read(){int qrx=0,qry=1;char qrc=getchar();
while(qrc<'0'||qrc>'9'){if(qrc=='-'){qry=-1,qrc=getchar();}else qrc=getchar();}
while(qrc>='0'&&qrc<='9')qrx=qrx*10+qrc-48,qrc=getchar();return qrx*qry;}

const int N=2e5+7,Mod=998244353,INF=1e9+7;
int n,m,k,fa[N],fw[N],dep[N],d[N],f[N],G[N];
struct edge{
	int to,w;
	edge(int to=0,int w=0):to(to),w(w){};
};
vector<edge> g[N],ch[N];

void dfs(int u,int pr,int dp){
	dep[u]=dp,f[u]=d[u];
	for(int i=0;i<g[u].size();i++){
		int v=g[u][i].to;
		if(v==pr)continue;
		dfs(v,u,dp+1),fa[v]=u,fw[v]=g[u][i].w;
		ch[u].push_back(g[u][i]);
		f[u]=max(f[u],g[u][i].w+f[v]);
	}
	return;
}

void dfs2(int u){
	if(u!=1){
		G[u]=f[u];
		int x=fa[u];
		for(int i=0;i<ch[x].size();i++){
			int v=ch[x][i].to;
			if(u==v)continue;
			else G[u]=max(G[u],f[v]+ch[x][i].w+fw[u]);
		}
	}
	for(int i=0;i<ch[u].size();i++){
		int v=ch[u][i].to;
		dfs2(v);
	}
	return;
}

signed main(){
	n=read();
	for(int i=1,u,v,w;i<n;i++){
		u=read(),v=read(),w=read();
		g[u].push_back(edge(v,w));
		g[v].push_back(edge(u,w));
	}
	for(int i=1;i<=n;i++)d[i]=read();
	dfs(1,0,0),G[1]=f[1];
	dfs2(1);
	for(int i=1;i<=n;i++)printf("%d\n",G[i]);
	return 0;
}
