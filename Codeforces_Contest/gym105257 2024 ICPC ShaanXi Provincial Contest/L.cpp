// Author:Zimse  Data:2024-07-
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
int ans[N],f[N];

bool ck(int x,int k){
    int v=x,mul=1;
    while(v){
        mul*=v%k;
        v/=k;
    }
    if(mul&&x%mul==0)return true;
    return false;
}

signed main(){
    int T;
    T=read();
    while(T--){
        int n=read(),k=2;
        while(n%k==0)++k;
        _wri(k);
    }
//    for(int k=2;k<=20;k++){
//        f[1]=1;
//        for(int i=2;i<=1000;i++){
//            for(int j=1;j<=i;j++)if(ck(j,k)&&f[i-j]==0){
//                f[i]=1;
//                if(!ans[i])ans[i]=k;
//            }
//        }
//    }
//    ans[1]=2;
//    for(int i=1;i<=1000;i++)if(ans[i]>3)printf("%3d %3d\n",i,ans[i]);
    return 0;
}



