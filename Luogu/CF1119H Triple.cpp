/************************
*FileName:
*Author: Zimse
*Data: 2023-02-
*Description:
************************/

#include <algorithm>
#include <cctype>
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
#define ll long long
#define int long long
// #define M ((L+R)/2)
// #define Lid (id<<1)
// #define Rid (Lid|1)

namespace Zimse{
const int INF=1000114514;
const int Mod=998244353;
// const int Mod=1000000007;
inline int read(){int x=0,y=1;char c=gc();while(c<48||57<c)
{if(c==45)y=-1;c=gc();}while(47<c&&c<58)x=x*10+c-48,c=gc();return x*y;}
inline void write(int x){if(x<0)pc(45),x=-x;if(x>=10)write(x/10);pc(48+x%10);return;}
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

const int N=1100007;

int n,k,X,Y,Z,a[N],b[N],c[N],A,f1[N],f2[N],f3[N],F[N];

void FWT(int *f,int t=1){
    for(int i=0;i<k;i++){
        for(int j=0;j<(1<<k);j++)if(j&(1<<i)){
            int x=f[j^(1<<i)],y=f[j];
            f[j^(1<<i)]=(x+y)*t%Mod;
            f[j]=(x-y)*t%Mod;
        }
    }
    return;
}

signed main(){
    n=read(),k=read();
    X=read(),Y=read(),Z=read();
    for(int i=1;i<=n;i++){
        a[i]=read(),b[i]=read(),c[i]=read();
        b[i]^=a[i],c[i]^=a[i],A^=a[i];
        f1[b[i]]++,f2[c[i]]++,f3[b[i]^c[i]]++;
    }
    FWT(f1),FWT(f2),FWT(f3);
    for(int i=0;i<(1<<k);i++){
        int c1=(n+f1[i]+f2[i]+f3[i])/4;
        int c2=(n+f1[i]-2*c1)/2;
        int c3=(n+f2[i]-2*c1)/2;
        int c4=(n+f3[i]-2*c1)/2;
        F[i]=fpow(X+Y+Z,c1)*fpow(X+Y-Z,c2)%Mod*fpow(X-Y+Z,c3)%Mod*fpow(X-Y-Z,c4)%Mod;
    }
    FWT(F,inv(2));
    for(int i=0;i<(1<<k);i++){
        addmod(F[i^A],Mod);
        write_(F[i^A]);
    }
    pc(10);
    return 0;
}
