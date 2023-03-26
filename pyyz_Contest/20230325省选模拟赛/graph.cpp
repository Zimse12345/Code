/********************
*FileName:
*Author: Zimse
*Data: 2023-03-
*Description:
********************/

#include <bits/stdc++.h>
#define gc getchar
#define pc putchar
#define pb push_back
#define inv fpow
#define ll long long
//#define M ((L+R)/2)
//#define Lid (id<<1)
//#define Rid (Lid|1)

namespace Zimse{
const int INF=1000114514,Mod=998244353;//1000000007
inline int read(){int x=0,y=1;char c=gc();while(c<48||57<c)
{if(c==45)y=-1;c=gc();}while(47<c&&c<58)x=x*10+c-48,c=gc();return x*y;}
inline void WRI(ll x){if(x<0)pc(45),x=-x;if(x>=10)WRI(x/10);pc(48+x%10);return;}
inline void write_(ll x){WRI(x),pc(32);return;}
inline void _write(ll x){WRI(x),pc(10);return;}
inline void ifile(const char str[]){freopen(str,"r",stdin);return;}
inline void ofile(const char str[]){freopen(str,"w",stdout);return;}
inline int fpow(int x,int y=Mod-2){int res=1;while(y)
{if(y&1)res=1ll*res*x%Mod;x=1ll*x*x%Mod,y/=2;}return res;}
inline void _max(int& x,int y){if(x<y)x=y;return;}
inline void _min(int& x,int y){if(y<x)x=y;return;}
inline void addmod(int& x,int y){(x+=y)%=Mod;return;}
}using namespace Zimse;using namespace std;

namespace qwq{
std::mt19937 eng;
void init(int Seed){eng.seed(Seed);}
int readW(){return uniform_int_distribution<int>(0,1000000000)(eng);}
}

const int N=1000007;

int k,n,vis[N],Time;
int g[N][12],Tag,fa[N];

int F(int x){
    if(fa[x]^x)fa[x]=F(fa[x]);
    return fa[x];
}

struct node{
    int x,y;
    node(int x=0,int y=0):x(x),y(y){}
    bool operator < (const node &_)const{return y<_.y;}
};

struct edge{
    int u,v,w;
    edge(int u=0,int v=0,int w=0):u(u),v(v),w(w){}
    bool operator < (const edge &_)const{return w<_.w;}
};

struct tree{
    int L,R;long long sum;
    vector<edge> e;
    inline void Make(int l,int r){
        L=l,R=r,e.resize(0),sum=0;
        for(int i=L;i<R;i++){
            for(int j=1;j<k&&i+j<=R;j++)e.pb(edge(i,i+j,g[i][j]));
        }
        vector<edge> _e;
        sort(e.begin(),e.end());
        for(int i=L;i<=R;i++)fa[i]=i;
        for(unsigned i=0;i<e.size();i++){
            int u=F(e[i].u),v=F(e[i].v);
            if(u^v)fa[v]=u,sum+=e[i].w,_e.pb(e[i]);
        }
        e=_e;
        return;
    }
}mid,tl[N],tr[N];
vector<edge> G[N];
int dfn[N],stk[N],top,dep[N],fd[N];

void dfs(int u,int from){
    dfn[u]=++Time,fa[u]=from;
    for(unsigned i=0;i<G[u].size();i++){
        if(G[u][i].v==from)continue;
        dep[G[u][i].v]=dep[u]+1,fd[G[u][i].v]=G[u][i].w;
        dfs(G[u][i].v,u);
    }
    return;
}

inline int getlca(int u,int v){
    if(dep[u]<dep[v])swap(u,v);
    while(dep[u]>dep[v])u=fa[u];
    while(u!=v)u=fa[u],v=fa[v];
    return u;
}

inline void link(vector<edge> &e,int u,int v){
    int uu=u,vv=v,mx=0;
    if(dep[u]<dep[v])swap(u,v);
    while(dep[u]>dep[v])_max(mx,fd[u]),u=fa[u];
    if(vv<uu)swap(uu,vv);
    e.pb(edge(uu,vv,mx));
    return;
}

inline tree merge(const tree& l,const tree& r){
    if(!l.L)return r;
    if(!r.L)return l;
    tree t;
    t.L=l.L,t.R=r.R,t.sum=l.sum+r.sum,++Time;
    vector<edge> e=l.e;
    vector<int> p;
    for(unsigned i=0;i<r.e.size();i++)e.pb(r.e[i]);
    for(unsigned i=0;i<e.size();i++)t.sum-=e[i].w;
    for(int i=max(l.L,l.R-k+1);i<=l.R;i++){
        for(int j=1;j<k;j++)if(i+j>l.R&&i+j<=r.R)e.pb(edge(i,i+j,g[i][j]));
    }
    sort(e.begin(),e.end());
    for(unsigned i=0;i<e.size();i++){
        if(vis[e[i].u]^Time)p.pb(e[i].u);
        if(vis[e[i].v]^Time)p.pb(e[i].v);
        vis[e[i].u]=Time,vis[e[i].v]=Time;
    }
    for(unsigned i=0;i<p.size();i++)fa[p[i]]=p[i];
    int typ=(int(p.size())>3*k?0:1);
    for(unsigned i=0;i<e.size();i++){
        int u=F(e[i].u),v=F(e[i].v);
        if(u^v){
            fa[v]=u,t.sum+=e[i].w;
            if(typ)t.e.pb(e[i]);
            else{
                G[e[i].u].pb(e[i]);
                swap(e[i].u,e[i].v);
                G[e[i].u].pb(e[i]);
            }
        }
    }
    if(typ)return t;
    dep[t.L]=0,dfs(t.L,0);
    vector<node> P;
    for(unsigned i=0;i<p.size();i++){
        if(p[i]<=t.L+k-1||p[i]>=t.R-k+1)P.pb(node(p[i],dfn[p[i]]));
        G[p[i]].resize(0);
    }
    sort(P.begin(),P.end());
    top=0,stk[++top]=P[0].x;
    for(unsigned i=1;i<P.size();i++){
        int lca=getlca(P[i].x,P[i-1].x);
        while(top>1&&dep[lca]<=dep[stk[top-1]])link(t.e,stk[top-1],stk[top]),--top;
        if(dep[lca]<dep[stk[top]])link(t.e,lca,stk[top]),stk[top]=lca;
        if(P[i].x!=stk[top])stk[++top]=P[i].x;
    }
    for(int i=1;i<top;i++)link(t.e,stk[i],stk[i+1]);
    return t;
}

inline void Remake(int L,int R){
    if(R-L+1<k)Tag=0,mid.Make(L,R),tl[L]=mid;
    else{
        Tag=1;
        int lm=(R-L+1-k)/2+L,rm=lm+k-1;
        for(int i=lm;i<=rm;i++)tl[i].L=tr[i].L=0;
        mid.Make(lm,rm);
        tl[lm]=mid;
        for(int i=lm-1;i>=L;i--){
            tree t;
            t.L=t.R=i,t.sum=0;
            tl[i]=merge(t,tl[i+1]);
        }
        for(int i=rm+1;i<=R;i++){
            tree t;
            t.L=t.R=i,t.sum=0;
            tr[i]=merge(tr[i-1],t);
        }
    }
    return;
}

signed main(){
    // ifile("graph.in");
    // ofile("graph.out");

    qwq::init(read()),k=read(),n=read();
    mid.L=mid.R=n+1;
    int L=n+1,R=L;
    for(int I=1;I<=n;I++){
        int op=read();
        if(op==1){
            tl[L++].L=0;
            if(!Tag||L>mid.L)Remake(L,R);
        }
        else if(op==2){
            tr[R--].L=0;
            if(!Tag||R<mid.R)Remake(L,R);
        }
        else if(op==3){
            --L;
            for(int i=1;i<k&&L+i<=R;i++)g[L][i]=qwq::readW();
            if(Tag){
                tree t;
                t.L=t.R=L,t.sum=0;
                tl[L]=merge(t,tl[L+1]);
            }
            else Remake(L,R);
        }
        else if(op==4){
            ++R;
            for(int i=1;i<k&&R-i>=L;i++)g[R-i][i]=qwq::readW();
            if(Tag){
                tree t;
                t.L=t.R=R,t.sum=0;
                tr[R]=merge(tr[R-1],t);
            }
            else Remake(L,R);
        }
        else _write(merge(tl[L],tr[R]).sum);
    }
    return 0;
}
