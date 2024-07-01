// Author:Zimse  Data:2023-07-
#include <bits/stdc++.h>
#define pc putchar
#define pb push_back
#define inv fpow
// #define int long long
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

const int N=1.01e3;
int T,n,a[N],f[N][N],g[N];

signed main(){
    T=read();
    while(T--){
        n=read();
        for(int i=1;i<=n;i++){
            for(int j=i;j<=n;j++){
                f[i][j]=INF;
            }
        }
        for(int i=1;i<=n;i++)a[i]=read();
        for(int i=2;i<=n;i++){
            for(int j=i-1;j>=1;j-=2)if(a[j]<=j&&(a[j]-j)%2==0){
                if(f[j+1][i-1]<=j-a[j])f[j][i]=j-a[j];
                for(int k=j+1;k<i-1;k+=2)f[j][i]=min(f[j][i],max(f[j][k],f[k+1][i]-(k-j+1)));
            }
        }
        for(int i=0;i<=n;i++)g[i]=0;
        for(int i=2;i<=n;i++){
            for(int j=1;j<=n;j++)if(g[j-1]*2>=f[j][i])g[i]=max(g[i],g[j-1]+(i-j+1)/2);
            g[i]=max(g[i],g[i-1]);
        }
        _wri(g[n]);
    }
    return 0;
}



