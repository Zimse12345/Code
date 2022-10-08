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
int n,m,q,hd[N],nxt[N],to[N],ec=1,ans=1;
int dfn[N],low[N],Time,stk[N],top,col[N],cc;
int fa[N],dep[N],cnt[N],son[N],Top[N],A[N],B[N];
vector<int> Q[N],p,g[N];
inline void add(int u,int v){nxt[++ec]=hd[u],hd[u]=ec,to[ec]=v;return;}

void tarjan(int u,int fid){
	dfn[u]=low[u]=++Time,stk[++top]=u,p.push_back(u);
	for(int i=hd[u],v;i;i=nxt[i]){
		if(i==fid||(i^1)==fid)continue;
		v=to[i];
		if(!dfn[v])tarjan(v,i);
		low[u]=min(low[u],low[v]);
	}
	if(low[u]==dfn[u]){
		++cc;
		while(stk[top+1]^u)col[stk[top]]=cc,--top;
	}
	return;
}

void dfs(int u,int from){
	for(int i=0,v;i<signed(g[u].size());i++){
		v=g[u][i];
		if(v!=from&&(i==0||v!=g[u][i-1]))dfs(v,u),A[u]+=A[v],B[u]+=B[v];
	}
	if(A[u]&&B[u])ans=0;
	return;
}

void dfs1(int u,int from,int d){
	fa[u]=from,dep[u]=d,cnt[u]=1;
	for(int i=0,v;i<signed(g[u].size());i++){
		v=g[u][i];
		if(v!=from&&(i==0||v!=g[u][i-1])){
			dfs1(v,u,d+1);
			cnt[u]+=cnt[v];
			if(cnt[son[u]]<cnt[v])son[u]=v;
		}
	}
	return;
}

void dfs2(int u,int from,int d){
	Top[u]=d;
	if(son[u])dfs2(son[u],u,d);
	for(int i=0,v;i<signed(g[u].size());i++){
		v=g[u][i];
		if(v!=from&&v!=son[u]&&(i==0||v!=g[u][i-1]))dfs2(v,u,v);
	}
	return;
}

int LCA(int u,int v){
	while(Top[u]^Top[v]){
		if(dep[Top[u]]<dep[Top[v]])swap(u,v);
		u=fa[Top[u]];
	}
	return dep[u]<dep[v]?u:v;
}

signed main(){
	n=read(),m=read(),q=read();
	for(int i=1,u,v;i<=m;i++)u=read(),v=read(),add(u,v),add(v,u);
	for(int i=1,u,v;i<=q;i++)u=read(),v=read(),Q[u].push_back(v);
	for(int i=1;i<=n;i++)if(!dfn[i]){
		p.resize(0),tarjan(i,0);
		for(int ii=0,u;ii<signed(p.size());ii++){
			u=p[ii];
			for(int iii=hd[u],v;iii;iii=nxt[iii]){
				v=to[iii];
				if(col[u]^col[v])g[col[u]].push_back(col[v]);
			}
		}
		for(int i=1;i<=cc;i++)sort(g[i].begin(),g[i].end());
		dfs1(1,0,1);
		dfs2(1,0,1);
		for(int ii=0,u;ii<signed(p.size());ii++){
			u=p[ii];
			for(int j=0,x,y,lca;j<signed(Q[u].size());j++){
				x=col[u],y=col[Q[u][j]];
				if(!y){
					printf("No\n");
					return 0;
				}
				lca=LCA(x,y);
				--A[lca],--B[lca],++A[x],++B[y];
			}
		}
		dfs(1,0);
		for(int i=0;i<signed(p.size());i++)col[p[i]]=0;
		for(int i=1;i<=cc;i++){
			g[i].resize(0),son[i]=0;
			A[i]=B[i]=0;
		}
		cc=0;
	}
	if(ans)printf("Yes\n");
	else printf("No\n");
	return 0;
}

