// Author:Zimse  Data:2023-07-
#include <bits/stdc++.h>
#define pc putchar
#define pb push_back
#define inv fpow
// #define int long long
namespace OI{const int INF=1.001e9,Mod=1000000007;int read(){int x=0
,y=1;char c=getchar();while(c<48||57<c){if(c==45)y=-1;c=getchar();}
while(47<c&&c<58)x=x*10+c-48,c=getchar();return x*y;}void wr(int x)
{if(x<0)pc(45),x=-x;if(x>=10)wr(x/10);pc(48+x%10);}void wri(int x){
wr(x),pc(32);}void _wri(int x){wr(x),pc(10);}void iF(const char*x){
freopen(x,"r",stdin);}void oF(const char*x){freopen(x,"w",stdout);}
inline int fpow(long long x,int y=Mod-2){int z=1;while(y){if(y&1)z=
x*z%Mod;x=x*x%Mod,y/=2;}return z;}inline void _max(int&x,int y){if(
x<y)x=y;}inline void _min(int&x,int y){if(y<x)x=y;}inline void _mod
(int&x,int y){(x+=y)%=Mod;}}using namespace OI;using namespace std;

const int N=1.01e2,M=1100;
int n,a[N],f[N][M*2],vis[N][M*2],g[N][N],ans;

signed main(){
    n=read();
    g[0][0]=1;
    for(int i=1;i<=n;i++){
        a[i]=read();
        for(int j=0;j<i;j++)g[i][j]=g[i-1][j];
        for(int v=-1000;v<=1000;v++)if(v!=0&&f[i-1][v+M]){
            if(v+a[i]!=0)_mod(f[i][v+M+a[i]],f[i-1][v+M]);
            else _mod(g[i][i],f[i-1][v+M]);
            _mod(f[i][v+M],f[i-1][v+M]);
        }
        if(i>1)for(int j=0;j<i;j++)if(g[i-2][j]){
            for(int v=-10;v<=10;v++)if(v&&vis[i-1][v+M]-vis[j][v+M]>0){
                if(v+a[i]!=0)_mod(f[i][v+M+a[i]],g[i-2][j]);
                else _mod(g[i][i],g[i-2][j]);
            }
        }
        for(int v=-10;v<=10;v++)vis[i][v+M]=vis[i-1][v+M];
        vis[i][a[i]+M]++;
    }
    for(int v=-1000;v<=1000;v++)_mod(ans,f[n][v+M]);
    for(int i=0;i<=n;i++)_mod(ans,g[n][i]);
    _wri(ans);
    return 0;
}



