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

const int N=5.01e3;
int T,n,a[N],m,b[N],f[N][N];

signed main(){
    T=read();
    while(T--){
        n=read(),m=0;
        for(int i=1;i<=n;i++)a[i]=read();
        sort(a+1,a+n+1);
        for(int l=1;l<=n;){
            int r=l;
            while(r<n&&a[r+1]==a[r])++r;
            b[++m]=r-l+1;
            l=r+1;
        }
        for(int i=0;i<=n;i++)f[1][i]=INF;
        f[1][1]=1;
        for(int i=2;i<=m;i++){
            for(int j=0;j<=n;j++)f[i][j]=INF;
            for(int j=0;j<n;j++)if(f[i-1][j]<INF){
                f[i][j+1]=min(f[i-1][j]+1,f[i][j+1]);
                if(b[i]<=j)f[i][j-b[i]]=min(f[i][j-b[i]],f[i-1][j]);
            }
        }
        int ans=INF;
        for(int j=0;j<=n;j++)ans=min(ans,f[m][j]);
        _wri(ans);
    }
    return 0;
}



