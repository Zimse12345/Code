#include <bits/stdc++.h>
#define int long long
using namespace std;

const int N=2.01e5,M=30,inf=1e9;
int n,f[N],ans=-1;
vector<int> g[N],v[N];

void dfs(int u,int from){
    for(unsigned i=0;i<g[u].size();i++){
        if(g[u][i]==from)continue;
        dfs(g[u][i],u);
        v[u].push_back(f[g[u][i]]);
    }
    f[u]=1;
    sort(v[u].begin(),v[u].end());
    int sz=v[u].size();
    for(int i=sz-1;i>=0&&i>=sz-3;i--)f[u]+=v[u][i];
    if(sz<3)f[u]=1;
    if(from&&sz>=3)ans=max(ans,f[u]+1);
    if(sz>=4){
        ans=max(ans,f[u]+v[u][sz-4]);
    }
    return;
}

signed main(){
    cin>>n;
    for(int i=1,u,v;i<n;i++){
        cin>>u>>v;
        g[u].push_back(v);
        g[v].push_back(u);
    }
    dfs(1,0);
    printf("%lld\n",ans);
    return 0;
}


