// Author: Zimse
// Data: 2023-04-

#include <bits/stdc++.h>
#define gc getchar
#define pc putchar
#define pb push_back
#define inv fpow
//#define int long long
//#define M ((L+R)/2)

namespace Zimse{const int INF=1.01e9,Mod=998244353;
int read(){int x=0,y=1;char c=gc();while(c<48||57<c){if(c==45)
y=-1;c=gc();}while(47<c&&c<58)x=x*10+c-48,c=gc();return x*y;}
void WRI(int x){if(x<0)pc(45),x=-x;if(x>=10)WRI(x/10);pc(48+x%10);}
void write_(int x){WRI(x),pc(32);}void _write(int x){WRI(x),pc(10);}
void ifile(const char *x){freopen(x,"r",stdin);}
void ofile(const char *x){freopen(x,"w",stdout);}
inline int fpow(long long x,int y=Mod-2){int z=1;while(y)
{if(y&1)z=x*z%Mod;x=x*x%Mod,y/=2;}return z;}
inline void _max(int& x,int y){if(x<y)x=y;}
inline void _min(int& x,int y){if(y<x)x=y;}
inline void addmod(int& x,int y){(x+=y)%=Mod;}
}using namespace Zimse;using namespace std;

const int N=1.01e5,Sz=512;
int n,m,q,fa[N],pos[N];
vector<int> g[N],G[N];
int dep[N],dfn[N],Time;
bool cmp_dfn(int x,int y){return dfn[x]<dfn[y];}
int vis[N],tag[N],dis[N],inpos[N],id[N],s[N];
deque<int> deq[512];

void getdis(int u,int from){
    dis[u]=dis[from]+1,inpos[u]=inpos[from];
    for(unsigned i=0;i<g[u].size();i++){
        int v=g[u][i];
        if(v==from||vis[v])continue;
        getdis(v,u);
    }
    return;
}

void update(int u,int pre=0){
    for(unsigned i=0;i<G[u].size()){
        v=G[u][i];
        if(v==pre)continue;
        update(v);
    }
    return;
}

struct Block{
    int l,r,to[N];
    void build(){
        vector<int> p;
        p.pb(1),vis[1]=tag[1]=1;
        for(int i=l;i<=r;i++)p.pb(pos[i]);
        sort(p.begin(),p.end(),cmp_dfn);
        for(unsigned i=1;i<p.size();i++){
            if(p[i]==p[i-1])continue;
            int lca=p[i];
            while(!vis[lca])vis[lca]=1,lca=fa[lca];
            tag[p[i]]=tag[lca]=1;
        }
        dis[0]=-1,vis[0]=1;
        int cnt=0;
        for(int i=1;i<=n;i++)if(vis[i]){
            inpos[0]=i,getdis(i,0);
            id[i]=++cnt,s[cnt]=i;
            int x=i;
            deq[cnt].clear();
            while(x==i||!vis[x])deq[cnt].push_front(x),x=fa[x];
            if(x)G[x].pb(i);
        }
        for(int i=l;i<=r;i++){
            int x=pos[i],pre=0;
            while(x){
                update(x,pre);
                pre=x,x=fa[x];
            }
        }
        for(int i=1;i<=cnt;i++)G[s[i]].resize(0);
        return;
    }
}B[512];
int cnt,bel[N];

void dfs(int u){
    dep[u]=dep[fa[u]]+1,dfn[u]=++Time;
    for(unsigned i=0;i<g[u].size();i++){
        int v=g[u][i];
        if(v==fa[u])continue;
        dfs(v);
    }
    return;
}

signed main(){
    n=read(),m=read(),q=read();
    for(int i=2;i<=n;i++){
        fa[i]=read();
        g[fa[i]].pb(i),g[i].pb(fa[i]);
    }
    dfs(1);
    for(int i=1;i<=m;i++)pos[i]=read();
    for(int l=1,r=0;l<=m;l=r+1){
        r=min(m,l+Sz-1),++cnt;
        B[cnt].l=l,B[cnt].r=r;
        // B[cnt].build();
        for(int i=l;i<=r;i++)bel[i]=cnt;
    }
    while(q--){
        int l=read(),r=read(),x=read();
        Block b;
        b.l=l,b.r=r,b.build();
        _write(b.to[x]);
    }
    return 0;
}

