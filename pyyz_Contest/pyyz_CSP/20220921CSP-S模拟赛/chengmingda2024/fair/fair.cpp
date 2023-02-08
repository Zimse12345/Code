/********************************
*FileName:
*Author: Zimse
*Data: 2022-09-21
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
#define ll long long
#define int long long
//#define M ((L+R)/2)
//#define Lid (id<<1)
//#define Rid (Lid|1)
//#define Lid ch[id][0]
//#define Rid ch[id][1]

using namespace std;

namespace Zimse{
const int Mod=998244353;
//const int Mod=1000000007;
inline int read(){int x=0,y=1;char c=gc();while(c<48||c>57){if(c==45)y=-1;c=gc();}while(c>=48&&c<=57)x=x*10+c-48,c=gc();return x*y;}
inline void write(int x){if(x<0)pc(45),x=-x;if(x>=10)write(x/10);pc(48+x%10);return;}
inline void _Yes(){pc(89),pc(101),pc(115),pc(10);return;}
inline void _No(){pc(78),pc(111),pc(10);return;}
inline void _ck(bool x){x?yes:no;return;}
inline void write_(int x){write(x),pc(32);return;}
inline void _write(int x){write(x),pc(10);return;}
inline void ifile(const char str[]){freopen(str,"r",stdin);return;}
inline void ofile(const char str[]){freopen(str,"w",stdout);return;}
inline void cfile(){fclose(stdin),fclose(stdout);return;}
inline ll fpow(ll x,ll y){ll res=1ll;while(y){if(y&1ll)res=res*x%Mod;x=x*x%Mod,y/=2ll;}return res;}
inline ll inv(ll x){return fpow(x,Mod-2);}
inline int _gcd(int x,int y){return y?_gcd(y,x%y):x;}
inline int _abs(int x){return x<0?-x:x;}
inline void _max(int& x,int y){if(y>x)x=y;return;}
inline void _min(int& x,int y){if(y<x)x=y;return;}
inline void addmod(int& x,int y){(x+=y)%=Mod;return;}
const int INF=1000114514;
}using namespace Zimse;

const int N=256;

int n,m,U[N],V[N],P[N],e[N][N],ans,bet[1000000],f[1000000],ibet[1000000];

signed main(){
    ifile("fair.in"),ofile("fair.out");
    n=read(),m=read();
    for(int i=0;i<m;i++){
        U[i]=read()-1,V[i]=read()-1,P[i]=1-read();
    }
    for(int i=0;i<(1<<n);i++){
        bet[i]=1;
        for(int j=0;j<m;j++){
            if((i&(1<<U[j]))&&(i&(1<<V[j])))bet[i]=bet[i]*(1-P[j])%Mod;
        }
        ibet[i]=inv(bet[i]);
    }
    for(int x=1;x<(1<<n);x++){
        int t=0;
        for(int i=0;i<n;i++)if(x&(1<<i)){
            t=i;
            break;
        }
        for(int y=x;y;y=(y-1)&x)if(y&(1<<t)){
            if(y==x)continue;
            addmod(f[x],(1-f[y])*bet[x]%Mod*ibet[y]%Mod*ibet[x^y]);
        }
        int p=1;
        for(int j=0;j<m;j++){
            int a=(x&(1<<U[j]))?1:0;
            int b=(x&(1<<V[j]))?1:0;
            if(a^b)p=p*(1-P[j])%Mod;
        }
        addmod(ans,(1-f[x])*p);
    }
    addmod(ans,Mod);
    _write(ans);
    return 0;
}
