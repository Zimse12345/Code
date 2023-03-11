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
// const int Mod=998244353;
const int Mod=1000000007;
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

const int N=2000007;

int n,m,L,fa[N],w[N],val[N],_w[N],Ans;
int f[N],g[N],_f[N],ff[N],_g[N],sumf[N],sumg[N],_sumf[N];
int hd[N],nxt[N],to[N],ec;

inline void add(int u,int v){
    nxt[++ec]=hd[u],hd[u]=ec,to[ec]=v;
    return;
}

void dfs(int u){
    f[u]=sumf[w[u]-1],_f[u]=_sumf[_w[u]-1],ff[u]=_sumf[w[u]-1];
    g[u]=-sumg[w[u]+1],_g[u]=-sumg[_w[u]+1];
    addmod(sumf[w[u]],f[u]),addmod(_sumf[_w[u]],_f[u]);
    for(int i=hd[u],v;i;i=nxt[i])dfs(to[i]);
    addmod(g[u],sumg[w[u]+1]),addmod(_g[u],sumg[_w[u]+1]);
    if(w[u]==L)g[u]=1;
    if(_w[u]==L)_g[u]=1;
    addmod(sumg[w[u]],g[u]);
    addmod(sumf[w[u]],-f[u]),addmod(_sumf[_w[u]],-_f[u]);
    return;
}

signed main(){
    n=read(),m=read(),L=read();
    for(int i=2;i<=n;i++)fa[i]=read(),add(fa[i],i);
    for(int i=1;i<=n;i++)w[i]=read();
    for(int i=1;i<=m;i++)val[i]=read();
    for(int l=1;l<=m;l+=n){
        for(int i=1;i<=n;i++){
            if(l+i-1<=m)_w[i]=val[l+i-1];
            else _w[i]=w[i];
        }
        for(int i=0;i<=L;i++)sumg[i]=0;
        sumf[0]=_sumf[0]=1;
        dfs(1);
        int ans=0;
        for(int i=1;i<=n;i++)if(w[i]==L)addmod(ans,f[i]);
        for(int i=1;i<=n;i++){
            addmod(ans,_f[i]*_g[i]-ff[i]*g[i]);
            addmod(ans,Mod);
            if(l+i-1<=m)addmod(Ans,ans*(l+i-1));
        }
        for(int i=1;i<=n;i++)w[i]=_w[i];
    }
    _write(Ans);
    return 0;
}
