#include <bits/stdc++.h>
#define int long long
using namespace std;

const int N=1.01e6;
int n,deg[N],f[N][2],ans;
vector<int> g[N];

void dfs(int u,int from){
    deg[u]=g[u].size();
    if(deg[u]==2)f[u][0]=1;
    for(unsigned i=0;i<g[u].size();i++){
        int v=g[u][i];
        if(v==from)continue;
        dfs(v,u);
        ans+=f[u][0]*f[v][1]+f[u][1]*(f[v][0]+f[v][1]);
        if(deg[u]==3)f[u][1]+=f[v][0]+f[v][1];
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


