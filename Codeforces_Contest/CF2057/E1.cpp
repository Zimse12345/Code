#include <bits/stdc++.h>
using namespace std;

const int N=410;
int T,n,m,q,W[N],d[N][N][N];

struct edge{
    int to,w;
    edge(int to=0,int w=0):to(to),w(w){}
};
vector<edge> g[N];
edge Q[1000000];

signed main(){
    cin>>T;
    while(T--){
        cin>>n>>m>>q;
        for(int i=1;i<=n;i++){
            g[i].resize(0);
            for(int j=1;j<=m;j++){
                for(int k=1;k<=n;k++)d[i][j][k]=1e9;
            }
        }
        for(int i=1,u,v,w;i<=m;i++){
            cin>>u>>v>>w;
            W[i]=w;
            g[u].push_back(edge(v,w));
            g[v].push_back(edge(u,w));
        }
        sort(W+1,W+m+1);
        for(int i=1;i<=n;i++){
            for(int j=1;j<=m;j++){
                int L=m*m,R=m*m;
                Q[m*m]=edge(i,0);
                while(L<=R){
                    int v=Q[L].to,s=Q[L].w;
                    ++L;
                    if(s<d[i][j][v]){
                        d[i][j][v]=s;
                        for(unsigned i=0;i<g[v].size();i++){
                            int u=g[v][i].to,w=g[v][i].w;
                            if(w<=W[j])Q[--L]=edge(u,s);
                            else Q[++R]=edge(u,s+1);
                        }
                    }
                }
            }
        }
        while(q--){
            int a,b,k,ans=0;
            cin>>a>>b>>k;
            for(int i=1;i<=m;i++){
                if(d[a][i][b]<k){
                    ans=W[i];
                    break;
                }
            }
            printf("%d\n",ans);
        } 
    }
    return 0;
}


