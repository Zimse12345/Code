#include <bits/stdc++.h>
#define int long long
using namespace std;

const int N=2048,inf=1ll<<60;
int n,m,to[16][16],ans=inf;

void dfs(int u,int z,int x){
    if(u==n-1){
        ans=min(ans,x);
        return;
    }
    for(int v=0;v<n;v++)if(!(z&(1<<v))){
        if(to[u][v]!=-1)dfs(v,z|(1<<v),x^to[u][v]);
    }
    return; 
}

signed main(){
    cin>>n>>m;
    for(int i=0;i<=n;i++){
        for(int j=0;j<=n;j++)to[i][j]=-1;
    }
    for(int i=1,u,v,w;i<=m;i++){
        cin>>u>>v>>w;
        --u,--v;
        to[u][v]=w;
        to[v][u]=w;
    }
    dfs(0,1,0);
    printf("%lld\n",ans);
    return 0;
}


