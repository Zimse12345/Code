#include <bits/stdc++.h>
using namespace std;

const int N=2.01e3,inf=1e9;
int n,m,deg[N],ans=inf,vis[N][N];
struct edge{
    int v,w;
    edge(int v=0,int w=0):v(v),w(w){}
};
struct node{
    int x,y;
    node(int x=0,int y=0):x(x),y(y){}
};
vector<edge> g[N];
queue<node> q;

signed main(){
    cin>>n>>m;
    for(int i=1,u,v,w;i<=m;i++){
        cin>>u>>v>>w;
        g[u].push_back(edge(v,w));
    }
    q.push(node(1,0));
    while(!q.empty()){
        int u=q.front().x,x=q.front().y;
        if(u==n)ans=min(ans,x);
        q.pop();
        if(vis[u][x]++)continue;
        for(unsigned i=0;i<g[u].size();i++){
            q.push(node(g[u][i].v,x^g[u][i].w));
        }
    }
    if(ans==inf)ans=-1;
    printf("%d\n",ans);
    return 0;
}


