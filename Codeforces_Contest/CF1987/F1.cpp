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

const int N=1.01e2;
int T,n,a[N],f[N][N][N];
bool vis[N][N][N];

int dfs(int l,int r,int d){
    if(r-l<0)return 0;
    if(vis[l][r][d])return f[l][r][d];
    vis[l][r][d]=true;
    for(int i=l;i<r;i++)if(a[i]<=i&&a[i]>=i-d&&(a[i]-i+d)%2==0){
        int _d=i-a[i];
        for(int j=i+1;j<=r;j+=2)if(dfs(i+1,j-1,_d)*2==j-i-1){
            f[l][r][d]=max(f[l][r][d],dfs(j+1,r,d+(j-i+1))+(j-i+1)/2);
        }
    }
    return f[l][r][d];
}

signed main(){
    T=read();
    while(T--){
        n=read();
        for(int i=1;i<=n;i++){
            for(int j=1;j<=n;j++){
                for(int k=0;k<=n;k++)f[i][j][k]=0,vis[i][j][k]=false;
            }
        }
        for(int i=1;i<=n;i++)a[i]=read();
        _wri(dfs(1,n,0));
    }
    return 0;
}



