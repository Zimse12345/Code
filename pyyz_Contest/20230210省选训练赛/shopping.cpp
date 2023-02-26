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

const int N=10000007;

int n,m,k,w[N/10],f[N/10],g[N/10],sum,ans,fac[N],ifac[N];

int C(int x,int y){
    if(y<0||x<y)return 0;
    return fac[x]*ifac[y]%Mod*ifac[x-y]%Mod;
}

signed main(){
    n=read(),m=read(),k=read();
    f[0]=1;
    for(int i=1;i<=m;i++){
        w[i]=read();
        for(int j=0;j<=sum;j++)addmod(g[j],f[j]),addmod(g[j+w[i]+1],-f[j]);
        for(int j=0,s=0;j<=sum+w[i];j++){
            s+=g[j],g[j]=0;
            f[j]=s%Mod;
        }
        sum+=w[i],g[sum+1]=0;
    }
    fac[0]=1;
    for(int i=1;i<N;i++)fac[i]=fac[i-1]*i%Mod;
    ifac[N-1]=inv(fac[N-1]);
    for(int i=N-2;i>=0;i--)ifac[i]=ifac[i+1]*(i+1)%Mod;
    for(int i=0;i<=sum;i++)addmod(ans,f[i]*C(k-i+n-m-1,n-m-1));
    if(n==m)ans=f[k];
    addmod(ans,Mod);
    //printf("(i=%lld f=%lld C=%lld)\n",i,f[i],C(k-i+n-m-1,n-m-1));
    _write(ans);
    return 0;
}
