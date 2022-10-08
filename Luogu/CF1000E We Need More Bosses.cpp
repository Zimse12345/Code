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
int n,m,hd[N],nxt[N],to[N],ec,ans;
int dfn[N],low[N],Time,stk[N],top,col[N],ecnt,dep[N];
vector<int> g[N],p;
inline void add(int u,int v){nxt[++ec]=hd[u],hd[u]=ec,to[ec]=v;return;}

void tarjan(int u,int from){
	dfn[u]=low[u]=++Time,stk[++top]=u,p.push_back(u);
	for(int i=hd[u],v;i;i=nxt[i]){
		v=to[i];
		if(v==from)continue;
		if(!dfn[v])tarjan(v,u);
		low[u]=min(low[u],low[v]); 
	}
	if(dfn[u]==low[u]){
		++ecnt;
		while(stk[top+1]^u)col[stk[top]]=ecnt,--top;
	}
	return;
}

void dfs(int u,int from){
	int mx=0,se=0;
	for(int i=0,v;i<signed(g[u].size());i++){
		v=g[u][i];
		if(v!=from&&(i==0||v!=g[u][i-1])){
			dfs(v,u);
			if(dep[v]>mx)se=mx,mx=dep[v];
			else if(dep[v]>se)se=dep[v];
		}
	}
	ans=max(ans,mx+se),dep[u]=mx+1;
	return;
}

signed main(){
	n=read(),m=read();
	for(int i=1,u,v;i<=m;i++)u=read(),v=read(),add(u,v),add(v,u);
	for(int i=1;i<=n;i++)if(!dfn[i]){
		tarjan(i,0);
		for(int j=0,u;j<signed(p.size());j++){
			u=p[j];
			for(int k=hd[u],v;k;k=nxt[k]){
				v=to[k];
				if(col[u]^col[v])g[col[u]].push_back(col[v]);
			}
		}
		for(int j=1;j<=ecnt;j++)sort(g[j].begin(),g[j].end());
		dfs(1,0);
		for(int j=1;j<=ecnt;j++)g[j].resize(0);
		ecnt=0,p.resize(0);
	}
	printf("%d\n",ans);
	return 0;
}

