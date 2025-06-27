#include <bits/stdc++.h>
using namespace std;

const int N=1.01e6;
int n,m,cnt,vis[N];
vector<int> g[N];

void dfs(int u){
    vis[u]=1;
    for(unsigned i=0;i<g[u].size();i++){
        int v=g[u][i];
        if(!vis[v])dfs(v);
    }
    return;
}

signed main(){
    cin>>n>>m;
    for(int i=1,u,v;i<=m;i++){
        cin>>u>>v;
        g[u].push_back(v);
        g[v].push_back(u);
    }
    for(int i=1;i<=n;i++)if(!vis[i]){
        dfs(i),++cnt;
    }
    printf("%d\n",m-(n-cnt));
    return 0;
}


