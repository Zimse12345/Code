/************************
*FileName:
*Author: Zimse
*Data: 2023-02-
*Description:
************************/

#pragma GCC optimize("Ofast")
#pragma GCC target("avx")
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

namespace Zimse{
const int INF=1000114514;
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
inline ll fpow(ll x,ll y){ll res=1;while(y){if(y&1)res=res*x%Mod;x=x*x%Mod,y/=2;}return res;}
inline ll inv(ll x){return fpow(x,Mod-2);}
inline int _gcd(int x,int y){return y?_gcd(y,x%y):x;}
inline int _lcm(int x,int y){return x/_gcd(x,y)*y;}
inline int _abs(int x){return x<0?-x:x;}
inline void _max(int& x,int y){if(x<y)x=y;return;}
inline void _min(int& x,int y){if(y<x)x=y;return;}
inline void addmod(int& x,int y){(x+=y)%=Mod;return;}
}using namespace Zimse;using namespace std;

const int N=512;

int T,n,m,a,b,c,f[45][800000],popc[800000],g[N][N],vis[N][N],h[2000][2000],Id;
char str[N][N];

int lowbit(int x){
    return x&(-x);
}

void dp(int l,int r,int x,int y){
    if(vis[l][r]==Id)return;
    g[l][r]=INF,vis[l][r]=Id;
    for(int i=l;i<=r;i++){
        if(((x&(1<<i))>0)&&((y&(1<<i))==0)){
            for(int j=i;j<=r;j++){
                if((x&(1<<j))==0)break;
                dp(j+1,r,x,y);
                _min(g[l][r],min(a*(j-i+1)+b,i==j?c:INF)+g[j+1][r]);
            }
            return;
        }
        if(((x&(1<<i))==0)&&((y&(1<<i))>0)){
            for(int j=i;j<=r;j++){
                if((x&(1<<j))==1)break;
                dp(j+1,r,x,y);
                _min(g[l][r],min(a*(j-i+1)+b,i==j?c:INF)+b+g[j+1][r]);
            }
            return;
        }
    }
    g[l][r]=0;
    return;
}

int sol(int x,int y){
    ++Id;
    dp(0,n-1,x,y);
    int res=g[0][n-1];
    return res;
}

signed main(){
    T=read();
    for(int i=1;i<800000;i++)popc[i]=popc[i^lowbit(i)]+1;
    while(T--){
        n=read(),m=read(),a=read(),b=read(),c=read();
        for(int i=0;i<(1<<n);i++){
            for(int j=0;j<(1<<n);j++){
                if(((i^j)&1)==0)h[i][j]=h[i/2][j/2];
                else h[i][j]=sol(i,j);
            }
        }
        for(int i=1;i<=n;i++)scanf("%s",str[i]+1);
        for(int i=1;i<(1<<n);i++)f[0][i]=INF;
        for(int i=1;i<=m;i++){
            int S=0;
            for(int j=0;j<(1<<n);j++)f[i][j]=INF;

            for(int j=0;j<n;j++)if(str[j+1][i]=='#')S|=(1<<j);
            for(int p=0;p<(1<<n);p++)if(f[i-1][p]<INF){
                for(int q=0;q<(1<<n);q++){
                    int cost=f[i-1][p];
                    cost+=popc[(p^q)&q]*b+popc[q]*a;
                    cost+=h[S][q];
                    _min(f[i][q],cost);
                }
            }
        }
        int ans=INF;
        for(int i=0;i<(1<<n);i++)_min(ans,f[m][i]);
        _write(ans);
    }
    return 0;
}
