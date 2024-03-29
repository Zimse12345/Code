/********************
*FileName:
*Author: Zimse
*Data: 2023-03-
*Description:
********************/

#include <bits/stdc++.h>
#define gc getchar
#define pc putchar
#define pb push_back
#define inv fpow
#define int long long
//#define M ((L+R)/2)
//#define Lid (id<<1)
//#define Rid (Lid|1)

namespace Zimse{
const int INF=1000114514,Mod=1000000007;//1000000007
inline int read(){int x=0,y=1;char c=gc();while(c<48||57<c)
{if(c==45)y=-1;c=gc();}while(47<c&&c<58)x=x*10+c-48,c=gc();return x*y;}
inline void WRI(int x){if(x<0)pc(45),x=-x;if(x>=10)WRI(x/10);pc(48+x%10);return;}
inline void write_(int x){WRI(x),pc(32);return;}
inline void _write(int x){WRI(x),pc(10);return;}
inline void ifile(const char str[]){freopen(str,"r",stdin);return;}
inline void ofile(const char str[]){freopen(str,"w",stdout);return;}
inline int fpow(int x,int y=Mod-2){int res=1;while(y)
{if(y&1)res=1ll*res*x%Mod;x=1ll*x*x%Mod,y/=2;}return res;}
inline void _max(int& x,int y){if(x<y)x=y;return;}
inline void _min(int& x,int y){if(y<x)x=y;return;}
inline void addmod(int& x,int y){(x+=y)%=Mod;return;}
}using namespace Zimse;using namespace std;

const int N=1000007;

int T,n,ans;

int phi(int x){
    int res=1;
    for(int i=2;i*i<=x;i++)if(x%i==0){
        x/=i,res*=i-1;
        while(x%i==0)x/=i,res*=i;
    }
    if(x>1)res*=x-1;
    return res;
}

signed main(){
    T=read();
    while(T--){
        n=read(),ans=0;
        for(int i=1;i*i<=n;i++)if(n%i==0){
            addmod(ans,fpow(n,i)*phi(n/i));
            if(i*i!=n)addmod(ans,fpow(n,n/i)*phi(i));
        }
        _write(ans*inv(n)%Mod);
    }
    return 0;
}
