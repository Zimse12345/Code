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

const int N=2e6+7,Mod=998244353,INF=1e9+7;
int n,s,dep[N],ans;
struct edge{
	int to,w;
	edge(int to=0,int w=0):to(to),w(w){}
};
vector<edge> g[N];

void dfs(int u,int pr){
	int mx=0;
	for(unsigned i=0,v,w;i<g[u].size();i++){
		v=g[u][i].to,w=g[u][i].w;
		if(v==pr)continue;
		dfs(v,u);
		dep[u]=max(dep[u],dep[v]+w);
		mx=max(mx,dep[v]+w);
	}
	for(unsigned i=0,v,w;i<g[u].size();i++){
		v=g[u][i].to,w=g[u][i].w;
		if(v==pr)continue;
		ans+=mx-dep[v]-w;
	}
	return;
}

signed main(){
	n=read(),s=read();
	for(int i=1,u,v,w;i<n;i++){
		u=read(),v=read(),w=read();
		g[u].push_back(edge(v,w)),g[v].push_back(edge(u,w));
	}
	dfs(s,0);
	printf("%lld\n",ans);
	return 0;
}
