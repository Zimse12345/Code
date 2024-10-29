#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <stack>
#include <set>
#include <map>
#include <list>
#include <math.h>
#include <functional> 

#define endl '\n'
#define pii pair<int, int>
#define pdd pair<double, double> 
#define fi first
#define se second
#define pb push_back
#define eb emplace_back
#define codeforces cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(false)
#define bendl(x) x.begin(), x.end()
#define siz(x) ((int)(x).size())
#define int long long

using namespace std;

const int inf = 1ll << 60;
const int mod = 998244353;
const int N = 5e5 + 10, M = N << 1;
int n,m,vis[N],dis[N][2],U[N],V[N],W[N],tag[N];

struct edge{
    int to,w,id;
    edge(int to=0,int w=0,int id=0):to(to),w(w),id(id){}
};
vector<edge> g[N],G[N];
struct node{
    int x,y;
    node(int x=0,int y=0):x(x),y(y){}
    bool operator < (const node& _)const{return y>_.y;}
};
priority_queue<node> Q;

void Dijkstra(int s,int T){
    for(int i=1;i<=n;i++)vis[i]=0,dis[i][T]=inf;
    dis[s][T]=0,Q.push(node(s,0));
    while(!Q.empty()){
        int u=Q.top().x;
        Q.pop();
        if(vis[u]++)continue;
        for(unsigned i=0;i<g[u].size();i++){
            int v=g[u][i].to,w=g[u][i].w;
            if(dis[u][T]+w<dis[v][T])dis[v][T]=dis[u][T]+w,Q.push(node(v,dis[v][T]));
        }
    }
    return;
}

int dfn[N],low[N],Time;
void tarjan(int u,int from){
    dfn[u]=low[u]=++Time;
    for(unsigned i=0;i<G[u].size();i++){
        int v=G[u][i].to;
        if(!dfn[v]){
            tarjan(v,G[u][i].id);
            if(dfn[u]<low[v])tag[G[u][i].id]=1;
        }
        if(G[u][i].id!=from)low[u]=min(low[u],low[v]);
    }
    return;
}

void solve(){
    cin>>n>>m;
    for(int i=1,u,v,w;i<=m;i++){
        cin>>u>>v>>w;
        g[u].push_back(edge(v,w,i));
        g[v].push_back(edge(u,w,i));
        U[i]=u,V[i]=v,W[i]=w;
    }
    Dijkstra(1,0);
    Dijkstra(n,1);
    for(int i=1;i<=m;i++){
        if(dis[U[i]][0]+W[i]+dis[V[i]][1]==dis[n][0]||dis[V[i]][0]+W[i]+dis[U[i]][1]==dis[n][0]){
            G[U[i]].push_back(edge(V[i],0,i));
            G[V[i]].push_back(edge(U[i],0,i));
        }
    }
    tarjan(1,0);
    for(int i=1;i<=m;i++){
        if(tag[i])printf("Yes\n");
        else printf("No\n");
    }
}

signed main(){
    
    int t = 1; // cin >> t;
    while(t--) solve();
    return 0;
}
