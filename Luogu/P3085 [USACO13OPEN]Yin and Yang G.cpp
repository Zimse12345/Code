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
int cnt[N],mn,_n,rt,vis[N],ans,sum;

inline void add(int u,int v,int c){
    nxt[++ec]=hd[u],hd[u]=ec,to[ec]=v,col[ec]=c;
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

int pd[N],d0[N],d1[N],maxd,T;
void dfs(int u,int from,int c0,int c1){
    _max(maxd,_abs(c0-c1));
    if(from){
        if(pd[c0-c1+M])++d1[c0-c1+M];
        else ++d0[c0-c1+M];
        if(T==1&&c0==c1&&pd[M]>1)++ans;
    }
    ++pd[c0-c1+M];
    for(int i=hd[u],v;i;i=nxt[i]){
        v=to[i];
        if(v==from||vis[v])continue;
        dfs(v,u,c0+(col[i]^1),c1+(col[i]));
    }
    --pd[c0-c1+M];
    return;
}

void calc(int u,int t,int c,int from){
    sum=0,maxd=0,T=t;
    if(t==1)dfs(u,0,0,0);
    else pd[M]=1,dfs(u,from,c^1,c),pd[M]=0;
    for(int i=0;i<=maxd;i++){
        sum+=d0[M-i]*d1[M+i]+d1[M-i]*d0[M+i];
        if(!i)sum+=d1[M]*(d1[M]-1)/2;
        else sum+=d1[M-i]*d1[M+i];
        d0[M-i]=d0[M+i]=d1[M-i]=d1[M+i]=0;
    }
    ans+=sum*t;
    return;
}

void divide(int u){
    vis[u]=1;
    calc(u,1,0,0);
    for(int i=hd[u],v;i;i=nxt[i]){
        v=to[i];
        if(vis[v])continue;
        calc(v,-1,col[i],u);
        mn=INF,_n=cnt[v],findrt(v,0);
        divide(rt);
    }
    return;
}

signed main(){
    n=read();
    for(int i=1,u,v,c;i<n;i++)u=read(),v=read(),c=read(),add(u,v,c),add(v,u,c);
    mn=INF,_n=n,findrt(1,0);
    divide(rt);
    _write(ans);
    return 0;
}
