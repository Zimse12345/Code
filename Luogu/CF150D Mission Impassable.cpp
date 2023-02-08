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
#define int long long
// #define M ((L+R)/2)
// #define Lid (id<<1)
// #define Rid (Lid|1)
// #define Lid ch[id][0]
// #define Rid ch[id][1]

namespace Zimse{
const int INF=100114514;
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

const int N=160;

int T,n,v[N],vis[N][N][N],f[N][N][N],g[N];
char str[N];

int dp(int l,int r,int d){
    int& F=f[l][r][d];
    if(vis[l][r][d]++)return F;
    if(r<l){
        if(v[d]==-1)F=-INF;
        else F=v[d];
    }
    else{
        F=-INF;
        if(d&&v[d]!=-1)_max(F,dp(l,r,0)+v[d]);
        if(v[d+1]!=-1){
            for(int i=l;i<=r;i++)_max(F,dp(l,i-1,0)+dp(i+1,r,0)+v[d+1]);
        }
        if(str[l]==str[r]&&l<r)_max(F,dp(l+1,r-1,d+2));
        for(int i=l;i<r;i++)_max(F,max(dp(l,i,d)+dp(i+1,r,0),dp(l,i,0)+dp(i+1,r,d)));
    }
    return F;
}

signed main(){
    n=read();
    for(int i=1;i<=n;i++)v[i]=read();
    scanf("%s",str+1);
    for(int l=1;l<=n;l++)for(int r=l;r<=n;r++)dp(l,r,0);
    for(int i=1;i<=n;i++){
        g[i]=-INF;
        for(int j=1;j<=i;j++)_max(g[i],g[j-1]+f[j][i][0]);
        _max(g[i],g[i-1]);
    }
    _write(g[n]);
    for(int i=0;i<=n+1;i++){
        for(int j=0;j<=n+1;j++){
            for(int d=0;d<=n+2;d++)vis[i][j][d]=f[i][j][d]=0;
        }
    }
    return 0;
}
