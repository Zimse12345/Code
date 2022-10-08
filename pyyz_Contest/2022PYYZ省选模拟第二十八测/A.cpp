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

#pragma GCC optimize(3)
#pragma GCC target("avx")
#pragma GCC optimize("Ofast")
#pragma GCC optimize("inline")
#pragma GCC optimize("-fgcse")
#pragma GCC optimize("-fgcse-lm")
#pragma GCC optimize("-fipa-sra")
#pragma GCC optimize("-ftree-pre")
#pragma GCC optimize("-ftree-vrp")
#pragma GCC optimize("-fpeephole2")
#pragma GCC optimize("-ffast-math")
#pragma GCC optimize("-fsched-spec")
#pragma GCC optimize("unroll-loops")
#pragma GCC optimize("-falign-jumps")
#pragma GCC optimize("-falign-loops")
#pragma GCC optimize("-falign-labels")
#pragma GCC optimize("-fdevirtualize")
#pragma GCC optimize("-fcaller-saves")
#pragma GCC optimize("-fcrossjumping")
#pragma GCC optimize("-fthread-jumps")
#pragma GCC optimize("-funroll-loops")
#pragma GCC optimize("-fwhole-program")
#pragma GCC optimize("-freorder-blocks")
#pragma GCC optimize("-fschedule-insns")
#pragma GCC optimize("inline-functions")
#pragma GCC optimize("-ftree-tail-merge")
#pragma GCC optimize("-fschedule-insns2")
#pragma GCC optimize("-fstrict-aliasing")
#pragma GCC optimize("-fstrict-overflow")
#pragma GCC optimize("-falign-functions")
#pragma GCC optimize("-fcse-skip-blocks")
#pragma GCC optimize("-fcse-follow-jumps")
#pragma GCC optimize("-fsched-interblock")
#pragma GCC optimize("-fpartial-inlining")
#pragma GCC optimize("no-stack-protector")
#pragma GCC optimize("-freorder-functions")
#pragma GCC optimize("-findirect-inlining")
#pragma GCC optimize("-fhoist-adjacent-loads")
#pragma GCC optimize("-frerun-cse-after-loop")
#pragma GCC optimize("inline-small-functions")
#pragma GCC optimize("-finline-small-functions")
#pragma GCC optimize("-ftree-switch-conversion")
#pragma GCC optimize("-foptimize-sibling-calls")
#pragma GCC optimize("-fexpensive-optimizations")
#pragma GCC optimize("-funsafe-loop-optimizations")
#pragma GCC optimize("inline-functions-called-once")
#pragma GCC optimize("-fdelete-null-pointer-checks")
#pragma GCC optimize(2)

#define ll long long
#define ull unsigned long long

using namespace std;

inline int read(){int qrx=0,qry=1;char qrc=getchar();
while(qrc<'0'||qrc>'9'){if(qrc=='-'){qry=-1,qrc=getchar();}else qrc=getchar();}
while(qrc>='0'&&qrc<='9')qrx=qrx*10+qrc-48,qrc=getchar();return qrx*qry;}

const int N=1e6+7,Mod=998244353,INF=1e9+7;
int n,m,hd[N],nxt[N],to[N],ec;
int dfn[N],low[N],st[N],top,ct,cl[N],scc,sz[N];
int ans_u[N],ans_v[N];
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

int vis[N],P,V;
void dfs(int u){
	if(vis[u]==P)return;
	vis[u]=P;
	if(u==V)return;
	for(unsigned i=0;i<g[u].size();i++){
		if(vis[V]==P)return;
		int v=g[u][i];
		if(i==0||v!=g[u][i-1]){
			dfs(v); 
		}
	}
	return;
}

signed main(){
	n=read(),m=read();int ans=m;
	if(n>25000){
		printf("NO\n");
		return 0;
	}
	for(int i=1,u,v;i<=m;i++){
		u=read(),v=read(),add(u,v);
		ans_u[i]=u,ans_v[i]=v;
	}
	for(int i=1;i<=n;i++)if(!dfn[i])tarjan(i);
	for(int u=1;u<=n;u++){
		for(int i=hd[u],v;i;i=nxt[i]){
			v=to[i];
			if(cl[u]!=cl[v])g[cl[u]].push_back(cl[v]);
		}
	}
	for(int i=1;i<=scc;i++)sort(g[i].begin(),g[i].end());
	m=read();
	while(m--){
		++P;
		int u=read(),v=read();V=cl[v];
		dfs(cl[u]);
		if(vis[cl[v]]==P){
			printf("NO\n");
			return 0;
		}
	}
	printf("YES\n");
	printf("%d\n",ans);
	for(int i=1;i<=ans;i++)printf("%d %d\n",ans_u[i],ans_v[i]);
	return 0;
}

