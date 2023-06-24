// Author:Zimse  Data:2023-06-
#include <bits/stdc++.h>
#define pc putchar
#define pb push_back
#define inv fpow
#define int long long
//#define M ((L+R)/2)
namespace OI{const int INF=1.01e9,Mod=1000000009;int read(){int x=0
,y=1;char c=getchar();while(c<48||57<c){if(c==45)y=-1;c=getchar();}
while(47<c&&c<58)x=x*10+c-48,c=getchar();return x*y;}void wr(int x)
{if(x<0)pc(45),x=-x;if(x>=10)wr(x/10);pc(48+x%10);}void wri(int x){
wr(x),pc(32);}void _wri(int x){wr(x),pc(10);}void iF(const char*x){
freopen(x,"r",stdin);}void oF(const char*x){freopen(x,"w",stdout);}
inline int fpow(long long x,int y=Mod-2){int z=1;while(y){if(y&1)z=
x*z%Mod;x=x*x%Mod,y/=2;}return z;}inline void _max(int&x,int y){if(
x<y)x=y;}inline void _min(int&x,int y){if(y<x)x=y;}inline void _mod
(int&x,int y){(x+=y)%=Mod;}}using namespace OI;using namespace std;

const int N=2048;
int n,k,a[N],b[N],f[N][N],ans,p,C[N][N],fac[N];

signed main(){
    n=read(),k=read();
    if((n+k)&1){
        _wri(0);
        return 0;
    }
    for(int i=1;i<=n;i++)a[i]=read();
    for(int i=1;i<=n;i++)b[i]=read();
    sort(a+1,a+n+1);
    sort(b+1,b+n+1);
    C[0][0]=fac[0]=1;
    for(int i=1;i<=n;i++){
        C[i][0]=1,fac[i]=fac[i-1]*i%Mod;
        for(int j=1;j<=n;j++)C[i][j]=(C[i-1][j]+C[i-1][j-1])%Mod;
    }
    f[0][0]=1;
    for(int i=1,t=0;i<=n;i++){
        while(t<n&&b[t+1]<a[i])++t;
        for(int j=0;j<i;j++)if(f[i-1][j]){
            _mod(f[i][j],f[i-1][j]);
            _mod(f[i][j+1],f[i-1][j]*(t-j));
        }
    }
    p=(n+k)/2;
    for(int i=p,t=1;i<=n;i++,t=-t)_mod(ans,t*f[n][i]*fac[n-i]%Mod*C[i][p]);
    _mod(ans,Mod);
    _wri(ans);
    return 0;
}

