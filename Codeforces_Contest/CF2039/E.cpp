// Author:Zimse  Data:2024-11-
#include <bits/stdc++.h>
#define pc putchar
#define pb push_back
#define inv fpow
 #define int long long
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
int T,n,f[N][3],s[N],sf[N];

signed main(){
    cin>>T;
    for(int i=2;i<N;i++)f[i][0]=1;
    f[3][1]=1;
    for(int i=4;i<N;i++){
        f[i][1]=i-2;
        f[i][2]=(i*(i-3)/2)%Mod;
        (f[i][2]+=s[i-1])%=Mod;
        s[i]=(s[i-1]+f[i][2]*i)%Mod;
        sf[i]=(sf[i-1]+f[i][2])%Mod;
    }
    while(T--){
        cin>>n;
        int ans=(f[n][0]+f[n][1]+sf[n])%Mod;
        printf("%lld\n",ans);
    }
    return 0;
}


