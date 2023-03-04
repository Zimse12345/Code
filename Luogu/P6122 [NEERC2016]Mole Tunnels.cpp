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

int n,m,c[N],pos[N],f[N],g[N],dis[N],ans;

void update(int u){
    dis[u]=INF;
    if(c[u])dis[u]=0;
    if(u*2<=n)_min(dis[u],dis[u*2]+(f[u*2]?-1:1));
    if(u*2+1<=n)_min(dis[u],dis[u*2+1]+(f[u*2+1]?-1:1));
    return;
}

void dfs(int u){
    if(u>n)return;
    dfs(u*2),dfs(u*2+1);
    update(u);
    return;
}

void dfs2(int u){
    if(c[u])--c[u];
    else if(dis[u*2]+(f[u*2]?-1:1)==dis[u]){
        dfs2(u*2);
        if(f[u*2])f[u*2]--;
        else g[u*2]++;
    }
    else{
        dfs2(u*2+1);
        if(f[u*2+1])f[u*2+1]--;
        else g[u*2+1]++;
    }
    update(u);
    return;
}

signed main(){
    n=read(),m=read();
    for(int i=1;i<=n;i++)c[i]=read();
    for(int i=1;i<=m;i++)pos[i]=read();
    dfs(1);
    for(int i=1;i<=m;i++){
        int p=pos[i],mn=dis[p],mp=p,d=0;
        while(p/2){
            d+=(g[p]?-1:1),p/=2;
            if(dis[p]+d<mn)mn=dis[p]+d,mp=p;
        }
        ans+=mn;
        p=pos[i];
        while(p!=mp){
            if(g[p])--g[p];
            else ++f[p];
            p/=2,update(p);
        }
        dfs2(mp);
        while(mp/2)mp/=2,update(mp);
        write_(ans);
    }
    pc(10);
    return 0;
}
