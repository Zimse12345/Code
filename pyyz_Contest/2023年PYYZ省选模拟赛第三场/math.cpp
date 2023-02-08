/************************
*FileName:
*Author: Zimse
*Data: 2023-01-
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

int Mod;

namespace Zimse{
const int INF=1000114514;
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

const int SZ=3010;

int n,f[SZ][SZ],g[SZ][SZ],gg[SZ][SZ],gg2[SZ][SZ],fac[SZ],ifac[SZ];

int C(int x,int y){
    return fac[x]*ifac[y]%Mod*ifac[x-y]%Mod;
}

signed main(){
	// ifile("math.in");
	// ofile("math.out");
	 
    n=read(),Mod=read();
    fac[0]=ifac[0]=1;
    for(int i=1;i<SZ;i++)fac[i]=fac[i-1]*i%Mod,ifac[i]=inv(fac[i]);
    f[1][1]=f[0][0]=1;
    for(int i=1;i<n;i++){
        for(int j=1;j<=i;j++)addmod(f[i+1][j],f[i][j]*j),addmod(f[i+1][j+1],f[i][j]);
    }
    for(int i=n;i>=0;i--){
        g[i][0]=1;
        gg[i][0]=0;
        for(int j=1;j<=n;j++){
        	g[i][j]=(g[i][j-1]*i+g[i+1][j-1])%Mod;
        	gg[i][j]=(gg[i][j-1]*i+g[i][j-1]+gg[i+1][j-1])%Mod;
        	gg2[i][j]=(gg2[i][j-1]*i+(2*gg[i][j-1]+g[i][j-1])+gg2[i+1][j-1])%Mod;
		}
    }
    for(int i=1;i<=n;i++){
        int ans=0;
        for(int j=1;j<=n;j++){
            int x=(f[j][i]-f[j-1][i]*i)%Mod;
            addmod(x,Mod);
            addmod(ans,(gg2[i][n-j]+2*gg[i][n-j]+g[i][n-j])%Mod*x);
        }
        addmod(ans,Mod);
        write_(ans);
    }
    pc(10);
    return 0;
}
