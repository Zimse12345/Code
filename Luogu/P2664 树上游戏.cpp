/************************
*FileName:
*Author: Zimse
*Data: 2023-02-
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
// #define M ((L+R)/2)
// #define Lid (id<<1)
// #define Rid (Lid|1)
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

const int N=1000007,M=500000;

int n,hd[N],nxt[N],to[N],col[N],ec;
int cnt[N],mn,_n,rt,vis[N],ans[N];

inline void add(int u,int v){
    nxt[++ec]=hd[u],hd[u]=ec,to[ec]=v;
}

void findrt(int u,int from){
    cnt[u]=1;
    int mx=0;
    for(int i=hd[u],v;i;i=nxt[i]){
        v=to[i];
        if(v==from||vis[v])continue;
        findrt(v,u),cnt[u]+=cnt[v];
        _max(mx,cnt[u]);
    }
    _max(mx,_n-cnt[u]);
    if(mx<mn)mn=mx,rt=u;
    return;
}

int sz[N],pre[N],d[N],cc[N],tot,vc[N],sum,Sz;
void dfs(int u,int from){
    sz[u]=1,pre[col[u]]++;
    for(int i=hd[u],v;i;i=nxt[i]){
        v=to[i];
        if(v==from||vis[v])continue;
        dfs(v,u),sz[u]+=sz[v];
    }
    pre[col[u]]--;
    if(!pre[col[u]])d[col[u]]+=sz[u];
    if(!vc[col[u]])vc[col[u]]=1,cc[++tot]=col[u];
    return;
}

void dfs2(int u,int from,int t){
    if(!pre[col[u]])sum+=Sz-d[col[u]];
    ans[u]+=sum*t;
    ++pre[col[u]];
    for(int i=hd[u],v;i;i=nxt[i]){
        v=to[i];
        if(v==from||vis[v])continue;
        dfs2(v,u,t);
    }
    --pre[col[u]];
    if(!pre[col[u]])sum-=Sz-d[col[u]];
    return;
}

void calc(int u){
    dfs(u,0),sum=0,Sz=sz[u];
    for(int i=1;i<=tot;i++)sum+=d[cc[i]];
    dfs2(u,0,1);
    for(int i=1;i<=tot;i++)vc[cc[i]]=d[cc[i]]=0;
    tot=0;
    for(int i=hd[u],v;i;i=nxt[i]){
        v=to[i];
        if(vis[v])continue;
        pre[col[u]]=1,d[col[u]]+=sz[v],vc[col[u]]=1,cc[++tot]=col[u];
        dfs(v,u),sum=0,Sz=sz[v];
        for(int j=1;j<=tot;j++)sum+=d[cc[j]];
        dfs2(v,u,-1);
        pre[col[u]]=0;
        for(int j=1;j<=tot;j++)vc[cc[j]]=d[cc[j]]=0;
        tot=0;
    }
    return;
}

void divide(int u){
    vis[u]=1;
    calc(u);
    for(int i=hd[u],v;i;i=nxt[i]){
        v=to[i];
        if(vis[v])continue;
        mn=INF,_n=cnt[v],findrt(v,0);
        divide(rt);
    }
    return;
}

signed main(){
    n=read();
    for(int i=1;i<=n;i++)col[i]=read();
    for(int i=1,u,v,c;i<n;i++)u=read(),v=read(),add(u,v),add(v,u);
    mn=INF,_n=n,findrt(1,0);
    divide(rt);
    for(int i=1;i<=n;i++)_write(ans[i]);
    return 0;
}
