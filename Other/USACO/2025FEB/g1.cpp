#include <bits/stdc++.h>
#define int long long
using namespace std;

const int N=1.01e6,inf=1e18;
int n,a[N],c[N],vis[N],stk[N],tp,ring[N],f[N][2],t;
vector<int> g[N];
int vis2[N],vis3[N],F[N][2],m,G[N][2],ans;

void dfs(int u,int from){
    if(a[u]!=u)f[u][0]+=c[u];
    for(unsigned i=0;i<g[u].size();i++){
        int v=g[u][i];
        if(v==from||ring[v])continue;
        dfs(v,u);
        f[u][0]+=min(f[v][0],f[v][1]);
        f[u][1]+=f[v][0];
    }
    return;
}

signed main(){
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>a[i];
        g[a[i]].push_back(i);
    }
    for(int i=1;i<=n;i++)cin>>c[i];
    for(int i=1;i<=n;i++)if(!vis[i]){
        tp=0;
        ++t;
        int x=i;
        while(!vis[x])vis[x]=t,stk[++tp]=x,x=a[x];
        if(vis[x]!=t)continue;
        for(int j=tp;j>=1;j--){
            ring[stk[j]]=1;
            if(stk[j]==x)break;
        }
    }
    for(int i=1;i<=n;i++)if(ring[i]&&!vis2[i]){
        dfs(i,0);
        vis2[i]=1;
    }
    for(int i=1;i<=n;i++)if(ring[i]&&!vis3[i]){
        int x=i;
        m=0;
        while(!vis3[x]){
            vis3[x]=1;
            ++m;
            F[m][0]=f[x][0],F[m][1]=f[x][1];
            x=a[x];
        }
        G[1][0]=F[1][0],G[1][1]=inf;
        for(int i=2;i<=m;i++){
            G[i][0]=min(G[i-1][0],G[i-1][1])+F[i][0];
            G[i][1]=G[i-1][0]+F[i][1];
        }
        int mn=min(G[m][0],G[m][1]);
        G[1][1]=F[1][1];
        for(int i=2;i<=m;i++){
            G[i][0]=min(G[i-1][0],G[i-1][1])+F[i][0];
            G[i][1]=G[i-1][0]+F[i][1];
        }
        mn=min(mn,G[m][0]);
        ans+=mn;
    }
    printf("%lld\n",ans);
    return 0;
}


