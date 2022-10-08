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

const int N=2e6+7,Mod=998244353,INF=1e15+7;
int n,m,S,T,U,V,dis[N][4],vis[N];
struct edge{
	int to,w,tag;
	edge(int to=0,int w=0,int tag=0):to(to),w(w),tag(tag){}
};
struct node{
	int id,d;
	node(int id=0,int d=0):id(id),d(d){}
	bool operator < (const node& A)const{return d>A.d;}
};
vector<edge> g[N];
priority_queue<node> Q;

void Dijkstra(int s,int p){
	for(int i=1;i<=n;i++)dis[i][p]=INF,vis[i]=0;
	while(!Q.empty())Q.pop();
	dis[s][p]=0,Q.push(node(s,0));

	while(!Q.empty()){
		int u=Q.top().id;
		Q.pop();
		if(vis[u]++)continue;
		for(int i=0,v,w;i<signed(g[u].size());i++){
			v=g[u][i].to,w=g[u][i].w;
			if(g[u][i].tag==1)w=0;
			if(dis[u][p]+w<dis[v][p]){
				dis[v][p]=dis[u][p]+w;
				Q.push(node(v,dis[v][p]));
			}
		}
	}
	return;
}

signed main(){
	n=read(),m=read();
	S=read(),T=read(),U=read(),V=read();
	for(int i=1,u,v,w;i<=m;i++){
		u=read(),v=read(),w=read();
		g[u].push_back(edge(v,w,0)),g[v].push_back(edge(u,w,0));
	}
	Dijkstra(S,0),Dijkstra(T,1);
	int Dis=dis[S][1];
	for(int u=1;u<=n;u++){
		for(int i=0,v,w;i<signed(g[u].size());i++){
			v=g[u][i].to,w=g[u][i].w;
			if(dis[u][0]+dis[v][1]+w==Dis)g[u][i].tag=1;
			else g[u][i].tag=0;
		}
	}
	Dijkstra(U,2);
	int ans=dis[V][2];
	for(int u=1;u<=n;u++){
		for(int i=0,v,w;i<signed(g[u].size());i++){
			v=g[u][i].to,w=g[u][i].w;
			if(dis[u][1]+dis[v][0]+w==Dis)g[u][i].tag=1;
			else g[u][i].tag=0;
		}
	}
	Dijkstra(U,2);
	ans=min(ans,dis[V][2]);
	printf("%lld\n",ans);
	return 0;
}
