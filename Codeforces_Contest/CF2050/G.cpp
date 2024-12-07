#include <bits/stdc++.h>
using namespace std;

const int N=1.01e6;
int T,n,ans,f[N];
vector<int> g[N];

void dfs(int u,int from){
    int mx=0,se=0,cnt=0;
    for(unsigned i=0;i<g[u].size();i++){
        int v=g[u][i];
        if(v==from)continue;
        ++cnt;
        dfs(v,u);
        if(f[v]>mx)se=mx,mx=f[v];
        else if(f[v]>se)se=f[v];
    }
    ans=max(ans,cnt-2+mx+se+(u==1?0:1));
    ans=max(ans,cnt-1+mx+(u==1?0:1));
    f[u]=max(mx+cnt-1,1);
    return;
}

signed main(){
    cin>>T;
    while(T--){
        cin>>n;
        for(int i=1;i<=n;i++)g[i].resize(0);
        for(int i=1,u,v;i<n;i++){
            cin>>u>>v;
            g[u].push_back(v);
            g[v].push_back(u);
        }
        ans=1;
        dfs(1,0);
        printf("%d\n",ans);
    }
    return 0;
}


