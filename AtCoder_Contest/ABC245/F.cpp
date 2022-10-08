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
int n,m,P,hd[N],nxt[N],to[N],ec,vis[N],mx[N],cnt[N];
int dfn[N],low[N],st[N],top,ct,cl[N],scc,sz[N],ans,T[N];
vector<int> g[N];
inline void add(int u,int v){nxt[++ec]=hd[u],hd[u]=ec,to[ec]=v;return;}

void tarjan(int u){
	dfn[u]=low[u]=++ct,st[++top]=u;
	for(int i=hd[u],v;i;i=nxt[i]){
		v=to[i];
		if(!dfn[v])tarjan(v),low[u]=min(low[u],low[v]);
		else if(!cl[v])low[u]=min(low[u],dfn[v]);
	}
	if(low[u]==dfn[u]){
		cl[u]=++scc,sz[scc]=1;
		while(st[top]!=u)cl[st[top--]]=scc,++sz[scc];
		--top;
	}
	return;
}

void dp(int u){
	if(vis[u]++)return;
	for(unsigned i=0;i<g[u].size();i++){
		int v=g[u][i];
		if(i==0||v!=g[u][i-1]){
			dp(v);
			T[u]|=T[v];
		}
	}
	return;
}

signed main(){
	n=read(),m=read();
	for(int i=1,u,v;i<=m;i++)u=read(),v=read(),add(u,v);
	for(int i=1;i<=n;i++)if(!dfn[i])tarjan(i);
	for(int u=1;u<=n;u++){
		for(int i=hd[u],v;i;i=nxt[i]){
			v=to[i];
			if(cl[u]!=cl[v])g[cl[u]].push_back(cl[v]);
		}
	}
	for(int i=1;i<=scc;i++){
		sort(g[i].begin(),g[i].end());
		if(sz[i]>1)T[i]=1;
	}
	for(int i=1;i<=scc;i++)if(!vis[i])dp(i);
	for(int i=1;i<=scc;i++)ans+=T[i]*sz[i];
	printf("%d\n",ans);
	return 0;
}

