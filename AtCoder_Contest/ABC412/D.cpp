#include <bits/stdc++.h>
using namespace std;

const int N=1.01e3;
int n,m,g[N][N],f[N][10][10],vis[N][10][10];

int dfs(int z,int u,int v){
    if(!z){
        if(u==v)return 0;
        else return (g[u][v]^1);
    }
    if(vis[z][u][v])return f[z][u][v];
    vis[z][u][v]=1;
    
    if(u==v){
        int res=1e9,c=0;
        for(int i=0;i<n;i++)if(z&(1<<i)){
            ++c;
            for(int j=i+1;j<n;j++)if(z&(1<<j)){
                res=min(res,dfs(z-(1<<i)-(1<<j),i,j)+(g[i][j]^1));
            }
        }
        if(c==2)res=1e9;
        f[z][u][v]=res;
        return res;
    }
    
    int res=1e9;
    for(int i=0;i<n;i++)if(z&(1<<i)){
        res=min(res,dfs(z-(1<<i),0,0)+(g[u][i]^1)+(g[v][i]^1));
        res=min(res,dfs(z-(1<<i),i,v)+(g[u][i]^1));
        res=min(res,dfs(z-(1<<i),u,i)+(g[v][i]^1));
    }
    
    f[z][u][v]=res;
    return res;
}

signed main(){
    cin>>n>>m;
    for(int i=1,u,v;i<=m;i++){
        cin>>u>>v;
        --u,--v;
        g[u][v]=g[v][u]=1;
    }
    int k=dfs((1<<n)-1,0,0);
    printf("%d\n",k+m-(n-k));
    return 0;
}


