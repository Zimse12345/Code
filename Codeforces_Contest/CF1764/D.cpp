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

int P;
#define Mod P

using namespace std;

namespace Zimse{
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
inline void cfile(){fclose(stdin),fclose(stdout);return;}
inline ll fpow(ll x,ll y){ll res=1;while(y){if(y&1)res=res*x%Mod;x=x*x%Mod,y/=2;}return res;}
inline ll inv(ll x){return fpow(x,Mod-2);}
inline int _gcd(int x,int y){return y?_gcd(y,x%y):x;}
inline int _abs(int x){return x<0?-x:x;}
inline void _max(int& x,int y){if(x<y)x=y;return;}
inline void _min(int& x,int y){if(y<x)x=y;return;}
inline void addmod(int& x,int y){(x+=y)%=Mod;return;}
const int INF=1000114514;
}using namespace Zimse;

const int N=5140;

int n,ans,C[N][N],fac[N];

signed main(){
    n=read(),Mod=read();
    C[0][0]=fac[0]=1;
    for(int i=1;i<N;i++){
        C[i][0]=1,fac[i]=fac[i-1]*i%Mod;
        for(int j=1;j<N;j++)C[i][j]=(C[i-1][j]+C[i-1][j-1])%Mod;
    }
    for(int i=n/2;i<n;i++){
        int rm=n-i-1,t=0;
        if(i!=n-1)--rm;
        for(int j=1;j<=i;j++){
            if(j-1<n/2&&i-j<n/2)++t;
        }
        for(int j=0;j<=rm;j++){
            addmod(ans,C[rm][j]*fac[j+i-1]%Mod*t);
        }
    }
    ans=ans*n%Mod;
    _write(ans);
    return 0;
}
