#include <bits/stdc++.h>
using namespace std;

const int N=1.01e6;
int n,k,f[N];
vector<int> g[N];

void dfs(int u,int from){
    int x=0,y=0,z=0;
    for(unsigned i=0;i<g[u].size();i++){
        int v=g[u][i];
        if(v==from)continue;
        dfs(v,u);
        if(f[v]){
            if(f[v]==-1)z=1;
            else if(y)z=1;
            else if(x)y=f[v];
            else x=f[v];
        }
    }
    if(z)f[u]=-1;
    else if(x+y+1==k)f[u]=0;
    else if(y>0)f[u]=-1;
    else f[u]=x+1;
//    printf("f[%d]=%d\n",u,f[u]);
    return;
}

signed main(){
    cin>>n>>k;
    for(int i=1,u,v;i<n*k;i++){
        cin>>u>>v;
        g[u].push_back(v);
        g[v].push_back(u);
    }
    dfs(1,0);
    if(f[1]==0)printf("Yes\n");
    else printf("No\n");
    return 0;
}


