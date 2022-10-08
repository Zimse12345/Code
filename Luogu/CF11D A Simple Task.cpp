/********************************
*FileName:
*Author: Zimse
*Data: 2022-09-25
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

const int N=1e6+7;

int n,m,f[N][20],ans[N],tot,popcnt[N];
vector<int> g[N];

inline int lowbit(int x){
    return x&(-x);
}

signed main(){
    n=read(),m=read();
    int _n=n;
    while(m--){
        int u=read()-1,v=read()-1;
        g[u].push_back(v),g[v].push_back(u);
    }
    for(int i=0,I=0;i<(1<<n);i++){
        I=i;
        while(I)I-=lowbit(I),++popcnt[i];
    }
    while(n){
        f[1][0]=1;
        for(int i=0;i<(1<<n);i++){
            for(int u=0;u<n;u++)if(f[i][u]){
                for(unsigned j=0;j<g[u].size();j++){
                    int v=g[u][j];
                    if(v<0)continue;
                    if(!v)ans[popcnt[i]]+=f[i][u];
                    else if(!(i&(1<<v)))f[i|(1<<v)][v]+=f[i][u];
                }
            }
        }
        for(int i=0;i<(1<<n);i++){
            for(int u=0;u<n;u++)f[i][u]=0;
        }
        for(int i=0;i<n;i++){
            g[i]=g[i+1];
            for(unsigned j=0;j<g[i].size();j++)g[i][j]--;
        }
        --n;
    }
    for(int i=3;i<=_n;i++)tot+=ans[i]/2;
    _write(tot);
    return 0;
}
