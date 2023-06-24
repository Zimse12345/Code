// Author:Zimse  Data:2023-06-
#include <bits/stdc++.h>
#define pc putchar
#define pb push_back
#define inv fpow
#define int long long
//#define M ((L+R)/2)
namespace OI{const int INF=1.001e9,Mod=998244353;int read(){int x=0
,y=1;char c=getchar();while(c<48||57<c){if(c==45)y=-1;c=getchar();}
while(47<c&&c<58)x=x*10+c-48,c=getchar();return x*y;}void wr(int x)
{if(x<0)pc(45),x=-x;if(x>=10)wr(x/10);pc(48+x%10);}void wri(int x){
wr(x),pc(32);}void _wri(int x){wr(x),pc(10);}void iF(const char*x){
freopen(x,"r",stdin);}void oF(const char*x){freopen(x,"w",stdout);}
inline int fpow(long long x,int y=Mod-2){int z=1;while(y){if(y&1)z=
x*z%Mod;x=x*x%Mod,y/=2;}return z;}inline void _max(int&x,int y){if(
x<y)x=y;}inline void _min(int&x,int y){if(y<x)x=y;}inline void _mod
(int&x,int y){(x+=y)%=Mod;}}using namespace OI;using namespace std;

const int N=1.01e6;
int n,fac[N],ifac[N],ans;

inline int C(int x,int y){
    return fac[x]*ifac[y]%Mod*ifac[x-y]%Mod;
}

signed main(){
    fac[0]=ifac[0]=1;
    for(int i=1;i<N;i++)fac[i]=fac[i-1]*i%Mod,ifac[i]=inv(fac[i]);
    n=read();
    for(int i=1,t=-1;i<=n;i++,t=-t){
        _mod(ans,t*C(n,i)*fpow(3,n*(n-i)+i)*2);
        _mod(ans,fpow(3,n*n+1)*C(n,i)%Mod*t*inv(fpow(3,-i*n))%Mod*(fpow(1-inv(fpow(3,n-i)),n)-1));
    }
    ans=(Mod-ans)%Mod;
    _wri(ans);
    return 0;
}

