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

const int N=1000007;

int n,f[N],g[N],h[N],ans;

signed main(){
    n=read();
    for(int i=0;i<1000000;i++)f[i]=1;
    for(int i=1,x;i<=n;i++){
        x=read();
        h[x]=(h[x]*2+f[x]*x*x+2*g[x]*x)%Mod;
        g[x]=(f[x]*x+2*g[x])%Mod;
        f[x]=f[x]*2%Mod;
    }
    for(int i=1;i<=100000;i*=10){
        for(int j=999999;j>=0;j--){
            if((j/i)%10==9)continue;
            h[j]=(h[j]*f[j+i]+f[j]*h[j+i]+2*g[j]*g[j+i])%Mod;
            g[j]=(f[j]*g[j+i]+f[j+i]*g[j])%Mod;
            f[j]=f[j]*f[j+i]%Mod;
        }
    }
    for(int i=1;i<=100000;i*=10){
        for(int j=0;j<1000000;j++){
            if((j/i)%10==9)continue;
            addmod(h[j],Mod-h[j+i]);
        }
    }
    for(int j=0;j<1000000;j++)ans^=(h[j]*j);
    _write(ans);
    return 0;
}
