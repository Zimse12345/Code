#include <bits/stdc++.h>
using namespace std;

const int N=1.01e6;
int T,n,m,t0,t1,t2,dis[N],vis[N];

struct edge{
    int to,w1,w2;
    edge(int to=0,int w1=0,int w2=0):to(to),w1(w1),w2(w2){}
};
struct node{
    int p,dis;
    node(int p=0,int dis=0):p(p),dis(dis){}
    bool operator < (const node &_)const{return dis<_.dis;}
};
vector<edge> g[N];
priority_queue<node> Q;

signed main(){
    cin>>T;
    while(T--){
        cin>>n>>m>>t0>>t1>>t2;
        for(int i=1;i<=n;i++)g[i].resize(0);
        for(int i=1,u,v,w1,w2;i<=m;i++){
            cin>>u>>v>>w1>>w2;
            g[u].push_back(edge(v,w1,w2));
            g[v].push_back(edge(u,w1,w2));
        }
        for(int i=1;i<=n;i++)dis[i]=-1,vis[i]=0;
        dis[n]=t0;
        Q.push(node(n,t0));
        while(!Q.empty()){
            int u=Q.top().p;
            Q.pop();
            if(vis[u]++)continue;
            for(unsigned i=0;i<g[u].size();i++){
                int v=g[u][i].to,w=0;
                if(dis[u]<=t1||dis[u]-g[u][i].w1>=t2)w=g[u][i].w1;
                else w=g[u][i].w2;
                int t=dis[u]-w;
                if(dis[u]>=t1)t=max(t,t1-g[u][i].w1);
                if(t>dis[v]){
                    dis[v]=t;
                    Q.push(node(v,dis[v]));
                }
            }
        }
        printf("%d\n",dis[1]);
    }
    return 0;
}


