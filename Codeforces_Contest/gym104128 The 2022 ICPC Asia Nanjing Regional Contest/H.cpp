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

int n,k,hd[N],nxt[N],to[N],len[N],ec,rt[N],tot,ans;

struct node{
    int l,r,v,ky,sz,a,d;
    node(int l=0,int r=0,int v=0,int ky=0,int sz=0,int a=0,int d=0):
    l(l),r(r),v(v),ky(ky),sz(sz),a(a),d(d){}
}t[N];
void update(int id){t[id].sz=t[t[id].l].sz+t[t[id].r].sz+1;return;}

void pushdown(int id){
    int a=t[id].a,d=t[id].d;
    if(a==0&&d==0)return;
    t[id].a=0,t[id].d=0;
    int lid=t[id].l,rid=t[id].r;
    if(lid)t[lid].a+=a,t[lid].d+=d;
    t[id].v+=a+d*(t[lid].sz);
    if(rid)t[rid].a+=a+(t[lid].sz+1)*d,t[rid].d+=d;
    return;
}

void split(int id,int x,int& l,int& r){
	if(!id){l=r=0;return;}
    pushdown(id);
	if(t[id].v<=x)l=id,split(t[id].r,x,t[id].r,r);
	if(t[id].v>x)r=id,split(t[id].l,x,l,t[id].l);
	update(id);return;
}

int merge(int l,int r){
    pushdown(l),pushdown(r);
	if(!l||!r)return l+r;
	if(t[l].ky<=t[r].ky){t[l].r=merge(t[l].r,r),update(l);return l;}
	t[r].l=merge(l,t[r].l),update(r);return r;
}

inline void add(int u,int v,int w){
    nxt[++ec]=hd[u],hd[u]=ec,to[ec]=v,len[ec]=w;
    return;
}

void Merge(int& Rt,int x){
    if(!x)return;
    pushdown(x);
    Merge(Rt,t[x].l),Merge(Rt,t[x].r);
    int l,r;
    split(Rt,t[x].v,l,r);
    t[x]=node(0,0,t[x].v,rand(),1,0,0);
    Rt=merge(merge(l,x),r);
    return;
}

void dfs(int u,int from,int fw=0){
    rt[u]=++tot,t[tot]=node(0,0,0,rand(),1,0,0);
    for(int i=hd[u],v;i;i=nxt[i]){
        v=to[i];
        if(v==from)continue;
        dfs(v,u,len[i]);
        if(t[rt[v]].sz>t[rt[u]].sz)swap(rt[u],rt[v]);
        Merge(rt[u],rt[v]);
    }
    t[rt[u]].a-=(k-1)*fw,t[rt[u]].d+=(fw*2);
    return;
}

void query(int x){
    if(!x||!k)return;
    pushdown(x);
    query(t[x].l);
    if(k)ans+=t[x].v,--k;
    query(t[x].r);
    return;
}

signed main(){
	srand(time(0));
    n=read(),k=read();
    for(int i=1,u,v,w;i<n;i++){
        u=read(),v=read(),w=read();
        add(u,v,w),add(v,u,w);
    }
    dfs(1,0);
    query(rt[1]);
    _write(-ans);
    return 0;
}
