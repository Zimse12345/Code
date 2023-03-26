/********************************
*FileName:
*Author: Zimse
*Data: 2022-11-
*Description:
*Other:
********************************/

#include <cstdio>
#include <algorithm>
#include <cstring>
#include <vector>
#include <cmath>
#include <set>
#include <map>
#include <queue>
#include <stack>
#include <iostream>
#include <cstdlib>
#include <ctime>
#include <cctype>

#define gc getchar
#define pc putchar
#define yes _Yes()
#define no _No()
#define pb push_back
#define ll long long
#define int long long
// #define M ((L+R)/2)
// #define Lid (id<<1)
// #define Rid (Lid|1)
// #define Lid ch[id][0]
// #define Rid ch[id][1]

using namespace std;

namespace Zimse{
const int Mod=998244353;
// const int Mod=1000000007;

inline int read(){int x=0,y=1;char c=gc();while(c<48||57<c)
{if(c==45)y=-1;c=gc();}while(47<c&&c<58)x=x*10+c-48,c=gc();return x*y;}
inline void write(int x){if(x<0)pc(45),x=-x;if(x>=10)write(x/10);pc(48+x%10);return;}
inline void _Yes(){pc(89),pc(101),pc(115),pc(10);return;}
inline void _No(){pc(78),pc(111),pc(10);return;}
inline void _ck(bool x){x?yes:no;return;}
inline void write_(int x){write(x),pc(32);return;}
inline void _write(int x){write(x),pc(10);return;}
inline void ifile(const char str[]){freopen(str,"r",stdin);return;}
inline void ofile(const char str[]){freopen(str,"w",stdout);return;}
inline void cfile(){fclose(stdin),fclose(stdout);return;}
inline ll fpow(ll x,ll y){ll res=1;while(y){if(y&1)res=res*x%Mod;x=x*x%Mod,y/=2;}return res;}
inline ll inv(ll x){return fpow(x,Mod-2);}
inline int _gcd(int x,int y){return y?_gcd(y,x%y):x;}
inline int _abs(int x){return x<0?-x:x;}
inline void _max(int& x,int y){if(x<y)x=y;return;}
inline void _min(int& x,int y){if(y<x)x=y;return;}
inline void addmod(int& x,int y){(x+=y)%=Mod;return;}
const int INF=1e18;
}using namespace Zimse;

const int N=1000007;

int n,k,f[2][1024][1024];

struct node{
    int w,s,p;
    node(int w=0,int s=0,int p=0):w(w),s(s),p(p){}
    bool operator < (const node& _){
        if(w==_.w)return p<_.p;
        return w<_.w;
    }
}a[N];

signed main(){
    n=read(),k=read();
    if(k*2>n){
        _write(-1);
        return 0;
    }
    for(int i=1,w,s,p;i<=n;i++){
        w=read(),s=read(),p=read();
        if(p==1)p=3;
        else if(p==2)p=1;
        else if(p==3)p=2;
        a[i]=node(w,s,p);
    }
    sort(a+1,a+n+1);
    int T=0;
    for(int i=0;i<=k;i++){
        for(int j=0;j<=k;j++)f[0][i][j]=INF;
    }
    f[0][0][0]=0;
    for(int i=1;i<=n;i++){
        for(int j=0;j<=k;j++){
            for(int t=0;t<=k;t++){
                f[T^1][j][t]=f[T][j][t];
            }
        }
        for(int j=0;j<=k;j++){
            for(int t=0;t<=k;t++){
                if(a[i].p<=2)_min(f[T^1][j][t+1],f[T][j][t]+a[i].s);
                if(a[i].p>=2&&t)_min(f[T^1][j+1][t-1],f[T][j][t]+a[i].s);
            }
        }
        T^=1;
    }
    if(f[T][k][0]==INF)f[T][k][0]=-1;
    _write(f[T][k][0]);
    return 0;
}
