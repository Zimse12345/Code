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
//#define int long long
//#define M ((L+R)/2)
//#define Lid (id<<1)
//#define Rid (Lid|1)

namespace Zimse{
const int INF=1000114514,Mod=998244353;//1000000007
inline int read(){int x=0,y=1;char c=gc();while(c<48||57<c)
{if(c==45)y=-1;c=gc();}while(47<c&&c<58)x=x*10+c-48,c=gc();return x*y;}
inline void WRI(int x){if(x<0)pc(45),x=-x;if(x>=10)WRI(x/10);pc(48+x%10);return;}
inline void write_(int x){WRI(x),pc(32);return;}
inline void _write(int x){WRI(x),pc(10);return;}
inline void ifile(const char str[]){freopen(str,"r",stdin);return;}
inline void ofile(const char str[]){freopen(str,"w",stdout);return;}
inline int fpow(int x,int y=Mod-2){int res=1;while(y)
{if(y&1)res=1ll*res*x%Mod;x=1ll*x*x%Mod,y/=2;}return res;}
inline int _abs(int x){return x<0?-x:x;}
inline void _max(int& x,int y){if(x<y)x=y;return;}
inline void _min(int& x,int y){if(y<x)x=y;return;}
inline void addmod(int& x,int y){(x+=y)%=Mod;return;}
}using namespace Zimse;using namespace std;

const int N=1000007;

int n,a[N],b[N],ans;

signed main(){
    n=read();
    for(int i=1;i<=n;i++)a[i]=read();
    for(int i=1;i<=n;i++)b[i]=read();
    for(int i=1;i<=n;i++){
        int mn=INF;
        for(int j=1;j<=n;j++)_min(mn,_abs(a[i]-b[j]));
        _max(ans,mn);
    }
    _write(ans);
    return 0;
}
