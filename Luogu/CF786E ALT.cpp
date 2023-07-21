// Author:Zimse  Data:2023-07-
#include <bits/stdc++.h>
#define pc putchar
#define pb push_back
#define inv fpow
// #define int long long
#define M ((L+R)/2)
#define Lid ch[id][0]
#define Rid ch[id][1]
namespace OI{const int INF=1.001e9,Mod=998244353;int read(){int x=0
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
struct Dinic{
    int n,s,t,hd[N],h[N],nxt[N],ec,d[N],Flow;
    struct Arc{
        int v,f;
        Arc(int v=0,int f=0):v(v),f(f){}
    }E[N];
    inline void init(){for(int i=1;i<=n;i++)hd[i]=0;ec=1,n=Flow=0;return;}
    inline void link(int u,int v,int f){nxt[++ec]=hd[u],hd[u]=ec,E[ec]=Arc(v,f);return;}
    inline void Link(int u,int v,int f){link(u,v,f),link(v,u,0);return;}

    queue<int> Q;
    bool bfs(){
        for(int i=1;i<=n;i++)d[i]=0;
        d[s]=1,Q.push(s);
        while(!Q.empty()){
            int u=Q.front();
            Q.pop();
            for(int i=hd[u];i;i=nxt[i])if(E[i].f&&!d[E[i].v])d[E[i].v]=d[u]+1,Q.push(E[i].v);
        }
        return d[t];
    }

    int dfs(int u,int maxf){
        if(u==t||!maxf)return maxf;
        int flow=0;
        for(int i=h[u];i;i=nxt[i]){
            if(d[u]+1==d[E[i].v]){
                int f=dfs(E[i].v,min(maxf,E[i].f));
                flow+=f,maxf-=f,E[i].f-=f,E[i^1].f+=f;
                if(!maxf)break;
            }
            h[u]=nxt[h[u]];
        }
        if(!flow)d[u]=0;
        return flow;
    }

    void dinic(){
        while(bfs()){
            for(int i=1;i<=n;i++)h[i]=hd[i];
            Flow+=dfs(s,INF);
        }
        return;
    }
}G;
int n,q,pos[N],tot,eid[N],ans[N],ch[N][2],nc;
int fa[N],cnt[N],dep[N],son[N],top[N],dfn[N],Time,idfn[N];
struct edge{
    int v,id;
    edge(int v=0,int id=0):v(v),id(id){};
};
vector<edge> g[N];
vector<int> hc[N];

inline void dfs0(int u,int from){
    fa[u]=from,cnt[u]=1,dep[u]=dep[from]+1;
    for(unsigned i=0;i<g[u].size();i++){
        int v=g[u][i].v;
        if(v==from)continue;
        dfs0(v,u),cnt[u]+=cnt[v];
        eid[v]=g[u][i].id;
        if(cnt[son[u]]<cnt[v])son[u]=v;
    }
    return;
}

inline void dfs1(int u,int t){
    hc[t].pb(u);
    top[u]=t,dfn[u]=++Time,idfn[Time]=u;
    if(son[u])dfs1(son[u],t);
    for(unsigned i=0;i<g[u].size();i++){
        int v=g[u][i].v;
        if(v==fa[u]||v==son[u])continue;
        dfs1(v,v);
    }
    return;
}

void build(int &id,int L,int R){
    id=++nc;
    if(L==R)G.Link(id+n,L,INF);
    else{
        build(Lid,L,M),build(Rid,M+1,R);
        G.Link(id+n,Lid+n,INF),G.Link(id+n,Rid+n,INF);
    }
    return;
}

void update(int id,int L,int R,int l,int r,int u){
    if(l<=L&&r>=R)G.Link(u,id+n,INF);
    else if(r<L||R<l)return;
    else update(Lid,L,M,l,r,u),update(Rid,M+1,R,l,r,u);
}

signed main(){
    n=read(),q=read();
    for(int i=1,u,v;i<n;i++){
        u=read(),v=read();
        g[u].pb(edge(v,i)),g[v].pb(edge(u,i));
    }
    dfs0(1,0);
    dfs1(1,1);
    G.init(),G.n=n*4,G.s=++G.n,G.t=++G.n;
    int rt=0;
    build(rt,1,n);
    for(int i=1;i<=n;i++)if(hc[i].size()){
        for(unsigned j=0;j<hc[i].size();j++){
            G.Link(hc[i][j]+n*3,dfn[hc[i][j]],INF);
            if(j)G.Link(hc[i][j]+n*3,hc[i][j-1]+n*3,INF);
        }
    }
    for(int i=2;i<=n;i++)G.Link(i,G.t,1);
    for(int i=1;i<=q;i++){
        int u=read(),v=read();
        pos[i]=++G.n,G.Link(G.s,G.n,1);
        while(top[u]^top[v]){
            if(dep[top[u]]<dep[top[v]])swap(u,v);
            G.Link(G.n,u+n*3,INF);
            u=fa[top[u]];
        }
        if(dfn[v]<dfn[u])swap(u,v);
        update(1,1,n,dfn[u]+1,dfn[v],G.n);
    }
    G.dinic();
    _wri(G.Flow);
    for(int i=1;i<=q;i++)if(!G.d[pos[i]])++tot;
    wri(tot);
    for(int i=1;i<=q;i++)if(!G.d[pos[i]])wri(i);
    pc(10);
    tot=0;
    for(int i=1;i<=n;i++)if(G.d[i])ans[++tot]=eid[idfn[i]];
    wri(tot);
    sort(ans+1,ans+tot+1);
    for(int i=1;i<=tot;i++)wri(ans[i]);
    pc(10);
    return 0;
}

