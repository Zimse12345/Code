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

const int N=1.01e6;
int a1,b1,a2,b2,q,n,ans[N];

void sub(){
    int s=min(a1,a2);
    while(q--){
        n=read();
        int sum=n/(a1+b1)*s;
        n%=(a1+b1);
        sum+=min(n,min(a1,a2));
        _wri(sum);
    }
    return;
}

signed main(){
    iF("snow.in");
    oF("snow.out");

    a1=read(),b1=read(),a2=read(),b2=read(),q=read();
    if(a1+b1==a2+b2){
        sub();
        return 0;
    }
    for(int i=1,l=0,r=1;i<N;i++){
        if((i-1)%(a1+b1)<a1)++r;
        if((i-1)%(a2+b2)<a2)l=min(l+1,r-1);
        ans[i]=l;
    }
    while(q--){
        n=read();
        _wri(ans[n]);
    }
    return 0;
}

