// Author:Zimse  Data:2023-06-
#include <bits/stdc++.h>
#define pc putchar
#define pb push_back
#define inv fpow
#define int long long
//#define M ((L+R)/2)
namespace OI{const int INF=1.01e9,Mod=1000000007;int read(){int x=0
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
int n,m,f[N],g[N],a[2][N],T,C[1000][1000];

signed main(){
    C[0][0]=1;
    for(int i=1;i<1000;i++){
        C[i][0]=1;
        for(int j=1;j<1000;j++)C[i][j]=(C[i-1][j-1]+C[i-1][j])%Mod;
    }
    n=read(),m=read();
    if(n*n<=150000000){
        f[0]=f[1]=1;
        for(int i=2;i<=n;i++)f[i]=(f[i-2]+f[i-1])%Mod;
        for(int i=1;i<=n;i++){
            g[i]=f[i]=fpow(f[i],m);
            for(int j=1;j<i;j++)_mod(g[i],-g[j]*f[i-j]);
        }
        _mod(g[n],Mod);
        _wri(g[n]);
        return 0;
    }
    a[T][0]=1;
    for(int i=1;i<=n;i++){
        T^=1;
        for(int j=0;j<=m;j++)if(a[T^1][j]){
            int v=0;
            swap(v,a[T^1][j]);
            if(i>1&&!j)continue;
            for(int k=0;k+j<=m;k++){
                _mod(a[T][m-k-j],v*C[m-j][k]);
            }
        }
    }
    _wri(a[T][0]);
    return 0;
}

