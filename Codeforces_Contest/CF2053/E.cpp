#include <bits/stdc++.h>
using namespace std;

const int N=1.01e6;
int T,n,lf[N],nf[N],t[N],ct[N],x,y,z;
long long ans;
vector<int> g[N];

void dfs(int u,int from){
    ct[u]=t[u];
    for(unsigned i=0;i<g[u].size();i++){
        int v=g[u][i];
        if(v==from)continue;
        dfs(v,u);
        ct[u]+=ct[v];
    }
    if(nf[u]){
        if(from!=0&&!lf[from]){
            ans+=ct[u]-t[u];
        }
        for(unsigned i=0;i<g[u].size();i++){
            int v=g[u][i];
            if(v==from||lf[v])continue;
            ans+=z-ct[v]-t[u];
        }
    }
    return;
}

signed main(){
    cin>>T;
    while(T--){
        cin>>n;
        for(int i=1;i<=n;i++){
            g[i].resize(0);
            lf[i]=nf[i]=t[i]=0;
        }
        for(int i=1,u,v;i<n;i++){
            cin>>u>>v;
            g[u].push_back(v);
            g[v].push_back(u);
        }
        x=0,y=0,z=0;
        for(int i=1;i<=n;i++){
            if(g[i].size()==1)lf[i]=1,++x;
        }
        for(int i=1;i<=n;i++){
            if(!lf[i]){
                for(unsigned j=0;j<g[i].size();j++){
                    nf[i]|=lf[g[i][j]];
                }
                y+=nf[i];
            }
        }
        for(int i=1;i<=n;i++)if(lf[i]+nf[i]==0){
            t[i]=1,++z;
        }
        ans=1ll*x*(n-x);
        dfs(1,0);
        printf("%lld\n",ans);
    }
    return 0;
}


