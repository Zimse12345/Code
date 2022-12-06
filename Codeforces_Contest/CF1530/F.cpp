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
// #define int long long
// #define M ((L+R)/2)
// #define Lid (id<<1)
// #define Rid (Lid|1)
// #define Lid ch[id][0]
// #define Rid ch[id][1]

using namespace std;

namespace Zimse{
const int Mod=31607;
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

const int N=32;

int n,m,a[N][N],f[8500000],popc[8500000],p2[8500000],Mul[8500000],_lg[8500000];

inline int lowbit(int x){
    return x&(-x);
}

signed main(){
	n=read(),m=(1<<n);
	for(int i=0;i<n;i++)for(int j=0;j<n;j++)a[i][j]=read()*inv(10000)%Mod;
    for(int i=0;i<n;i++)_lg[1<<i]=i;
    p2[0]=f[0]=1;
    for(int z=1;z<(1<<(n+2));z++)popc[z]=popc[z^lowbit(z)]+1,p2[z]=p2[z-1]*2,f[z]=1;
    for(int i=0;i<n;i++){
        Mul[0]=1;
        for(int z=1;z<(1<<n);z++)Mul[z]=(Mul[z^(lowbit(z))]*a[i][_lg[lowbit(z)]])%Mod;
        for(int z=0;z<(1<<(n+2));z++){
            int _z=(z&(m-1));
            if(z&p2[n])_z|=p2[i];
            if(z&p2[n+1])_z|=p2[n-i-1];
            (f[z]*=Mul[_z])%=Mod;
            _z^=(m-1);
            (f[z]*=(1-Mul[_z]))%=Mod;
        }
    }
    int ans=0;
    for(int z=0;z<(1<<(n+2));z++){
        int val=1;
        if(popc[z]&1)val=-1;
        addmod(ans,f[z]*val);
    }
    ans=1-ans;
    addmod(ans,Mod);
    _write(ans);
    return 0;
}


