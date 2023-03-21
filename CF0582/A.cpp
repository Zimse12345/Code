/********************
*FileName:
*Author: Zimse
*Data: 2023-03-
*Description:
********************/

#include <algorithm>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <ctime>
#include <iostream>
#include <map>
#include <queue>
#include <set>
#include <stack>
#include <vector>

#define gc getchar
#define pc putchar
#define yes printf("Yes\n")
#define no printf("No\n")
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
inline void _ck(bool x){x?yes:no;return;}
inline int fpow(int x,int y=Mod-2){int res=1;while(y)
{if(y&1)res=1ll*res*x%Mod;x=1ll*x*x%Mod,y/=2;}return res;}
inline int _gcd(int x,int y){return y?_gcd(y,x%y):x;}
inline int _lcm(int x,int y){return x/_gcd(x,y)*y;}
inline int _abs(int x){return x<0?-x:x;}
inline void _max(int& x,int y){if(x<y)x=y;return;}
inline void _min(int& x,int y){if(y<x)x=y;return;}
inline void addmod(int& x,int y){(x+=y)%=Mod;return;}
}using namespace Zimse;using namespace std;

const int N=1000007;

int n,a[N],ans[N],_n;
map<int,int> cnt;

signed main(){
    n=read();
    for(int i=1;i<=n*n;i++)a[i]=read();
    sort(a+1,a+n*n+1);
    for(int r=n*n,l=n*n+1;r>=1;r=l-1){
        l=r;
        while(a[l-1]==a[l])--l;
        int tot=r-l+1,x=0;
        tot-=cnt[a[l]];
        if(tot){
            for(int i=1;i<=_n;i++)if(_gcd(a[l],ans[i])==a[l])++x;
            int p=0;
            while(p*p+2*p*x<tot)++p;
            cnt[a[l]]+=p*p;
            while(p--){
                for(int i=1;i<=_n;i++)cnt[_gcd(ans[i],a[l])]+=2;
                ans[++_n]=a[l];
            }
        }
    }
    sort(ans+1,ans+n+1);
    for(int i=1;i<=n;i++)write_(ans[i]);
    pc(10);
    return 0;
}
