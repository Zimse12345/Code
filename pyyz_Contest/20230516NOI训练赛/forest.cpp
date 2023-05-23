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
int T,n,fa[N],pr[20][N],dfn[N],dep[N],Time,sz[N],t[N];
long long ans;
vector<int> g1[N],g2[N];

struct line{
    int l,r,v;
    line(int l=0,int r=0,int v=0):l(l),r(r),v(v){}
};
vector<line> a[N];

void dfs(int u,int from){
    fa[u]=from,dfn[u]=++Time,sz[u]=1;
    pr[0][u]=from,dep[u]=dep[from]+1;
    for(unsigned i=0;i<g2[u].size();i++){
        int v=g2[u][i];
        if(v==from)continue;
        dfs(v,u),sz[u]+=sz[v];
    }
    return;
}

inline int getlca(int x,int y){
    if(dep[x]<dep[y])swap(x,y);
    for(int i=19;i>=0;i--)if(dep[pr[i][x]]>=dep[y])x=pr[i][x];
    if(x==y)return x;
    for(int i=19;i>=0;i--)if(pr[i][x]!=pr[i][y])x=pr[i][x],y=pr[i][y];
    return fa[x];
}

inline void addrec(int l1,int r1,int l2,int r2,int v){
    a[l1].pb(line(l2,r2,v)),a[r1+1].pb(line(l2,r2,-v));
    return;
}

inline void Addrec(int l1,int r1,int l2,int r2,int v){
    addrec(l1,r1,l2,r2,v);
    addrec(l2,r2,l1,r1,v);
    addrec(max(l1,l2),min(r1,r2),max(l1,l2),min(r1,r2),-v);
    return;
}

int ad[N],mn[N],mncnt[N],secnt[N];

void build(int id,int L,int R){
    mn[id]=ad[id]=0,mncnt[id]=R-L+1;
    if(L!=R)build(Lid,L,M),build(Rid,M+1,R);
    return;
}

inline void pushdown(int id){
    if(ad[id]!=0){
        if(Rid<N)ad[Lid]+=ad[id],ad[Rid]+=ad[id];
        mn[id]+=ad[id],ad[id]=0;
    }
    return;
}

void update(int id,int L,int R,int l,int r,int v){
    pushdown(id);
    if(r<L||R<l)return;
    if(l<=L&&r>=R)ad[id]+=v,pushdown(id);
    else{
        update(Lid,L,M,l,r,v),update(Rid,M+1,R,l,r,v);
        int x=Lid,y=Rid;
        if(mn[y]<mn[x])swap(x,y);
        mn[id]=mn[x],mncnt[id]=mncnt[x],secnt[id]=secnt[x];
        if(mn[x]==mn[y])mncnt[id]+=mncnt[y],secnt[id]+=secnt[y];
        else if(mn[x]+1==mn[y])secnt[id]+=mncnt[y];
    }
    return;
}

signed main(){
    T=read();
    while(T--){
        n=read(),ans=Time=0;
        for(int i=1,u,v;i<n;i++){
            u=read(),v=read();
            g1[u].pb(v),g1[v].pb(u);
        }
        for(int i=1,u,v;i<n;i++){
            u=read(),v=read();
            g2[u].pb(v),g2[v].pb(u);
        }
        dfs(1,0);
        for(int i=1;i<20;i++){
            for(int u=1;u<=n;u++)pr[i][u]=pr[i-1][pr[i-1][u]];
        }
        for(int u=1;u<=n;u++){
            Addrec(1,n,1,n,1);
            for(unsigned i=0;i<g2[u].size();i++){
                int x=u,y=g2[u][i];
                if(y==fa[x]){
                    Addrec(1,dfn[x]-1,1,dfn[x]-1,-1);
                    Addrec(dfn[x]+sz[x],n,dfn[x]+sz[x],n,-1);
                    Addrec(1,dfn[x]-1,dfn[x]+sz[x],n,-1);
                }
                else Addrec(dfn[y],dfn[y]+sz[y]-1,dfn[y],dfn[y]+sz[y]-1,-1);
            }
        }
        for(int u=1;u<=n;u++){
            for(unsigned i=0;i<g1[u].size();i++){
                int x=u,y=g1[u][i];
                if(y<x)continue;
                int lca=getlca(x,y);
                if(lca==y)swap(x,y);
                if(lca==x){
                    int p=y;
                    for(int j=19;j>=0;j--)if(dep[pr[j][p]]>dep[lca])p=pr[j][p];
                    Addrec(1,n,dfn[y],dfn[y]+sz[y]-1,-1);
                    Addrec(dfn[p],dfn[p]+sz[p]-1,dfn[y],dfn[y]+sz[y]-1,1);
                }
                else Addrec(dfn[x],dfn[x]+sz[x]-1,dfn[y],dfn[y]+sz[y]-1,-1);
            }
        }
        build(1,1,n);
        for(int i=1;i<=n;i++){
            for(unsigned j=0;j<a[i].size();j++){
                update(1,1,n,a[i][j].l,a[i][j].r,a[i][j].v);
            }
            if(mn[1]==0)ans+=secnt[1];
            if(mn[1]==1)ans+=mncnt[1];
            update(1,1,n,i,i,INF);
        }
        printf("%lld\n",ans);
        for(int i=1;i<=n;i++)g1[i].resize(0),g2[i].resize(0),a[i].resize(0);
    }
    return 0;
}

