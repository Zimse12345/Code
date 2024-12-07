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
int T,x,m;

signed main(){
    cin>>T;
    while(T--){
        cin>>x>>m;
        int ans=0;
        for(int i=1;i<=m&&i<=x*4;i++){
            int v=(x^i);
            if(v%i==0||v%x==0)++ans;
        }
        int l=1,r=m/x+1;
        if(l<=r){
            for(int k=1;k<=x*2+100;k++){
                if(r<l)break;
                int y=((l*x)^x);
                if(x*4<y&&y<=m)++ans;
                ++l;
                if(r<l)break;
                y=((r*x)^x);
                if(x*4<y&&y<=m)++ans;
                --r;
            }
            if(l<=r)ans+=(r-l+1);
            
        }
        printf("%lld\n",ans);
    }
    return 0;
}


