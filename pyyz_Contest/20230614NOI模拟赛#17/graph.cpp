// Author:Zimse  Data:2023-06-
#include <bits/stdc++.h>
#define pc putchar
#define pb push_back
#define inv fpow
#define int long long
//#define M ((L+R)/2)
int Mod;
namespace OI{const int INF=1.001e9;int read(){int x=0
,y=1;char c=getchar();while(c<48||57<c){if(c==45)y=-1;c=getchar();}
while(47<c&&c<58)x=x*10+c-48,c=getchar();return x*y;}void wr(int x)
{if(x<0)pc(45),x=-x;if(x>=10)wr(x/10);pc(48+x%10);}void wri(int x){
wr(x),pc(32);}void _wri(int x){wr(x),pc(10);}void iF(const char*x){
freopen(x,"r",stdin);}void oF(const char*x){freopen(x,"w",stdout);}
inline int fpow(long long x,int y=Mod-2){int z=1;while(y){if(y&1)z=
x*z%Mod;x=x*x%Mod,y/=2;}return z;}inline void _max(int&x,int y){if(
x<y)x=y;}inline void _min(int&x,int y){if(y<x)x=y;}inline void _mod
(int&x,int y){(x+=y)%=Mod;}}using namespace OI;using namespace std;

const int N=1.01e7;
int n,m,fac[N],g[N];

inline int C(int x,int y){
    int res=1;
    for(int i=x;i>=x-y+1;i--)res=res*(i%Mod)%Mod;
    res=res*inv(fac[y])%Mod;
    return res;
}

signed main(){
    iF("graph.in");
    oF("graph.out");

    n=read(),m=read(),Mod=read();
    fac[0]=1;
    for(int i=1;i<N;i++)fac[i]=fac[i-1]*i%Mod;
    _wri(fac[n]*C(n*(n-1)/2,m)%Mod);
    return 0;
}

