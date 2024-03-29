/************************
*FileName:
*Author: Zimse
*Data: 2023-02-
*Description:
************************/

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
#define ll __int128
#define int __int128
// #define M ((L+R)/2)
// #define Lid (id<<1)
// #define Rid (Lid|1)
// #define Lid ch[id][0]
// #define Rid ch[id][1]

int Mod;

namespace Zimse{
const int INF=1000114514;
// const int Mod=998244353;
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
inline ll fpow(ll x,ll y){ll res=1;while(y){if(y&1)res=res*x%Mod;x=x*x%Mod,y/=2;}return res;}
inline ll inv(ll x){return fpow(x,Mod-2);}
inline int _gcd(int x,int y){return y?_gcd(y,x%y):x;}
inline int _lcm(int x,int y){return x/_gcd(x,y)*y;}
inline int _abs(int x){return x<0?-x:x;}
inline void _max(int& x,int y){if(x<y)x=y;return;}
inline void _min(int& x,int y){if(y<x)x=y;return;}
inline void addmod(int& x,int y){(x+=y)%=Mod;return;}
}using namespace Zimse;using namespace std;

const int N=2500007;

int n,m,t,a[N],b[N],popc[N],c[N];

inline int lowbit(int x){
    return x&(-x);
}

void fwt(int *f){
    for(int i=0;i<m;i++){
        for(int j=0;j<n;j++)if(j&(1<<i)){
            int x=f[j^(1<<i)],y=f[j];
            f[j^(1<<i)]=(x+y)%Mod;
            f[j]=(x-y+Mod)%Mod;
        }
    }
    return;
}

signed main(){
    m=read(),t=read();
    n=1;
    for(int i=1;i<=m;i++)n*=2;
    Mod=read()*n;
    for(int i=0;i<n;i++)b[i]=read();
    for(int i=1;i<n;i++)popc[i]=popc[i^lowbit(i)]+1;
    for(int i=0;i<=m;i++)c[i]=read();
    for(int i=0;i<n;i++)a[i]=c[popc[i]];
    fwt(a),fwt(b);
    for(int i=0;i<n;i++)a[i]=b[i]*fpow(a[i],t)%Mod;
    fwt(a);
    for(int i=0;i<n;i++)_write(a[i]/n);
    return 0;
}
