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

const int N=3.01e3;
int n,c,a[N],cnt[N],ans[N],dp[3][N][N],T,p2[N],q[N];

void solve1(){
    dp[T][0][0]=1;
    for(int i=1;i<=n;i++){
        T^=1;
        for(int x=0;x<=n/c;x++){
            for(int z=0,v,_z;z<(1<<c);z++)if(dp[T^1][x][z]){
                v=0,swap(v,dp[T^1][x][z]);
                _mod(dp[T][x][z],v);
                _z=(z|(1<<(a[i]-1)));
                if(_z==(1<<c)-1)_mod(dp[T][x+1][0],v);
                else _mod(dp[T][x][_z],v);
            }
        }
    }
    for(int x=0;x<=n/c;x++){
        for(int z=0;z<(1<<c);z++)_mod(ans[x],dp[T][x][z]);
    }
    --ans[0];
    return;
}

void solve2(){
    #define h dp[0]
    #define f dp[1]
    #define g dp[2]
    p2[0]=1;
    for(int i=1;i<N;i++)p2[i]=p2[i-1]*2%Mod,q[i]=(p2[i]-1)*inv(i>1?p2[i-1]-1:1)%Mod;
    for(int l=1;l<=n;l++){
        int r0=c,s=1;
        for(int r=l;r<=n;r++){
            if(!cnt[a[r]])--r0;
            s=s*q[++cnt[a[r]]]%Mod;
            if(!r0)f[l][r]=s;
        }
        for(int i=1;i<=c;i++)cnt[i]=0;
    }
    for(int l=1;l<=n;l++){
        int s=0;
        for(int r=l;r<=n;r++){
            g[l][r]=f[l][r]-s;
            s=(s+g[l][r])*2%Mod;
        }
    }
    h[0][0]=1;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=i-c+1;j++)if(g[j][i]){
            for(int x=1;(x-1)*c<j;x++){
                _mod(h[i][x],h[j-1][x-1]*g[j][i]);
            }
        }
        for(int x=0;x<=n;x++)_mod(ans[x],h[i][x]*(p2[n-i]-f[i+1][n]));
    }
    ans[0]=p2[n]-1-f[1][n];
    #undef h
    #undef f
    #undef g
    return;
}

signed main(){
    n=read(),c=read();
    for(int i=1;i<=n;i++)a[i]=read();
    if(c<=9)solve1();
    else solve2();
    for(int x=0;x<=n;x++){
        _mod(ans[x],Mod);
        wri(ans[x]);
    }
    pc(10);
    return 0;
}

