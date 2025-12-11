#include <bits/stdc++.h>
#define LOG(FMT...) fprintf(stderr, FMT)
using namespace std;
typedef long long LL;
#define int long long
const int N = 1e6 + 10,Mod=1000000007;
int read(){
    int x = 0,f = 1; char ch = getchar();
    while (ch < '0' || ch > '9') {if (ch == '-') f = -1; ch = getchar();}
    while (ch >= '0' && ch <= '9') {x = x * 10 + ch - '0'; ch = getchar();}
    return x * f;
}
int n,m,ans,fac[N],sz[N];
vector<int> g[N];

void dfs(int u,int from){
    if(!from){
        int c=0;
        for(int i=0,v;i<sz[u];i++){
            v=g[u][i];
            if(sz[v]==1)continue;
            else dfs(v,u),++c;
        }
        if(c==0)ans=ans*fac[sz[u]]%Mod;
        else if(c==1)ans=ans*fac[sz[u]-1]%Mod*2%Mod;
        else if(c==2)ans=ans*fac[sz[u]-2]%Mod*2%Mod;
        else ans=0;
        return;
    }
    int c=0;
    for(int i=0,v;i<sz[u];i++){
        v=g[u][i];
        if(v==from)continue;
        if(sz[v]==1)continue;
        else dfs(v,u),++c;
    }
    if(c==0)ans=ans*fac[sz[u]-1]%Mod;
    else if(c==1)ans=ans*fac[sz[u]-2]%Mod;
    else ans=0;
    return;
}

inline void solve() {
    cin>>n>>m;
    fac[0]=1;
    for(int i=1;i<=n;i++)fac[i]=fac[i-1]*i%Mod;
    for(int i=1;i<=n;i++)g[i].resize(0);
    for(int i=1,u,v;i<=m;i++){
        cin>>u>>v;
        g[u].push_back(v);
        g[v].push_back(u);
    }
    for(int i=1;i<=n;i++)sz[i]=g[i].size();
    if(m!=n-1){
        printf("0\n");
        return;
    }
    if(n==2){
        printf("2\n");
        return;
    }
    for(int i=1;i<=n;i++)if(sz[i]>1){
        ans=2;
        dfs(i,0);
        printf("%lld\n",ans);
        break;
    }
    return;
}
signed main() {
    int _ = 1; cin >> _;
    while (_--) solve();
    return 0;
}
