#include <bits/stdc++.h>
#define int long long
using namespace std;

const int N=1.01e5,Mod=1000000007;
const unsigned B=350;
int n,c,m,a[N],id[N],col[N],t,sum[N],f[N],s[N];
vector<int> g[N];
bitset<N> G[700];

signed main(){
    cin>>n>>c;
    for(int i=1;i<=n;i++)cin>>a[i];
    cin>>m;
    for(int i=1,u,v;i<=m;i++){
        cin>>u>>v;
        g[u].push_back(v);
        if(u!=v)g[v].push_back(u);
    }
    for(int i=1;i<=c;i++)if(g[i].size()>B){
        id[i]=++t;
        col[t]=i;
        for(unsigned j=0;j<g[i].size();j++)G[t][g[i][j]]=1;
    }
    for(int i=1;i<=n;i++){
        if(i==1)f[i]=1;
        else if(g[a[i]].size()<=B){
            for(unsigned j=0;j<g[a[i]].size();j++)(f[i]+=sum[g[a[i]][j]])%=Mod;
        }
        else{
            f[i]=s[id[a[i]]];
        }
        for(int j=1;j<=t;j++)if(G[j][a[i]])(s[j]+=f[i])%=Mod;
        (sum[a[i]]+=f[i])%=Mod;
    }
    printf("%lld\n",f[n]);
    return 0;
}


