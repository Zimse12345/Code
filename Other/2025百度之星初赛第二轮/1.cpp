#include <bits/stdc++.h>
using namespace std;

const int N=1.01e6;
int T,n,f[N][3];
long long ans;
vector<int> g[N];

void dfs(int u,int from){
    if(g[u].size()==1)f[u][0]=1;
    for(unsigned i=0;i<g[u].size();i++){
        int v=g[u][i];
        if(v==from)continue;
        dfs(v,u);
        ans-=1ll*f[u][0]*f[v][2];
        ans-=1ll*f[u][1]*f[v][1];
        ans-=1ll*f[u][2]*f[v][0];
        f[u][1]+=f[v][0];
        f[u][2]+=f[v][1];
    }
    return;
}

signed main(){
    cin>>T;
    while(T--){
        cin>>n;
        for(int i=1,u,v;i<n;i++){
            cin>>u>>v;
            g[u].push_back(v);
            g[v].push_back(u);
        }
        ans=1ll*n*(n-1)/2;
        ans-=n-1;
        dfs(1,0);
        printf("%lld\n",ans);
        for(int i=1;i<=n;i++){
            g[i].resize(0);
            f[i][0]=f[i][1]=f[i][2]=0;
        }
    }
    return 0;
}


