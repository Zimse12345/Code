// Author:Zimse  Data:2023-06-
#include <bits/stdc++.h>
#define pc putchar
#define pb push_back
#define inv fpow
#define int long long
#define M ((L+R)/2)
#define Lid (id<<1)
#define Rid (Lid|1)
namespace OI{const int INF=1.01e18,Mod=998244353;int read(){int x=0
,y=1;char c=getchar();while(c<48||57<c){if(c==45)y=-1;c=getchar();}
while(47<c&&c<58)x=x*10+c-48,c=getchar();return x*y;}void wr(int x)
{if(x<0)pc(45),x=-x;if(x>=10)wr(x/10);pc(48+x%10);}void wri(int x){
wr(x),pc(32);}void _wri(int x){wr(x),pc(10);}void iF(const char*x){
freopen(x,"r",stdin);}void oF(const char*x){freopen(x,"w",stdout);}
inline int fpow(long long x,int y=Mod-2){int z=1;while(y){if(y&1)z=
x*z%Mod;x=x*x%Mod,y/=2;}return z;}inline void _max(int&x,int y){if(
x<y)x=y;}inline void _min(int&x,int y){if(y<x)x=y;}inline void _mod
(int&x,int y){(x+=y)%=Mod;}}using namespace OI;using namespace std;

const int N=1.01e6;
int n,q,dis[N],vis[N],ans[N],Mx;
int fa[N],hd[N],nxt[N],to[N],len[N],ec;
int dep[N],cnt[N],son[N],dfn[N],idfn[N],top[N],Time;
int mn[N*4],mx[N*4],mnpos[N*4],ban[N*4],tag[N*4];

struct edge{
    int l,r,w;
    edge(int l=0,int r=0,int w=0):l(l),r(r),w(w){}
};
vector<edge> g[N];

inline void add(int u,int v,int w){
    nxt[++ec]=hd[u],hd[u]=ec,to[ec]=v,len[ec]=w;
    return;
}

void dfs0(int u,int from){
    _max(Mx,dis[u]);
    fa[u]=from,dep[u]=dep[from]+1,cnt[u]=1;
    for(int i=hd[u],v;i;i=nxt[i]){
        v=to[i];
        if(v==from)continue;
        dis[v]=dis[u]+len[i];
        dfs0(v,u),cnt[u]+=cnt[v];
        if(cnt[son[u]]<cnt[v])son[u]=v;
    }
    return;
}

void dfs1(int u,int t){
    top[u]=t,dfn[u]=++Time,idfn[Time]=u;
    if(son[u])dfs1(son[u],t);
    for(int i=hd[u],v;i;i=nxt[i]){
        v=to[i];
        if(v==fa[u]||v==son[u])continue;
        dfs1(v,v);
    }
    return;
}

inline void pushdown(int id){
    if(tag[id]<INF){
        _min(tag[Lid],tag[id]),_min(tag[Rid],tag[id]);
        _min(mn[id],tag[id]),_min(mx[id],tag[id]),tag[id]=INF;
    }
    return;
}

inline void pushup(int id){
    if(!ban[Lid]&&(ban[Rid]||mn[Lid]<mn[Rid]))mn[id]=mn[Lid],mnpos[id]=mnpos[Lid];
    else mn[id]=mn[Rid],mnpos[id]=mnpos[Rid];
    ban[id]=(ban[Lid]&ban[Rid]);
    mx[id]=max(mx[Lid],mx[Rid]);
    return;
}

inline void build(int id,int L,int R){
    tag[id]=INF;
    if(L==R)mn[id]=mx[id]=dis[idfn[L]],mnpos[id]=L;
    else{
        build(Lid,L,M),build(Rid,M+1,R);
        pushup(id);
    }
    return;
}

inline void update(int id,int L,int R,int l,int r,int x){
    pushdown(id);
    if(x>=mx[id])return;
    if(l<=L&&r>=R){
        tag[id]=x,pushdown(id);
        return;
    }
    if(l<=M)update(Lid,L,M,l,r,x);
    else pushdown(Lid);
    if(r>M)update(Rid,M+1,R,l,r,x);
    else pushdown(Rid);
    pushup(id);
    return;
}

inline void Ban(int id,int L,int R,int x){
    pushdown(id);
    if(L==R)ban[id]=1;
    else{
        if(x<=M)Ban(Lid,L,M,x),pushdown(Rid);
        else Ban(Rid,M+1,R,x),pushdown(Lid);
        pushup(id);
    }
    return;
}

signed main(){
    iF("path.in");
    oF("path.out");
    
    n=read(),q=read();
    for(int i=1,u,v,w;i<n;i++){
        u=read(),v=read(),w=read();
        add(u,v,w),add(v,u,w);
    }
    dfs0(1,0),dfs1(1,1);
    for(int u=1;u<=n;u++){
        for(int i=hd[u],v;i;i=nxt[i]){
            v=to[i];
            g[dfn[u]].pb(edge(dfn[v],dfn[v],len[i]));
        }
    }
    while(q--){
        int op=read(),x=read();
        if(op==1){
            int u=read(),v=read(),w=read();
            while(top[u]!=top[v]){
                if(dep[top[u]]<dep[top[v]])swap(u,v);
                g[dfn[x]].pb(edge(dfn[top[u]],dfn[u],w));
                u=fa[top[u]];
            }
            if(dfn[v]<dfn[u])swap(u,v);
            g[dfn[x]].pb(edge(dfn[u],dfn[v],w));
        }
        else{
            int u=read(),w=read();
            g[dfn[x]].pb(edge(dfn[u],dfn[u]+cnt[u]-1,w));
        }
    }

    build(1,1,n);
    for(int i=1;i<=n;i++){
        int u=mnpos[1];
        ans[u]=mn[1];
        Ban(1,1,n,u);
        for(unsigned j=0;j<g[u].size();j++){
            update(1,1,n,g[u][j].l,g[u][j].r,ans[u]+g[u][j].w);
        }
    }
    for(int i=1;i<=n;i++)_wri(ans[dfn[i]]);
    return 0;
}

