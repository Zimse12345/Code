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

const int N=1000007,i2=499122177;

int T,L,R,f[N],g[N],sf[N],sg[N],lim[N];

int dp(int len){
    f[0]=1;
    for(int i=1;i<=len;i++){
        f[i]=g[i]=sf[i]=sg[i]=0;
        if(lim[i]!=1){
            addmod(f[i],f[i-1]+g[i-1]*i2);
            addmod(g[i],g[i-1]*i2);
            addmod(sf[i],sf[i-1]+(sg[i-1]+g[i-1])*i2);
            addmod(sg[i],(sg[i-1]+g[i-1])*i2);
        }
        if(lim[i]!=0){
            addmod(f[i],f[i-1]*i2);
            addmod(g[i],f[i-1]*i2+g[i-1]);
            addmod(sf[i],(sf[i-1]+f[i-1])*i2);
            addmod(sg[i],(sf[i-1]+f[i-1])*i2+sg[i-1]);
        }
    }
    return (sf[len]+sg[len]+g[len]*2)%Mod;
}

int sol(int x){
    int res=0;
    for(int i=0;i<=60;i++)if(x&(1ll<<i)){
        for(int j=0;j<i;j++)lim[j+1]=-1;
        lim[i+1]=0;
        for(int j=i+1;j<=60;j++){
            if(x&(1ll<<j))lim[j+1]=1;
            else lim[j+1]=0;
        }
        addmod(res,dp(64));
    }
    for(int i=0;i<=60;i++){
        if(x&(1ll<<i))lim[i+1]=1;
        else lim[i+1]=0;
    }
    addmod(res,dp(64));
    return res;
}

signed main(){
    T=read();
    while(T--){
        L=read(),R=read();
        int ans=(sol(R)-sol(L-1)+Mod*2)%Mod;
        _write(ans);
    }
    return 0;
}
