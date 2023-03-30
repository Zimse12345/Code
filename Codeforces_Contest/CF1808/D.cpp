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
#define yes printf("Yes\n")
#define no printf("No\n")
#define inv fpow
#define int long long
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
inline int _gcd(int x,int y){return y?_gcd(y,x%y):x;}
inline int _lcm(int x,int y){return x/_gcd(x,y)*y;}
inline int _abs(int x){return x<0?-x:x;}
inline void _max(int& x,int y){if(x<y)x=y;return;}
inline void _min(int& x,int y){if(y<x)x=y;return;}
inline void addmod(int& x,int y){(x+=y)%=Mod;return;}
}using namespace Zimse;using namespace std;

const int N=1000007;

int n,k,ans,s[2];
int a[N],t[2][N];
inline void ifile(const char str[]){freopen(str,"r",stdin);return;}
inline void ofile(const char str[]){freopen(str,"w",stdout);return;}

signed main(){
    n=read(),k=read();
    for(int i=1;i<=n;i++)a[i]=read();
    for(int i=1;i<=n;i++){
        ans+=s[i&1]-t[i&1][a[i]];
        ++s[i&1],++t[i&1][a[i]];
        if(i-k+1>0)--t[i&1][a[i-k+1]],--s[i&1];
    }
    for(int i=0;i<2;i++){
        s[i]=0;
        for(int j=0;j<N;j++)t[i][j]=0;
    }
    for(int i=1;i<=k;i++)++s[i&1],++t[i&1][a[i]];
    for(int i=1,r=k;i<=k;i++){
        --s[r&1],--t[r&1][a[r]],--r;
        if(r<i)break;
        --s[i&1],--t[i&1][a[i]];
        ans-=s[i&1]-t[i&1][a[i]];
    }
    for(int i=1;i<=n/2;i++)swap(a[i],a[n-i+1]);
    for(int i=0;i<2;i++){
        s[i]=0;
        for(int j=0;j<N;j++)t[i][j]=0;
    }
    for(int i=1;i<=k;i++)++s[i&1],++t[i&1][a[i]];
    for(int i=1,r=k;i<=k;i++){
        --s[r&1],--t[r&1][a[r]],--r;
        if(r<i)break;
        --s[i&1],--t[i&1][a[i]];
        ans-=s[i&1]-t[i&1][a[i]];
    }
    _write(ans);
    return 0;
}

