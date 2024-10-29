#include <bits/stdc++.h>
#define int long long
using namespace std;

const int N=1.01e4,inf=1e18;
int T,n,_n,m,p,s[N],tag[N],f[N],id[N],cnt[N],W[N];
int G[N];
vector<int> F[N];
vector<int> g[N];

struct edge{
    int u,v,w;
    edge(int u=0,int v=0,int w=0):u(u),v(v),w(w){}
    bool operator < (const edge& _)const{return w<_.w;}
}e[N];

inline int Find(int x){
    if(f[x]!=x)f[x]=Find(f[x]);
    return f[x];
}

void dfs(int u){
    F[u].resize(2);
    cnt[u]=0,F[u][0]=0;
    if(tag[u])++cnt[u],F[u][0]=inf,F[u][1]=0; 
    for(unsigned i=0;i<g[u].size();i++){
        int v=g[u][i];
        dfs(v);
        for(int x=0;x<=cnt[u]+cnt[v];x++)G[x]=inf;
        for(int x=0;x<=cnt[u];x++){
            for(int y=0;y<=cnt[v];y++){
                int sum=0;
                if(x==0)sum+=cnt[u]*W[u];
                else sum+=F[u][x];
                if(y==0)sum+=cnt[v]*W[u];
                else sum+=F[v][y];
                G[x+y]=min(G[x+y],sum);
            }
        }
        cnt[u]+=cnt[v];
        F[u].resize(cnt[u]+1);
        for(int x=0;x<=cnt[u];x++)F[u][x]=G[x];
    }
    return;
}

signed main(){
    cin>>T;
    while(T--){
        cin>>n>>m>>p;
        _n=n;
        for(int i=1;i<=n;i++){
            tag[i]=0;
            f[i]=i;
            id[i]=i;
        }
        for(int i=1;i<=p;i++){
            cin>>s[i];
            tag[s[i]]=1;
        }
        for(int i=1;i<=m;i++){
            cin>>e[i].u>>e[i].v>>e[i].w;
        }
        sort(e+1,e+m+1);
        for(int i=1;i<=m;i++){
            int u=Find(e[i].u),v=Find(e[i].v);
            if(u!=v){
                f[v]=u;
                ++_n;
                g[_n].push_back(id[u]);
                g[_n].push_back(id[v]);
                W[_n]=e[i].w;
                id[u]=_n;
            }
        }
        dfs(_n);
        for(int i=1;i<=n;i++){
            if(i>p)printf("0 ");
            else printf("%lld ",F[_n][i]);
        }
        printf("\n");
        for(int i=1;i<=_n;i++)g[i].resize(0),tag[i]=0;
    }
    return 0;
}


