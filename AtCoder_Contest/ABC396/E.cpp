#include <bits/stdc++.h>
using namespace std;

const int N=1.01e6;
int n,m,x[N],y[N],z[N];
int fa[N],cnt[N],vis[N],c[N],s[2],tag;
int id[N],tot,val[N],p[N];
vector<int> g[N];

inline int F(int x){
    if(fa[x]!=x)fa[x]=F(fa[x]);
    return fa[x];
}

void dfs(int u,int col){
    id[++tot]=u;
    vis[u]=1,c[u]=col;
    s[col]+=cnt[u];
    for(unsigned i=0;i<g[u].size();i++){
        int v=g[u][i];
        if(vis[v]){
            if(c[u]==c[v]){
                tag=1;
                return;
            }
        }
        else dfs(v,col^1);
    }
    return;
}

signed main(){
    cin>>n>>m;
    for(int i=1;i<=m;i++)cin>>x[i]>>y[i]>>z[i];
    for(int i=0;i<30;i++){
        for(int j=1;j<=n;j++){
            fa[j]=j,cnt[j]=1;
            g[j].resize(0);
            vis[j]=0,p[j]=0;
        }
        for(int j=1;j<=m;j++){
            if(!(z[j]&(1<<i))){
                int u=F(x[j]),v=F(y[j]);
                if(u!=v)fa[v]=u,cnt[u]+=cnt[v];
            }
        }
        for(int j=1;j<=m;j++){
            if(z[j]&(1<<i)){
                int u=F(x[j]),v=F(y[j]);
                if(u==v){
                    printf("-1\n");
                    return 0;
                }
                g[u].push_back(v);
                g[v].push_back(u);
            }
        }
        for(int j=1;j<=n;j++)if(F(j)==j&&!vis[j]){
            s[0]=s[1]=0,tot=0;
            dfs(j,0);
            if(tag){
                printf("-1\n");
                return 0;
            }
            int col=(s[0]<s[1]?0:1);
            for(int k=1;k<=tot;k++)if(c[id[k]]==col)p[id[k]]=1;
        }
        for(int j=1;j<=n;j++)if(p[F(j)])val[j]+=(1<<i);
    }
    for(int i=1;i<=n;i++)printf("%d ",val[i]);
    return 0;
}


