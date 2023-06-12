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

const int N=1024;
int n,nl[N],nr[N],ns[N],ni[N],v[N],tot,_tot,ans,p[N],_inv[N],sum[N];

signed main(){
    // iF("starmap.in");
    // oF("starmap.out");
     
    n=read();
    for(int i=1;i<=n+1;i++)_inv[i]=inv(i);
    for(int i=1,l,r;i<=n;i++){
        l=read(),r=read();
        nl[i]=l,nr[i]=r,ns[i]=r-l,ni[i]=inv(ns[i]);
        v[++tot]=l,v[++tot]=r;
    }
    sort(v+1,v+tot+1);
    swap(tot,_tot);
    for(int i=1;i<=_tot;i++)if(v[i]!=v[i-1])v[++tot]=v[i];
    for(int i=1,l,r;i<=n;i++){
        l=nl[i],r=nr[i];
        for(int j=1;j<tot;j++){
            if(v[j]==l)nl[i]=j;
            if(v[j+1]==r)nr[i]=j;
        }
    }
    for(int i=1;i<=n;i++){
        for(int x=nl[i];x<=nr[i];x++){
            int pp=(v[x+1]-v[x])*ni[i]%Mod;
            for(int e=0;e<=n;e++)p[e]=0,sum[e]=0;
            p[0]=1;
            for(int j=i-1;j>=1;j--){
                if(x<nl[j])break;
                int t=(v[min(x,nr[j]+1)]-v[nl[j]])*ni[j]%Mod,t2=0;
                if(x<=nr[j])t2=(v[x+1]-v[x])*ni[j]%Mod;
                for(int e=i-j;e>=0;e--){
                    if(p[e])p[e]=p[e]*t%Mod;
                    if(e&&t2&&p[e-1])_mod(p[e],p[e-1]*t2);
                    sum[e]+=p[e];
                }
            }
            for(int e=1;e<=n;e++)p[e]=0;
            p[0]=1;
            for(int j=i+1;j<=n;j++){
                if(x<nl[j])break;
                int t=(v[min(x,nr[j]+1)]-v[nl[j]])*ni[j]%Mod,t2=0;
                if(x<=nr[j])t2=(v[x+1]-v[x])*ni[j]%Mod;
                for(int e=j-i;e>=0;e--){
                    if(p[e])p[e]=p[e]*t%Mod;
                    if(e&&t2&&p[e-1])_mod(p[e],p[e-1]*t2);
                    sum[e]+=p[e];
                }
            }
            int Sum=0;
            for(int e=0;e<=n;e++)_mod(Sum,sum[e]%Mod*_inv[e+1]);
            _mod(ans,Sum*pp);
        }
    }
    _mod(ans,Mod);
    _wri(ans);
    return 0;
}
