// Author:Zimse  Data:2023-06-
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
int n,q,a[N],mxpos,mx;

signed main(){
    iF("debt.in");
    oF("debt.out");

    n=read(),q=read();
    for(int I=1;I<=q;I++){
        int op=read();
        if(op==1){
            int l=read(),r=read(),x=read();
            if(x==mx){
                for(int i=l;i<=r;i++)if(a[i]==x)++a[i],mxpos=i;
                mx=a[mxpos];
            }
            else for(int i=l;i<=r;i++)if(a[i]==x)++a[i];
        }
        else{
            int l=read(),r=read(),x=0;
            if(l<=mxpos&&mxpos<=r)x=mx;
            else for(int i=l;i<=r;i++)_max(x,a[i]);
            _wri(x);
        }
    }
    return 0;
}

