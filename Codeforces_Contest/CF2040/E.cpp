#include <bits/stdc++.h>
#define int long long
using namespace std;

const int N=2.01e3;
int T,n,q,f[N][N],fa[N];
vector<int> g[N];

void dfs(int u,int from){
    fa[u]=from;
    if(u!=1){
        int cnt=g[u].size();
        for(int p=0;p<=n;p++){
            f[u][p]=f[fa[fa[u]]][p]+cnt*2;
            if(p>0)f[u][p]=min(f[u][p],f[fa[fa[u]]][p-1]+2);
        }
    }
    for(unsigned i=0;i<g[u].size();i++){
        if(g[u][i]!=from)dfs(g[u][i],u);
    }
}

signed main(){
    cin>>T;
    while(T--){
        cin>>n>>q;
        for(int i=0;i<=n;i++){
            g[i].resize(0);
            f[0][i]=-1;
        }
        for(int i=1,u,v;i<n;i++){
            cin>>u>>v;
            g[u].push_back(v);
            g[v].push_back(u);
        }
        dfs(1,0);
        while(q--){
            int v,p;
            cin>>v>>p;
            printf("%lld\n",f[fa[v]][p]+1);
        }
    }
    return 0;
}


