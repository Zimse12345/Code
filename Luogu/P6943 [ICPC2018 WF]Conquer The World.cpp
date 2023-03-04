/************************
*FileName:
*Author: Zimse
*Data: 2023-02-
*Description:
************************/

#include <algorithm>
#include <cctype>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <ctime>
#include <iostream>
#include <map>
#include <queue>
#include <set>
#include <stack>
#include <vector>

#define gc getchar
#define pc putchar
#define yes printf("Yes\n")
#define no printf("No\n")
#define pb push_back
#define ll long long
#define int long long
// #define M ((L+R)/2)
// #define Lid (id<<1)
// #define Rid (Lid|1)

namespace Zimse{
const int INF=1000000000000;
const int Mod=998244353;
// const int Mod=1000000007;
inline int read(){int x=0,y=1;char c=gc();while(c<48||57<c)
{if(c==45)y=-1;c=gc();}while(47<c&&c<58)x=x*10+c-48,c=gc();return x*y;}
inline void write(int x){if(x<0)pc(45),x=-x;if(x>=10)write(x/10);pc(48+x%10);return;}
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

int n,hd[N],nxt[N],to[N],len[N],ec,d[N];
int dep[N],rt1[N],rt2[N],ans,tot;

struct node{
    signed l,r;int v;signed d;
    node(signed l=0,signed r=0,int v=0,signed d=0):l(l),r(r),v(v),d(d){}
}p[N*24];

inline void add(int u,int v,int w){
    nxt[++ec]=hd[u],hd[u]=ec,to[ec]=v,len[ec]=w;
    return;
}

int merge(int x,int y){
    if(!x||!y)return x|y;
    if(p[y].v<p[x].v)swap(x,y);
    p[x].r=merge(p[x].r,y);
    if(p[p[x].l].d<p[p[x].r].d)swap(p[x].l,p[x].r);
    p[x].d=p[p[x].l].d+1;
    return x;
}

void Ins(int& Rt,int x){
    p[++tot]=node(0,0,x,1);
    Rt=merge(Rt,tot);
    return;
}

void Pop(int& Rt){
    Rt=merge(p[Rt].l,p[Rt].r);
    return;
}

void dfs(int u,int from){
    while(d[u]>0)Ins(rt1[u],dep[u]),--d[u];
    while(d[u]<0)Ins(rt2[u],dep[u]-INF),ans+=INF,++d[u];
    for(int i=hd[u],v;i;i=nxt[i]){
        v=to[i];
        if(v==from)continue;
        dep[v]=dep[u]+len[i];
        dfs(v,u);
        rt1[u]=merge(rt1[u],rt1[v]),rt2[u]=merge(rt2[u],rt2[v]);
    }
    while(rt1[u]&&rt2[u]&&p[rt1[u]].v+p[rt2[u]].v-dep[u]*2<0){
        int x=p[rt1[u]].v,y=p[rt2[u]].v;
        ans+=x+y-dep[u]*2;
        Pop(rt1[u]),Pop(rt2[u]),Ins(rt1[u],dep[u]*2-y),Ins(rt2[u],dep[u]*2-x);
    }
    return;
}

signed main(){
    n=read();
    for(int i=1,u,v,w;i<n;i++){
        u=read(),v=read(),w=read();
        add(u,v,w),add(v,u,w);
    }
    for(int i=1,x,y;i<=n;i++){
        x=read(),y=read();
        d[i]=x-y;
    }
    dfs(1,0);
    _write(ans);
    return 0;
}
