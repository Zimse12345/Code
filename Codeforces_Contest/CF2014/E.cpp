#include <bits/stdc++.h>
#define int long long
using namespace std;

const int N=1.01e6,inf=1e18;
int T,n,m,h,vis[N],dis[N][2];
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
priority_queue<node> Q;

void Dijkstra(int s,int id){
	for(int i=1;i<=n*2;i++)dis[i][id]=inf,vis[i]=0;
	while(!Q.empty())Q.pop();
	dis[s][id]=0,Q.push(node(s,0));
	while(!Q.empty()){
		int u=Q.top().x;Q.pop();
		if(vis[u]++)continue;
		for(unsigned i=0;i<g[u].size();i++){
			int v=g[u][i].to,w=g[u][i].w;
			if(dis[v][id]>dis[u][id]+w){
				dis[v][id]=dis[u][id]+w;
				Q.push(node(v,dis[v][id]));
			}
		}
	}
	return;
}

signed main(){
    cin>>T;
    while(T--){
        cin>>n>>m>>h;
        for(int i=1;i<=n*2;i++)g[i].resize(0);
        for(int i=1,x;i<=h;i++){
            cin>>x;
            g[x].push_back(edge(x+n,0));
        }
        for(int i=1,u,v,w;i<=m;i++){
            cin>>u>>v>>w;
            g[u].push_back(edge(v,w));
            g[v].push_back(edge(u,w));
            g[u+n].push_back(edge(v+n,w/2));
            g[v+n].push_back(edge(u+n,w/2));
        }
        Dijkstra(1,0);
        Dijkstra(n,1);
        int ans=inf;
        for(int i=1;i<=n;i++){
            ans=min(ans,max(min(dis[i][0],dis[i+n][0]),min(dis[i][1],dis[i+n][1])));
        }
        if(ans==inf)ans=-1;
        printf("%lld\n",ans);
    }
    return 0;
}


