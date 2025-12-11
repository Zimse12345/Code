#include <bits/stdc++.h>
#define int long long
using namespace std;

const int N=2.01e5,B=1500;
int T,n,q,a[N],h[N];
int f[150][N],tot,id[N];

struct edge{
    int to,w;
    edge(int to=0,int w=0):to(to),w(w){}
};
vector<edge> g[N],G[N];

signed main(){
    cin>>T;
    while(T--){
        cin>>n>>q;
        int ans=0,W=0;
        for(int i=1;i<=n;i++)cin>>a[i];
        for(int i=1,u,v,c;i<n;i++){
            cin>>u>>v>>c;
            g[u].push_back(edge(v,c));
            g[v].push_back(edge(u,c));
            if(a[u]==a[v])ans+=c;
            W+=c;
        }
        for(int i=1;i<=n;i++){
            if(g[i].size()>B){
                h[i]=1;
                id[i]=++tot;
                for(unsigned j=0;j<g[i].size();j++){
                    int v=g[i][j].to;
                    f[tot][a[v]]+=g[i][j].w;
                    if(h[v]){
                        G[i].push_back(edge(v,g[i][j].w));
                        G[v].push_back(edge(i,g[i][j].w));
                    }
                }
            }
            else h[i]=0;
        }
        while(q--){
            int x,c;
            cin>>x>>c;
            if(h[x]){
                ans+=f[id[x]][c]-f[id[x]][a[x]];
                for(unsigned i=0;i<G[x].size();i++){
                    int y=G[x][i].to;
                    f[id[y]][a[x]]-=G[x][i].w;
                    f[id[y]][c]+=G[x][i].w;
                }
            }
            else for(unsigned i=0;i<g[x].size();i++){
                int y=g[x][i].to;
                if(h[y]){
                    f[id[y]][a[x]]-=g[x][i].w;
                    f[id[y]][c]+=g[x][i].w;
                }
                if(a[y]==a[x])ans-=g[x][i].w;
                if(a[y]==c)ans+=g[x][i].w;
            }
            a[x]=c;
            printf("%lld\n",W-ans);
        }
        while(tot>0){
            for(int i=1;i<=n;i++)f[tot][i]=0;
            --tot;
        }
        for(int i=1;i<=n;i++){
            g[i].resize(0);
            G[i].resize(0);
            h[i]=0;
        }
    }
    return 0;
}


