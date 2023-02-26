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
// #define int long long
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

const int N=1000007,B=1280;

int n,ans[N],p[N],s[N],Time,f[N],ff[N],fa[N];
vector<int> g[N];

inline void add(int u,int v){
    g[u].pb(v);
    return;
}

void dfs(int u,int from){
    s[++Time]=u;
    for(unsigned i=0;i<g[u].size();i++){
        int v=g[u][i];
        if(v==from)continue;
        fa[v]=u;
        dfs(v,u);
    }
    return;
}

int sol(int x){
    int cnt=0;
    for(int i=n;i>=1;i--){
        int u=s[i];
        f[u]=ff[u]=0;
        for(unsigned j=0;j<g[u].size();j++){
            int v=g[u][j];
            if(v==fa[u])continue;
            if(f[v]>f[u])ff[u]=f[u],f[u]=f[v];
            else if(f[v]>ff[u])ff[u]=f[v];
        }
        if(f[u]+ff[u]+1>=x){
            ++cnt,f[u]=-1;
        }
        ++f[u];
    }
    return cnt;
}

void solve(int L,int R,int l,int r){
    if(l==r){
        for(int i=L;i<=R;i++)ans[i]=l;
        return;
    }
    if(R<L)return;
    int M=(L+R)/2,v=sol(M);
    ans[M]=v,solve(L,M-1,v,r),solve(M+1,R,l,v);
    return;
}

signed main(){
    n=read();
    for(int i=1,u,v;i<n;i++){
        u=read(),v=read(),add(u,v),add(v,u);
    }
    dfs(1,0);
    for(int i=1;i<=min(B,n);i++)ans[i]=sol(i);
    solve(B+1,n,0,ans[B]);
    for(int i=1;i<=n;i++)_write(ans[i]);
    return 0;
}
