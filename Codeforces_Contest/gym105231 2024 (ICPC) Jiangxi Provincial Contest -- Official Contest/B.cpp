// Author:Zimse  Data:2024-06-
#include <bits/stdc++.h>
#define pc putchar
#define pb push_back
#define inv fpow
#define int __int128
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
int T,n,p,v[N],k,t,sum[N],ans;

inline int f(int x){
    return x*(x+1)/2;
}

void sol(){
    for(int i=1;i<=p;i++){
        int len=p-i+1;
        if(len>t)continue;
        if(t-len<len){
            _max(ans,sum[p]-sum[i-1]+k*(len*t-f(len-1)));
        }
        else if(i+t-len<=n){
            int a=t-len+1;
            _max(ans,sum[i+a-1]-sum[i-1]+k*(a*t-f(a-1)));
        }
        else{
            int a=n-i+1;
            _max(ans,sum[n]-sum[i-1]+k*(a*t-f(a-1)));
        }
    }
    return;
}

signed main(){
    T=read();
    while(T--){
        n=read(),p=read();
        ans=0;
        for(int i=1;i<=n;i++)v[i]=read(),sum[i]=sum[i-1]+v[i];
        k=read(),t=read();
        sol();
        for(int i=1;i<=n/2;i++)swap(v[i],v[n-i+1]);
        for(int i=1;i<=n;i++)sum[i]=sum[i-1]+v[i];
        p=n-p+1;
        sol();
        _wri(ans);
    }
    return 0;
}

