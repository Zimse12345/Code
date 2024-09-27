#include <bits/stdc++.h>
#define int long long
using namespace std;

const int N=1.01e6;
int T,n,c,a[N],f[N][2];
vector<int> g[N];

void dfs(int u,int from){
    f[u][0]=0,f[u][1]=a[u];
    for(unsigned i=0;i<g[u].size();i++){
        int v=g[u][i];
        if(v==from)continue;
        dfs(v,u);
        int f0=f[u][0]+max(f[v][0],f[v][1]);
        int f1=f[u][1]+max(f[v][0],f[v][1]-c*2);
        f[u][0]=f0,f[u][1]=f1;
    }
    return;
}

signed main(){
    cin>>T;
    while(T--){
        cin>>n>>c;
        for(int i=1;i<=n;i++){
            cin>>a[i];
            g[i].resize(0);
        }
        for(int i=1,u,v;i<n;i++){
            cin>>u>>v;
            g[u].push_back(v);
            g[v].push_back(u);
        }
        dfs(1,0);
        printf("%lld\n",max(f[1][0],f[1][1]));
    }
    return 0;
}


