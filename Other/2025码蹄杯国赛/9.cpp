#include <bits/stdc++.h>
#define int long long
using namespace std;

const int N=2.01e5,inf=1e18;
int T,n,m,k,t;
int d[N],id[N],pre[N];
int dis[N][32];
bool vis[N][32];

struct edge{
    int to,w;
    edge(int to=0,int w=0):to(to),w(w){}
};
vector<edge> g[N];

struct node{
    int pos,z,val;
    node(int pos=0,int z=0,int val=0):pos(pos),z(z),val(val){}
    bool operator < (const node& _)const{return val>_.val;} 
};
priority_queue<node> Q;

signed main(){
    scanf("%lld",&T);
    while(T--){
        scanf("%lld%lld%lld%lld",&n,&m,&k,&t);
        for(int i=1;i<=n;i++){
            g[i].resize(0);
            id[i]=pre[i]=0;
        }
        for(int i=1,u,v,w;i<=m;i++){
            scanf("%lld%lld%lld",&u,&v,&w);
            g[u].push_back(edge(v,w));
            g[v].push_back(edge(u,w));
        }
        for(int i=1;i<=k;i++){
            cin>>d[i];
            id[d[i]]=i;
        }
        for(int i=1,u,v;i<=t;i++){
            cin>>u>>v;
            pre[v]|=(1<<(id[u]-1));
        }
        
        for(int i=1;i<=n;i++){
            for(int j=0;j<(1<<k);j++)dis[i][j]=inf,vis[i][j]=false;
        }
        dis[1][0]=0;
        Q.push(node(1,0,0));
        while(!Q.empty()){
            int u=Q.top().pos,z=Q.top().z;
            Q.pop();
            if(vis[u][z])continue;
            vis[u][z]=true;
            for(unsigned i=0;i<g[u].size();i++){
                int v=g[u][i].to;
                if((pre[v]&z)!=pre[v]){
                    continue;
                }
                int _z=z;
                if(id[v])_z|=(1<<(id[v]-1));
                if(dis[u][z]+g[u][i].w<dis[v][_z]){
                    dis[v][_z]=dis[u][z]+g[u][i].w;
                    Q.push(node(v,_z,dis[v][_z]));
                }
            }
        }
        int ans=inf;
        for(int i=0;i<(1<<k);i++)ans=min(ans,dis[n][i]);
        if(ans==inf)printf("impossible\n");
        else printf("%lld\n",ans);
    }
    return 0;
}


