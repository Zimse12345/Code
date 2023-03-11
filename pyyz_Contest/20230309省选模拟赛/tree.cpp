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
// #define M ((L+R)/2)
// #define Lid (id<<1)
// #define Rid (Lid|1)

namespace Zimse{
const int INF=1000114514;
const int Mod=998244353;
// const int Mod=1000000007;
inline int read(){int x=0,y=1;char c=gc();while(c<48||57<c)
{if(c==45)y=-1;c=gc();}while(47<c&&c<58)x=x*10+c-48,c=gc();return x*y;}
inline void write(ll x){if(x<0)pc(45),x=-x;if(x>=10)write(x/10);pc(48+x%10);return;}
inline void _ck(bool x){x?yes:no;return;}
inline void write_(int x){write(x),pc(32);return;}
inline void _write(ll x){write(x),pc(10);return;}
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

const int N=200007;

int n,K,hd[N],nxt[N*2],to[N*2],len[N*2],ec,rt[N],tot;
ll dep[N];

struct node{
    int l,r;ll v;short d;
    node(int l=0,int r=0,ll v=0,short d=0):l(l),r(r),v(v),d(d){}
}t[N*64];

struct sta{
    int x,y;ll val;
    sta(int x=0,int y=0,ll val=0):x(x),y(y),val(val){}
    bool operator < (const sta& _)const{return val<_.val;}
};
priority_queue<sta> Q;
map<pair<int,int>,bool> mp;

inline void add(int u,int v,int w){
    nxt[++ec]=hd[u],hd[u]=ec,to[ec]=v,len[ec]=w;
    return;
}

int merge(int x,int y){
    if(!x||!y)return x|y;
    if(t[x].v<t[y].v)swap(x,y);
    int p=++tot;
    t[p]=t[x],t[p].r=merge(t[p].r,y);
    if(t[t[p].l].d<t[t[p].r].d)swap(t[p].l,t[p].r);
    t[p].d=t[t[p].l].d+1;
    return p;
}

void dfs(int u,int from){
    t[++tot]=node(0,0,dep[u],1),rt[u]=tot;
    for(int i=hd[u],v;i;i=nxt[i]){
        v=to[i];
        if(v==from)continue;
        dep[v]=dep[u]+len[i];
        dfs(v,u);
        Q.push(sta(rt[u],rt[v],t[rt[u]].v+t[rt[v]].v-2*dep[u]));
        rt[u]=merge(rt[u],rt[v]);
    }
    return;
}

signed main(){
//	ifile("tree.in");
//	ofile("tree.out");
	
    n=read(),K=read();
    for(int i=1,u,v,w;i<n;i++){
        u=read(),v=read(),w=read();
        add(u,v,w),add(v,u,w);
    }
    dfs(1,0);
    while(K){
        sta p=Q.top();
        Q.pop();
        if(mp[make_pair(p.x,p.y)])continue;
        mp[make_pair(p.x,p.y)]=true;
        _write(p.val),--K;
        int x=p.x,y=p.y;ll d=p.val-t[x].v-t[y].v;
        if(t[x].l)Q.push(sta(t[x].l,y,t[t[x].l].v+t[y].v+d));
        if(t[x].r)Q.push(sta(t[x].r,y,t[t[x].r].v+t[y].v+d));
        if(t[y].l)Q.push(sta(x,t[y].l,t[x].v+t[t[y].l].v+d));
        if(t[y].r)Q.push(sta(x,t[y].r,t[x].v+t[t[y].r].v+d));
    }
    return 0;
}
