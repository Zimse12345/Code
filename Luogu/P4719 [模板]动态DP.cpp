/************************
*FileName:
*Author: Zimse
*Data: 2023-01-
*Description:
************************/

#include <cstdio>
#include <algorithm>
#include <cstring>
#include <vector>
#include <cmath>
#include <set>
#include <map>
#include <queue>
#include <stack>
#include <iostream>
#include <cstdlib>
#include <ctime>
#include <cctype>

#define gc getchar
#define pc putchar
#define yes _Yes()
#define no _No()
#define pb push_back
#define ll long long
#define int long long
#define M ((L+R)/2)
#define Lid (id<<1)
#define Rid (Lid|1)
// #define Lid ch[id][0]
// #define Rid ch[id][1]

namespace Zimse{
const int INF=1000000000000114514;
const int Mod=998244353;
// const int Mod=1000000007;
inline int read(){int x=0,y=1;char c=gc();while(c<48||57<c)
{if(c==45)y=-1;c=gc();}while(47<c&&c<58)x=x*10+c-48,c=gc();return x*y;}
inline void write(int x){if(x<0)pc(45),x=-x;if(x>=10)write(x/10);pc(48+x%10);return;}
inline void _Yes(){pc(89),pc(101),pc(115),pc(10);return;}
inline void _No(){pc(78),pc(111),pc(10);return;}
inline void _ck(bool x){x?yes:no;return;}
inline void write_(int x){write(x),pc(32);return;}
inline void _write(int x){write(x),pc(10);return;}
inline void ifile(const char str[]){freopen(str,"r",stdin);return;}
inline void ofile(const char str[]){freopen(str,"w",stdout);return;}
inline ll fpow(ll x,ll y){ll res=1;while(y){if(y&1)res=res*x%Mod;x=x*x%Mod,y/=2;}return res;}
inline ll inv(ll x){return fpow(x,Mod-2);}
inline int _gcd(int x,int y){return y?_gcd(y,x%y):x;}
inline int _lcm(int x,int y){return x/_gcd(x,y)*y;}
inline int _abs(int x){return x<0?-x:x;}
inline void _max(int& x,int y){if(x<y)x=y;return;}
inline void _min(int& x,int y){if(y<x)x=y;return;}
inline void addmod(int& x,int y){(x+=y)%=Mod;return;}
}using namespace Zimse;using namespace std;

const int N=1000007;

int n,m,Val[N],val[N],hd[N],nxt[N],to[N],ec;
int fa[N],sz[N],dep[N],son[N],dfn[N],fr[N],ed[N],Time;
int g[N][2];

struct mixtra{
    int v[2][2];
    void Init(){
        v[0][0]=v[0][1]=v[1][0]=v[1][1]=-INF;
        return;
    }
}t[N*4];

inline mixtra mul(mixtra x,mixtra y){
    mixtra res;
    for(int i=0;i<2;i++){
        for(int j=0;j<2;j++)res.v[i][j]=max(x.v[i][0]+y.v[0][j],x.v[i][1]+y.v[1][j]);
    }
    return res;
}

inline void add(int u,int v){
    nxt[++ec]=hd[u],hd[u]=ec,to[ec]=v;
    return;
}

void dfs0(int u,int from){
    fa[u]=from,sz[u]=1,dep[u]=dep[from]+1;
    for(int i=hd[u],v;i;i=nxt[i]){
        v=to[i];
        if(v==from)continue;
        dfs0(v,u),sz[u]+=sz[v];
        if(sz[son[u]]<sz[v])son[u]=v;
    }
    return;
}

void dfs1(int u,int t){
    dfn[u]=++Time,fr[u]=t,ed[t]=Time;
    if(son[u])dfs1(son[u],t);
    for(int i=hd[u],v;i;i=nxt[i]){
        v=to[i];
        if(v==fa[u]||v==son[u])continue;
        dfs1(v,v);
    }
    return;
}

void build(int id,int L,int R){
    if(L==R)t[id].v[1][1]=-INF;
    else build(Lid,L,M),build(Rid,M+1,R),t[id]=mul(t[Rid],t[Lid]);
    return;
}

void update(int id,int L,int R,int x,mixtra y){
    if(L==R)t[id]=y;
    else{
        if(x<=M)update(Lid,L,M,x,y);
        else update(Rid,M+1,R,x,y);
        t[id]=mul(t[Rid],t[Lid]);
    }
    return;
}

mixtra query(int id,int L,int R,int l,int r){
    if(l<=L&&r>=R)return t[id];
    if(r<=M)return query(Lid,L,M,l,r);
    if(l>M)return query(Rid,M+1,R,l,r);
    return mul(query(Rid,M+1,R,l,r),query(Lid,L,M,l,r));
}

void upt(int p,int v){
    g[p][1]+=v-Val[p],Val[p]=v;
    while(p){
        mixtra _f=query(1,1,n,dfn[fr[p]],ed[fr[p]]);
        mixtra x;
        x.v[0][0]=x.v[1][0]=g[p][0],x.v[0][1]=g[p][1],x.v[1][1]=-INF;
        update(1,1,n,dfn[p],x);
        mixtra f=query(1,1,n,dfn[fr[p]],ed[fr[p]]);
        p=fa[fr[p]];
        if(p){
            g[p][0]+=max(f.v[0][0],f.v[0][1])-max(_f.v[0][0],_f.v[0][1]);
            g[p][1]+=f.v[0][0]-_f.v[0][0];
        }
    }
    return;
}

signed main(){
    n=read(),m=read();
    for(int i=1;i<=n;i++)val[i]=read();
    for(int i=1,u,v;i<n;i++)u=read(),v=read(),add(u,v),add(v,u);
    dfs0(1,0);
    dfs1(1,1);
    build(1,1,n);
    for(int i=1;i<=n;i++)upt(i,val[i]);
    while(m--){
        int x=read(),y=read();
        upt(x,y);
        mixtra ans=query(1,1,n,1,ed[1]);
        _write(max(ans.v[0][0],ans.v[0][1]));
    }
    return 0;
}
