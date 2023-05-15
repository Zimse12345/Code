// Author: Zimse
// Data: 2023-05-

#include <bits/stdc++.h>
#define gc getchar
#define pc putchar
#define pb push_back
#define inv fpow
//#define int long long
#define M ((L+R)/2)
#define Lid (id<<1)
#define Rid (Lid|1)

namespace Zimse{const int INF=1.01e9,Mod=998244353;
int read(){int x=0,y=1;char c=gc();while(c<48||57<c){if(c==45)
y=-1;c=gc();}while(47<c&&c<58)x=x*10+c-48,c=gc();return x*y;}
void WRI(int x){if(x<0)pc(45),x=-x;if(x>=10)WRI(x/10);pc(48+x%10);}
void write_(int x){WRI(x),pc(32);}void _write(int x){WRI(x),pc(10);}
void ifile(const char *x){freopen(x,"r",stdin);}
void ofile(const char *x){freopen(x,"w",stdout);}
inline int fpow(long long x,int y=Mod-2){int z=1;
while(y){if(y&1)z=x*z%Mod;x=x*x%Mod,y/=2;}return z;}
inline void _max(int &x,int y){if(x<y)x=y;}
inline void _min(int &x,int y){if(y<x)x=y;}
inline void addmod(int &x,int y){(x+=y)%=Mod;}
}using namespace Zimse;using namespace std;

const int N=1.01e6;
int T,n,fa[N],fb[N],vis[N],ans,mx,pa[N];
int cnt[N],dep[N],dfn[N],son[N],top[N],Time,sum[N*4],_dfn[N];
vector<int> g[N],G[N];

void dfs0(int u){
    dep[u]=dep[fa[u]]+1,cnt[u]=1,son[u]=0;
    for(unsigned i=0;i<g[u].size();i++){
        int v=g[u][i];
        dfs0(v);
        if(cnt[son[u]]<cnt[v])son[u]=v;
        cnt[u]+=cnt[v];
    }
    return;
}

void dfs1(int u,int t){
    dfn[u]=++Time,top[u]=t,_dfn[Time]=u;
    if(son[u])dfs1(son[u],t);
    for(unsigned i=0;i<g[u].size();i++){
        int v=g[u][i];
        if(v==son[u])continue;
        dfs1(v,v);
    }
    return;
}

void update(int id,int L,int R,int x,int y){
    sum[id]+=y;
    if(L!=R){
        if(x<=M)update(Lid,L,M,x,y);
        else update(Rid,M+1,R,x,y);
    }
    return;
}

int query(int id,int L,int R,int l,int r){
    if(r<L||R<l)return 0;
    if(l<=L&&r>=R)return sum[id];
    return query(Lid,L,M,l,r)+query(Rid,M+1,R,l,r);
}

void dfs(int u){
    /*
    int pr=0,cur=fa[u];
    while(cur){
        int cur2=u;
        while(cur2&&cur2!=cur)cur2=fb[cur2];
        if(cur2==cur){
            pr=cur;
            break;
        }
        cur=fa[cur];
    }
    */
    int pr=pa[u];
    if(!vis[pr]){
        vis[u]=1,++ans,_max(mx,ans);
        for(unsigned i=0;i<g[u].size();i++)dfs(g[u][i]);
        vis[u]=0,--ans;
    }
    else{
        swap(vis[u],vis[pr]);
        for(unsigned i=0;i<g[u].size();i++)dfs(g[u][i]);
        swap(vis[u],vis[pr]);
    }
    return;
}

void Dfs(int u){
    int cur=fa[u];
    pa[u]=0;
    while(cur){
        if(query(1,1,n,dfn[top[cur]],dfn[cur])){
            int L=dfn[top[cur]],R=dfn[cur];
            while(L<=R){
                if(query(1,1,n,M,dfn[cur]))pa[u]=_dfn[M],L=M+1;
                else R=M-1;
            }
            break;
        }
        cur=fa[top[cur]];
    }
    /*
    pa[u]=0;
    while(cur){
        if(query(1,1,n,dfn[cur],dfn[cur])){
            pa[u]=cur;
            break;
        }
        cur=fa[cur];
    }
    */
    update(1,1,n,dfn[u],1);
    for(unsigned i=0;i<G[u].size();i++)Dfs(G[u][i]);
    update(1,1,n,dfn[u],-1);
    return;
}

signed main(){
    T=read();
    while(T--){
        n=read(),mx=Time=0;
        for(int i=2;i<=n;i++)fa[i]=read(),g[fa[i]].pb(i);
        for(int i=2;i<=n;i++)fb[i]=read(),G[fb[i]].pb(i);
        dfs0(1);
        dfs1(1,1);
        Dfs(1);
        dfs(1);
        _write(mx);
        for(int i=1;i<=n;i++)g[i].resize(0),G[i].resize(0);
    }
    return 0;
}

