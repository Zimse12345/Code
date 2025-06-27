#include <bits/stdc++.h>
using namespace std;

const int N=1e6+7,INF=2e9+7;
int n,m,dis[N][2],vis[N],lim;
struct edge{
	int to,w;
	edge(int to=0,int w=0):to(to),w(w){}
};
struct node{
	int x,d;
	node(int x=0,int d=0):x(x),d(d){}
	bool operator <(const node& A)const{return d>A.d;}
};
vector<edge> g[N];
priority_queue <node> Q;

void Dijkstra(int s,int id){
	for(int i=1;i<=n;i++)dis[i][id]=INF,vis[i]=0;
	while(!Q.empty())Q.pop();
	dis[s][id]=0,Q.push(node(s,0));
	while(!Q.empty()){
		int u=Q.top().x;
        Q.pop();
		if(vis[u]++)continue;
		for(int i=0;i<int(g[u].size());i++){
			int v=g[u][i].to,w=g[u][i].w;
			if((w|lim)==lim){
				dis[v][id]=0;
				Q.push(node(v,0));
			}
		}
	}
	return;
}

int main(){
	cin>>n>>m;
	for(int i=1,u,v,w;i<=m;i++){
		cin>>u>>v>>w;
		g[u].push_back(edge(v,w));
		g[v].push_back(edge(u,w));
	}
	int ans=(1<<30)-1;
	lim=ans;
	for(int i=29;i>=0;i--){
	    lim-=(1<<i);
	    Dijkstra(1,0);
	    if(dis[n][0]<INF)ans=lim;
	    else lim+=(1<<i);
    }
    printf("%d\n",ans);
	return 0;
}
