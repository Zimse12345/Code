#include <bits/stdc++.h>
using namespace std;

const int N=1.01e6;
int n,m,U[N],V[N],W[N],vis[N],col[N],t,id[N],cnt[N],fa[N],C[2];
long long ans;
vector<int> g[N];

bool dfs(int u){
    vis[u]=1;
    id[u]=t,cnt[t]++;
    for(unsigned i=0;i<g[u].size();i++){
        int v=g[u][i];
        if(!vis[v])dfs(v);
    }
    return true;
}

bool dfs2(int u,int c){
    vis[u]=1,col[u]=c;
    C[c]+=cnt[u];
    for(unsigned i=0;i<g[u].size();i++){
        int v=g[u][i];
        if(vis[v]){
            if(col[u]==col[v])return false;
        }
        else{
            if(!dfs2(v,c^1))return false;
        }
    }
    return true;
}

inline int Find(int x){
    if(fa[x]!=x)fa[x]=Find(fa[x]);
    return fa[x];
}

signed main(){
    cin>>n>>m;
    for(int i=1;i<=m;i++){
        cin>>U[i]>>V[i]>>W[i]; 
    }
    for(int k=0;k<30;k++){
        for(int i=1;i<=n;i++){
            g[i].resize(0);
            vis[i]=cnt[i]=0;
            fa[i]=i;
        }
        for(int i=1;i<=m;i++)if(!(W[i]&(1<<k))){
            g[U[i]].push_back(V[i]);
            g[V[i]].push_back(U[i]);
        }
        t=0;
        for(int i=1;i<=n;i++)if(!vis[i]){
            ++t;
            dfs(i);
        }
        for(int i=1;i<=t;i++)g[i].resize(0),vis[i]=0;
        for(int i=1;i<=m;i++)if(W[i]&(1<<k)){
            int u=id[U[i]],v=id[V[i]];
            g[u].push_back(v);
            g[v].push_back(u);
        }
        for(int i=1;i<=t;i++)if(!vis[i]){
            C[0]=C[1]=0;
            if(!dfs2(i,0)){
                printf("-1\n");
                return 0;
            }
            ans+=1ll*(1<<k)*min(C[0],C[1]);
        }
    }
    printf("%lld\n",ans);
    return 0;
}


