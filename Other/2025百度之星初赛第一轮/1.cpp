#include <bits/stdc++.h>
#define int long long
using namespace std;

const int N=1.01e6,Mod=998244353;
int T,n,a[N],f[N],h[N];
vector<int> g[N];

void dfs(int u,int from){
    int c=0,s=1;
    for(unsigned i=0;i<g[u].size();i++){
        int v=g[u][i];
        if(v==from)continue;
        dfs(v,u);
        (s*=f[v]+h[v])%=Mod;
        ++c;
    }
    if(c&1){
        h[u]=(s*a[c])%Mod;
    }
    else{
        f[u]=(s*a[c])%Mod;
        if(from)h[u]=(s*a[c-1]%Mod*c)%Mod;
    }
    return;
}

signed main(){
    a[0]=a[1]=a[2]=1;
    for(int i=3;i<N;i++){
        if(i&1)a[i]=((i-1)*a[i-2]+a[i-1])%Mod;
        else a[i]=((i-1)*a[i-2])%Mod;
    }
    cin>>T;
    while(T--){
        cin>>n;
        for(int i=1;i<=n;i++){
            g[i].resize(0);
            f[i]=h[i]=0;
        }
        for(int i=1,u,v;i<n;i++){
            cin>>u>>v;
            g[u].push_back(v);
            g[v].push_back(u);
        }
        dfs(1,0);
        int ans=(f[1]+h[1])%Mod;
        printf("%lld\n",ans);
    }
    return 0;
}


