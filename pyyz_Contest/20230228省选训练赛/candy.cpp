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
// #define int long long
#define M ((L+R)/2)
// #define Lid (id<<1)
// #define Rid (Lid|1)

namespace Zimse{
const int INF=1000114514;
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

int n,q,hd[N],nxt[N],to[N],ec;
int fa[N][20],dep[N],ans[N],isq[N];

struct node{
    int x,y;
    node(int x=0,int y=0):x(x),y(y){}
};
vector<node> upt[N],qry[N];

struct Node{
    int l,r,sum,mn,mx;
    Node(int l=0,int r=0,int sum=0,int mn=0,int mx=0):
        l(l),r(r),sum(sum),mn(mn),mx(mx){}
}t[N];
int rt[N],tot;

inline void add(int u,int v){
    nxt[++ec]=hd[u],hd[u]=ec,to[ec]=v;
    return;
}

void dfs0(int u,int from){
    fa[u][0]=from,dep[u]=dep[from]+1;
    for(int i=hd[u],v;i;i=nxt[i]){
        v=to[i];
        if(v==from)continue;
        dfs0(v,u);
    }
    return;
}

int getlca(int u,int v){
    if(dep[u]<dep[v])swap(u,v);
    for(int i=19;i>=0;i--)if(dep[fa[u][i]]>=dep[v])u=fa[u][i];
    for(int i=19;i>=0;i--)if(fa[u][i]!=fa[v][i])u=fa[u][i],v=fa[v][i];
    return u==v?u:fa[u][0];
}

Node merge(int lid,int rid){
    return Node(lid,rid,t[lid].sum+t[rid].sum,
        min(t[lid].mn,t[lid].sum+t[rid].mn),
        max(t[lid].mx,t[lid].sum+t[rid].mx));
}

void update(int& id,int L,int R,int x,int y){
    if(!id)id=++tot;
    if(L==R){
        if(!x)t[id]=Node(0,0,0,0,INF);
        else t[id]=Node(0,0,y,min(y,0),max(y,0));
    }
    else{
        if(x<=M)update(t[id].l,L,M,x,y);
        else update(t[id].r,M+1,R,x,y);
        t[id]=merge(t[id].l,t[id].r);
    }
    return;
}

int MergeTree(int id1,int id2){
    if(!id1||!id2)return id1^id2;
    int id=++tot;
    t[id].l=MergeTree(t[id1].l,t[id2].l);
    t[id].r=MergeTree(t[id1].r,t[id2].r);
    t[id]=merge(t[id].l,t[id].r);
    return id;
}

int Find(int id,int L,int R,int r,int C){
    if(L>r||!id)return 0;
    int res=Find(t[id].r,M+1,R,r,C);
    if(res)return res;
    return Find(t[id].l,L,M,r,C);
}

int Calc(int Rt,int x,int C){
    int pos=Find(Rt,0,q,x,C);
    
}

void dfs(int u,int from){
    update(rt[u],0,q,0,0);
    for(unsigned i=0;i<upt[u].size();i++)update(rt[u],0,q,upt[u][i].x,upt[u][i].y);
    for(int i=hd[u],v;i;i=nxt[i]){
        v=to[i];
        if(v==from)continue;
        dfs(v,u),rt[u]=MergeTree(rt[u],rt[v]);
    }
    for(unsigned i=0;i<qry[u].size();i++){
        int x=qry[u][i].x,y=qry[u][i].y;
        for(int j=0;j<=10;j++)if(Calc(rt[u],x,j)==y)++ans[x];
    }
    return;
}

signed main(){
    n=read(),q=read();
    for(int i=1,u,v;i<n;i++)u=read(),v=read(),add(u,v),add(v,u);
    dfs0(1,0);
    for(int i=1;i<20;i++){
        for(int j=1;j<=n;j++)fa[j][i]=fa[fa[j][i-1]][i-1];
    }
    for(int i=1,typ,a,b,x;i<=q;i++){
        typ=read(),a=read(),b=read();
        if(typ<=2){
            x=read()*(typ==1?1:-1);
            int lca=getlca(a,b);
            upt[a].pb(node(i,x));
            upt[b].pb(node(i,x));
            upt[lca].pb(node(i,-x));
            upt[fa[lca][0]].pb(node(i,-x));
        }
        else{
            isq[i]=1;
            qry[a].pb(node(i,b));
        }
    }
    dfs(1,0);
    for(int i=1;i<=n;i++)if(isq[i])_write(ans[i]);
    return 0;
}
