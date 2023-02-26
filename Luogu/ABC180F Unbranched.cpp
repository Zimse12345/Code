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
// const int Mod=998244353;
const int Mod=1000000007;
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

const int N=1024;

int n,m,lim,a[N],b[N],f[N][N][2],fac[N],ifac[N];

inline int C(int x,int y){
    if(x<y||x<0||y<0)return 0;
    return fac[x]*ifac[y]%Mod*ifac[x-y]%Mod;
}

signed main(){
    fac[0]=ifac[0]=1;
    for(int i=1;i<N;i++)fac[i]=fac[i-1]*i%Mod,ifac[i]=inv(fac[i]);
    n=read(),m=read(),lim=read();
    a[2]=a[3]=1;
    for(int i=4;i<=n;i++)a[i]=a[i-1]*(i-1)%Mod;
    b[1]=b[2]=1;
    for(int i=3;i<=n;i++)b[i]=b[i-1]*i%Mod;
    f[0][0][0]=1;
    for(int i=1;i<=n;i++){
        for(int sz=1;sz<=min(i,lim);sz++){
            for(int e=0;e<=m;e++){
                for(int t=0;t<2;t++)if(f[i-sz][e][t]){
                    addmod(f[i][e+sz-1][t|(sz==lim?1:0)],f[i-sz][e][t]*b[sz]%Mod*C(i-1,sz-1));
                    addmod(f[i][e+sz][t|(sz==lim?1:0)],f[i-sz][e][t]*a[sz]%Mod*C(i-1,sz-1));
                }
            }
        }
    }
    _write(f[n][m][1]);
    return 0;
}
