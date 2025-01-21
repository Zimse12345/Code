#include <bits/stdc++.h>
#define int long long
using namespace std;

const int N=2100,Mod=998244353;
int n,m,a[N],stk[N],t,_t,vis[N],ring[N],f[N][N],ans=1,sum;
vector<int> g[N];

void dfs(int u,int from){
    vis[u]=1;
    for(int i=1;i<=m;i++)f[u][i]=1;
    for(unsigned i=0;i<g[u].size();i++){
        int v=g[u][i];
        if(ring[v]||v==from)continue;
        dfs(v,u);
        for(int j=1,s=0;j<=m;j++){
            (s+=f[v][j])%=Mod;
            (f[u][j]*=s)%=Mod;
        }
    }
    return;
}

signed main(){
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>a[i];
        g[a[i]].push_back(i);
    }
    for(int s=1;s<=n;s++)if(!vis[s]){
        int p=s;
        t=0;
        while(!vis[p]){
            stk[++t]=p;
            vis[p]=1;
            p=a[p];
        }
        _t=t;
        ring[p]=1;
        while(stk[_t]!=p){
            ring[stk[_t]]=1;
            --_t;
        }
        for(int i=_t;i<=t;i++){
            dfs(stk[i],0);
        }
        sum=0;
        for(int i=1;i<=m;i++){
            int mul=1;
            for(int j=_t;j<=t;j++){
                (mul*=f[stk[j]][i])%=Mod;
            }
            (sum+=mul)%=Mod;
        }
        (ans*=sum)%=Mod;
    }
    printf("%lld\n",ans);
    return 0;
}


