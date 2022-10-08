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

using namespace std;
 
inline int read(){int qrx=0,qry=1;char qrc=getchar();
while(qrc<'0'||qrc>'9'){if(qrc=='-'){qry=-1,qrc=getchar();}else qrc=getchar();}
while(qrc>='0'&&qrc<='9')qrx=qrx*10+qrc-48,qrc=getchar();return qrx*qry;}
 
const int N=1e5+7,Mod=1e9+7,INF=1e14+7;
struct edge{
	int to,w;
	edge(int to=0,int w=0):to(to),w(w){}
};
int n,cnt[N],fa[N],fw[N],f[N],ans=INF;
vector<edge> g[N];

void dfs1(int u,int from){
	for(int i=0,v,w;i<signed(g[u].size());i++){
		v=g[u][i].to,w=g[u][i].w;
		if(v==from)continue;
		dfs1(v,u),fa[v]=u,fw[v]=w,cnt[u]+=cnt[v],f[u]+=f[v]+cnt[v]*w;
	}
	return;
}

void dfs2(int u){
	if(u!=1)f[u]=f[fa[u]]+(cnt[1]-2*cnt[u])*fw[u];
	for(int i=0,v;i<signed(g[u].size());i++){
		v=g[u][i].to;
		if(v==fa[u])continue;
		dfs2(v);
	}
	return;
}

signed main(){
	n=read();
	for(int i=1;i<=n;i++)cnt[i]=read();
	for(int i=1,u,v,w;i<n;i++){
		u=read(),v=read(),w=read();
		g[u].push_back(edge(v,w)),g[v].push_back(edge(u,w));
	}
	dfs1(1,0);
	dfs2(1);
	for(int i=1;i<=n;i++)ans=min(ans,f[i]);
	printf("%lld\n",ans);
	return 0;
}
