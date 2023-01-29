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
// #define int long long
#define M ((L+R)/2)
#define Lid (id<<1)
#define Rid (Lid|1)
// #define Lid ch[id][0]
// #define Rid ch[id][1]

namespace Zimse{
const int INF=1000114514;
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

int n,a[N],b[N],hd[N],nxt[N],to[N],ec,q,val[N];
int fa[N],dep[N],cnt[N],son[N],tp[N];

struct node{
    int x,y;
    node(int x=0,int y=0):x(x),y(y){}
};
vector<node> p[N];

inline void add(int u,int v){
    nxt[++ec]=hd[u],hd[u]=ec,to[ec]=v;
    return;
}

void dfs0(int u,int from){
    fa[u]=from,dep[u]=dep[from]+1,cnt[u]=1;
    for(int i=hd[u],v;i;i=nxt[i]){
        v=to[i];
        if(v==from)continue;
        dfs0(v,u);
        cnt[u]+=cnt[v];
        if(cnt[son[u]]<cnt[v])son[u]=v;
    }
    return;
}

void dfs1(int u,int t){
    tp[u]=t;
    if(son[u])dfs1(son[u],t);
    for(int i=hd[u],v;i;i=nxt[i]){
        v=to[i];
        if(v==son[u]||v==fa[u])continue;
        dfs1(v,v);
    }
    return;
}

int getlca(int u,int v){
    while(tp[u]!=tp[v]){
        if(dep[tp[u]]<dep[tp[v]])swap(u,v);
        u=fa[tp[u]];
    }
    return dep[u]<dep[v]?u:v;
}

int getdis(int u,int v){
    if(u==v)return val[u];
    return dep[u]+dep[v]-dep[getlca(u,v)]*2+val[u]+val[v];
}

void update(int L,int R,int id,int l,int r,int x,int y){
    if(r<L||R<l)return;
    if(l<=L&&r>=R)p[id].pb(node(x,y));
    else update(L,M,Lid,l,r,x,y),update(M+1,R,Rid,l,r,x,y);
    return;
}

void solve(int L,int R,int id,int u,int v){
    for(unsigned i=0;i<p[id].size();i++){
        int x=p[id][i].x;
        val[x]=p[id][i].y;
        int A=getdis(u,v),B=getdis(u,x),C=getdis(v,x);
        if(B>=A&&B>=C)v=x;
        else if(C>=A&&C>=B)u=x;
    }
    if(L==R)_write(max((getdis(u,v)+1)/2,max(val[u],val[v])));
    else solve(L,M,Lid,u,v),solve(M+1,R,Rid,u,v);
    for(unsigned i=0;i<p[id].size();i++)val[p[id][i].x]=0;
    return;
}

signed main(){
    n=read();
    for(int i=1;i<=n;i++)a[i]=read(),b[i]=1;
    for(int i=1,u,v;i<n;i++)u=read(),v=read(),add(u,v),add(v,u);
    dfs0(1,0),dfs1(1,1);
    q=read();
    for(int i=1,x,y;i<=q;i++){
        x=read(),y=read();
        update(1,q,1,b[x],i-1,x,a[x]),a[x]=y,b[x]=i;
    }
    for(int i=1;i<=n;i++)update(1,q,1,b[i],q,i,a[i]);
    int u=1,v=1;
    for(int i=1;i<=n;i++)if(getdis(u,i)>getdis(u,v))v=i;
    for(int i=1;i<=n;i++)if(getdis(i,v)>getdis(u,v))u=i;
    solve(1,q,1,u,v);
    return 0;
}
