// Author:Zimse  Data:2023-06-
#include <bits/stdc++.h>
#define pc putchar
#define pb push_back
#define inv fpow
#define int long long
namespace OI{const int INF=1.01e9,Mod=10007;int read(){int x=0
,y=1;char c=getchar();while(c<48||57<c){if(c==45)y=-1;c=getchar();}
while(47<c&&c<58)x=x*10+c-48,c=getchar();return x*y;}void wr(int x)
{if(x<0)pc(45),x=-x;if(x>=10)wr(x/10);pc(48+x%10);}void wri(int x){
wr(x),pc(32);}void _wri(int x){wr(x),pc(10);}void iF(const char*x){
freopen(x,"r",stdin);}void oF(const char*x){freopen(x,"w",stdout);}
inline int fpow(long long x,int y=Mod-2){int z=1;while(y){if(y&1)z=
x*z%Mod;x=x*x%Mod,y/=2;}return z;}inline void _max(int&x,int y){if(
x<y)x=y;}inline void _min(int&x,int y){if(y<x)x=y;}inline void _mod
(int&x,int y){(x+=y)%=Mod;}}using namespace OI;using namespace std;

const int N=256;
int n,m,f[N][N],det=1;

signed main(){
    n=read(),m=read();
    for(int i=1,x,y;i<=m;i++){
        x=read()-1,y=read()-1;
        ++f[x][x];
        --f[y][x];
    }
    for(int i=1;i<n;i++){
        int t=0;
        for(int j=i;j<n;j++)if(f[j][i]){t=j;break;}
        for(int j=1;j<n;j++)swap(f[i][j],f[t][j]);
        if(t^i)det=-det;
        for(int j=i+1;j<n;j++){
            int v=f[j][i]*inv(f[i][i])%Mod;
            for(int k=i+1;k<n;k++)_mod(f[j][k],-v*f[i][k]);
        }
    }
    for(int i=1;i<n;i++)det=det*f[i][i]%Mod;
    _mod(det,Mod);
    _wri(det);
    return 0;
}

