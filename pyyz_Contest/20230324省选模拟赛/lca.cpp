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
//#define int long long
//#define M ((L+R)/2)
//#define Lid (id<<1)
//#define Rid (Lid|1)

namespace Zimse{
const int INF=1000114514,Mod=998244353;//1000000007
inline int read(){int x=0,y=1;char c=gc();while(c<48||57<c)
{if(c==45)y=-1;c=gc();}while(47<c&&c<58)x=x*10+c-48,c=gc();return x*y;}
inline void WRI(int x){if(x<0)pc(45),x=-x;if(x>=10)WRI(x/10);pc(48+x%10);return;}
inline void write_(int x){WRI(x),pc(32);return;}
inline void _write(int x){WRI(x),pc(10);return;}
inline void ifile(const char str[]){freopen(str,"r",stdin);return;}
inline void ofile(const char str[]){freopen(str,"w",stdout);return;}
inline int fpow(int x,int y=Mod-2){int res=1;while(y)
{if(y&1)res=1ll*res*x%Mod;x=1ll*x*x%Mod,y/=2;}return res;}
inline void _max(int& x,int y){if(x<y)x=y;return;}
inline void _min(int& x,int y){if(y<x)x=y;return;}
inline void addmod(int& x,int y){(x+=y)%=Mod;return;}
}using namespace Zimse;using namespace std;

const int N=1000007;

int n,m,q,U[N],V[N],pos[N],len[N];
int fa[N],dep[N],cnt[N],son[N],dfn[N],top[N],Time;
int cnt1[N][4],cnt2[N][4],fac[N];
vector<int> g[N];

struct query{
    int id,t;
    query(int id=0,int t=0):id(id),t(t){}
};
vector<query> Q[N];

struct Fenwick{
    int v[N];
    inline void ub(int &x){x+=(x&(-x));return;}
    inline void db(int &x){x-=(x&(-x));return;}
    inline void add(int x,int y){for(;x<N;ub(x))v[x]+=y;return;}
    inline int sum(int x){int res=0;for(;x;db(x))res+=v[x];return res;}
}A,B,C;

void dfs(int u,int from){
    fa[u]=from,dep[u]=dep[from]+1,cnt[u]=1;
    for(unsigned i=0;i<g[u].size();i++){
        int v=g[u][i];
        if(v==from)continue;
        dfs(v,u),cnt[u]+=cnt[v];
        if(cnt[son[u]]<cnt[v])son[u]=v;
    }
    return;
}

void dfs2(int u,int t){
    dfn[u]=++Time,top[u]=t;
    if(son[u])dfs2(son[u],t);
    for(unsigned i=0;i<g[u].size();i++){
        int v=g[u][i];
        if(v==fa[u]||v==son[u])continue;
        dfs2(v,v);
    }
    return;
}

int GetLCA(int u,int v){
    while(top[u]^top[v]){
        if(dep[top[u]]<dep[top[v]])swap(u,v);
        u=fa[top[u]];
    }
    return dep[u]<dep[v]?u:v;
}

signed main(){
    fac[0]=1;
    for(int i=1;i<N;i++)fac[i]=1ll*fac[i-1]*i%Mod;
    n=read(),m=read(),q=read();
    for(int i=1,u,v;i<n;i++){
        u=read(),v=read();
        g[u].pb(v),g[v].pb(u);
    }
    dfs(1,0);
    dfs2(1,1);
    for(int i=1;i<=m;i++)U[i]=read(),V[i]=read();
    for(int i=1,l,r;i<=q;i++){
        l=read(),r=read(),pos[i]=read(),len[i]=r-l+1;
        Q[l-1].pb(query(i,-1));
        Q[r].pb(query(i,1));
    }
    for(int i=1;i<=m;i++){
        int u=U[i],v=V[i],lca=GetLCA(u,v);
        A.add(dfn[lca],1);
        B.add(dfn[lca],1),B.add(dfn[u],-1),B.add(dfn[v],-1);
        C.add(dfn[lca],-2),C.add(dfn[u],1),C.add(dfn[v],1);
        for(unsigned j=0;j<Q[i].size();j++){
            int id=Q[i][j].id,t=Q[i][j].t,p=pos[id];
            for(unsigned I=0;I<g[p].size();I++){
                int to=g[p][I];
                if(to==fa[p]){
                    cnt1[id][I]+=t*(C.sum(dfn[p]+cnt[p]-1)-C.sum(dfn[p]-1));
                    cnt2[id][I]+=t*(i+B.sum(dfn[p]+cnt[p]-1)-B.sum(dfn[p]-1));
                }
                else{
                    cnt1[id][I]+=t*(C.sum(dfn[to]+cnt[to]-1)-C.sum(dfn[to]-1));
                    cnt2[id][I]+=t*(A.sum(dfn[to]+cnt[to]-1)-A.sum(dfn[to]-1));
                }
            }
        }
    }
    for(int i=1;i<=q;i++){
        int p=pos[i],ans=0;
        for(unsigned j=0;j<g[p].size();j++){
            addmod(ans,1ll*cnt2[i][j]*inv(len[i]-cnt1[i][j])%Mod);
        }
        ans=1ll*(Mod+1-ans)*fac[len[i]]%Mod;
        _write(ans);
    }
    return 0;
}
