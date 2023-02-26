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
#define ll long long
#define int long long
// #define M ((L+R)/2)
// #define Lid (id<<1)
// #define Rid (Lid|1)
// #define Lid ch[id][0]
// #define Rid ch[id][1]

namespace Zimse{
const int INF=1000114514;
// const int Mod=998244353;
const int Mod=1000000007;
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

const int N=2000007;

int X1,X2,X3,X4,X5,X6,Y1,Y2,Y3,Y4,Y5,Y6,L[N],R[N],D[N],U[N];
int fac[N],ifac[N],ans;

inline int C(int x,int y){
    return fac[x]*ifac[y]%Mod*ifac[x-y]%Mod;
}

inline int f(int x,int y){
    return C(x+y,x);
}

inline int calc(int a1,int a2,int b1,int b2){
    return (f(a2+1,b2+1)-f(a2+1,b1)-f(a1,b2+1)+f(a1,b1))%Mod;
}

signed main(){
    fac[0]=ifac[0]=1;
    for(int i=1;i<N;i++)fac[i]=fac[i-1]*i%Mod,ifac[i]=inv(fac[i]);
    X1=read(),X2=read(),X3=read(),X4=read(),X5=read(),X6=read();
    Y1=read(),Y2=read(),Y3=read(),Y4=read(),Y5=read(),Y6=read();
    for(int x=X3;x<=X4;x++){
        D[x]=calc(x-X2,x-X1,Y3-1-Y2,Y3-1-Y1);
        U[x]=calc(X5-x,X6-x,Y5-Y4-1,Y6-Y4-1);
        addmod(ans,-calc(X5-x,X6-x,Y5-Y3,Y6-Y3)*D[x]%Mod*(x+Y3));
        addmod(ans,calc(x-X2,x-X1,Y4-Y2,Y4-Y1)*U[x]%Mod*(x+Y4+1));
    }
    for(int y=Y3;y<=Y4;y++){
        L[y]=calc(X3-1-X2,X3-1-X1,y-Y2,y-Y1);
        R[y]=calc(X5-X4-1,X6-X4-1,Y5-y,Y6-y);
        addmod(ans,-calc(X5-X3,X6-X3,Y5-y,Y6-y)*L[y]%Mod*(y+X3));
        addmod(ans,calc(X4-X2,X4-X1,y-Y2,y-Y1)*R[y]%Mod*(y+X4+1));
    }
    addmod(ans,Mod);
    _write(ans);
    return 0;
}
