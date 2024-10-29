#include <bits/stdc++.h>
using namespace std;

const int N=1.01e6;
int T,n,d[N],maxd[N],c[N],f[N];
vector<int> g[N];

void dfs(int u,int from){
    d[u]=d[from]+1;
    maxd[u]=d[u];
    for(unsigned i=0;i<g[u].size();i++){
        int v=g[u][i];
        if(v==from)continue;
        dfs(v,u);
        maxd[u]=max(maxd[u],maxd[v]);
    }
    ++c[d[u]];
    ++f[maxd[u]];
    return;
} 

signed main(){
    cin>>T;
    while(T--){
        cin>>n;
        for(int i=0;i<=n;i++){
            g[i].resize(0);
            c[i]=f[i]=0;
        }
        for(int i=1,u,v;i<n;i++){
            cin>>u>>v;
            g[u].push_back(v);
            g[v].push_back(u);
        }
        dfs(1,0);
        int ans=n-1;
        for(int i=1;i<=n;i++)f[i]+=f[i-1];
        for(int i=n,s=0;i>=1;i--){
            ans=min(ans,s+f[i-1]);
            s+=c[i];
        }
        printf("%d\n",ans);
    }
    return 0;
}


