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

const int N=1e3+7,Mod=998244353,INF=1e9+7;
int n,m,w[N],v[N],d[N],hd[N],nxt[N],to[N],ec,E[N][N],pr[N],ans;
int dfn[N],low[N],st[N],tot,ct,in_s[N],cl[N],scc,W[N],V[N],f[N][N];
vector<int> g[N];
inline void add(int u,int v){nxt[++ec]=hd[u],hd[u]=ec,to[ec]=v;return;}

void tarjan(int u){
	dfn[u]=low[u]=++ct,st[++tot]=u,in_s[u]=1;
	for(int i=hd[u],v;i;i=nxt[i]){
		v=to[i];
		if(!dfn[v])tarjan(v),low[u]=min(low[u],low[v]);
		else if(in_s[v])low[u]=min(low[u],dfn[v]);
	}
	if(dfn[u]==low[u]){
		++scc,cl[u]=scc,in_s[u]=0;
		while(st[tot]!=u)cl[st[tot]]=scc,in_s[st[tot]]=0,--tot;
		--tot;
	}
	return;
}

void dfs(int u){
	for(unsigned i=0;i<g[u].size();i++){
		int v=g[u][i];
		dfs(v);
		for(int a=m;a>=0;a--){
			for(int b=1;b<=a;b++)f[u][a]=max(f[u][a],f[u][a-b]+f[v][b]);
		}
	}
	for(int i=m;i>=W[u];i--)f[u][i]=f[u][i-W[u]]+V[u];
	for(int i=0;i<=min(W[u]-1,m);i++)f[u][i]=0;
	return;
}

signed main(){
	n=read(),m=read();
	for(int i=1;i<=n;i++)w[i]=read();
	for(int i=1;i<=n;i++)v[i]=read();
	for(int i=1;i<=n;i++){
		d[i]=read();
		if(d[i])add(d[i],i);
	}
	for(int i=1;i<=n;i++)if(!dfn[i])tarjan(i);
	for(int i=1;i<=n;i++)W[cl[i]]+=w[i],V[cl[i]]+=v[i];
	for(int u=1;u<=n;u++){
		for(int i=hd[u],v;i;i=nxt[i]){
			v=to[i];
			if(cl[u]==cl[v]||E[cl[u]][cl[v]])continue;
			E[cl[u]][cl[v]]=1,g[cl[u]].push_back(cl[v]),++pr[cl[v]];
		}
	}
	for(int i=1;i<=scc;i++)if(!pr[i])g[0].push_back(i);
	dfs(0);
	for(int i=0;i<=m;i++)ans=max(ans,f[0][i]);
	printf("%d\n",ans);
	return 0;
}

