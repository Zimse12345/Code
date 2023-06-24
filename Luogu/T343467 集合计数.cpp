// Author:Zimse  Data:2023-06-
#include <bits/stdc++.h>
#define pc putchar
#define pb push_back
#define inv fpow
#define int long long
//#define M ((L+R)/2)
namespace OI{const int INF=1.001e9,Mod=1000000007;int read(){int x=0
,y=1;char c=getchar();while(c<48||57<c){if(c==45)y=-1;c=getchar();}
while(47<c&&c<58)x=x*10+c-48,c=getchar();return x*y;}void wr(int x)
{if(x<0)pc(45),x=-x;if(x>=10)wr(x/10);pc(48+x%10);}void wri(int x){
wr(x),pc(32);}void _wri(int x){wr(x),pc(10);}void iF(const char*x){
freopen(x,"r",stdin);}void oF(const char*x){freopen(x,"w",stdout);}
inline int fpow(long long x,int y=Mod-2,int mod=Mod){int z=1;while(y){if(y&1)z=
x*z%mod;x=x*x%mod,y/=2;}return z;}inline void _max(int&x,int y){if(
x<y)x=y;}inline void _min(int&x,int y){if(y<x)x=y;}inline void _mod
(int&x,int y){(x+=y)%=Mod;}}using namespace OI;using namespace std;

const int N=1.01e6;
int n,k,fac[N],ifac[N],ans;

inline int C(int x,int y){
    return fac[x]*ifac[y]%Mod*ifac[x-y]%Mod;
}

signed main(){
    fac[0]=ifac[0]=1;
    for(int i=1;i<N;i++)fac[i]=fac[i-1]*i%Mod,ifac[i]=inv(fac[i]);
    n=read(),k=read();
    for(int i=k,t=1;i<=n;i++,t=-t){
        _mod(ans,t*C(i,k)*C(n,i)%Mod*(fpow(2,fpow(2,n-i,Mod-1))-1));
    }
    _mod(ans,Mod),_wri(ans);
    return 0;
}

