#include <bits/stdc++.h>
using namespace std;

const int N=1.01e2;
int n,m,e[N][N],ans;

signed main(){
    cin>>n>>m;
    for(int i=1,u,v;i<=m;i++){
        cin>>u>>v;
        e[u-1][v-1]=e[v-1][u-1]=1;
    }
    for(int i=0;i<(1<<n);i++){
        int t=0;
        for(int u=0;u<n;u++)if(i&(1<<u)){
            for(int v=0;v<n;v++)if(!(i&(1<<v))){
                if(e[u][v])++t;
            }
        }
        ans=max(ans,t);
    }
    printf("%d\n",m-ans);
    return 0;
}


