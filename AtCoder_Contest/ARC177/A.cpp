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

const int N=1.01e6;
int A,B,C,D,E,F,n; 

signed main(){
    A=read(),B=read(),C=read(),D=read(),E=read(),F=read();
    n=read();
    while(n--){
        int x=read(),p=0;
        p=min(x/500,F),F-=p,x-=p*500;
        p=min(x/100,E),E-=p,x-=p*100;
        p=min(x/50,D),D-=p,x-=p*50;
        p=min(x/10,C),C-=p,x-=p*10;
        p=min(x/5,B),B-=p,x-=p*5;
        p=min(x/1,A),A-=p,x-=p*1;
        if(x){
            printf("No\n");
            return 0;
        }
    }
    printf("Yes\n");
    return 0;
}



