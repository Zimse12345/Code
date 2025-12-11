#include <bits/stdc++.h>
using namespace std;

const int N=32000;
int n,a[N];
long long unsigned ans[N];
vector<int> g[N];
bitset<N> f[N],pf[N],lf[N],rf[N];

void dfs(int u,int from){
    if(a[u])f[u][0]=1;
    for(unsigned i=0;i<g[u].size();i++){
        int v=g[u][i];
        if(v==from)continue;
        dfs(v,u);
        f[u]|=(f[v]<<1);
    }
    return;
}

void dfs2(int u,int from){
    if(a[u])pf[u][0]=1;
    ans[u]=(f[u]|pf[u]).count();
    int sz=g[u].size();
    for(int i=0,pr=0;i<sz;i++){
        int v=g[u][i];
        if(v==from)continue;
        pf[v]=(pf[u]<<1);
        lf[v]=(lf[pr]|(f[pr]<<2));
        pr=v;
    }
    for(int i=sz-1,pr=0;i>=0;i--){
        int v=g[u][i];
        if(v==from)continue;
        rf[v]=(rf[pr]|(f[pr]<<2));
        pr=v;
        pf[v]|=(lf[v]|rf[v]);
        dfs2(v,u);
    }
    return;
}

signed main(){
    cin>>n;
    for(int i=1;i<=n;i++)cin>>a[i];
    for(int i=1,u,v;i<n;i++){
        cin>>u>>v;
        g[u].push_back(v);
        g[v].push_back(u);
    }
    dfs(1,0);
    dfs2(1,0);
    for(int i=1;i<=n;i++)printf("%llu\n",ans[i]);
    return 0;
}


