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

const int N=45;

int testid,n,m,mp[N][N],X,Y,sum[N][N];
int f[N][N][N][N];
bool vis[N][N][N][N];

int qsum(int X1,int X2,int Y1,int Y2){
    return sum[X2][Y2]-sum[X2][Y1-1]-sum[X1-1][Y2]+sum[X1-1][Y1-1];
}

int dp(int X1,int X2,int Y1,int Y2){
    int &F=f[X1][X2][Y1][Y2];
    if(vis[X1][X2][Y1][Y2])return F;
    if(X1==X2&&Y1==Y2)return 0;
    vis[X1][X2][Y1][Y2]=1;
    F=min(min(qsum(X1,X,Y1,Y),qsum(X1,X,Y,Y2)),min(qsum(X,X2,Y,Y2),qsum(X,X2,Y1,Y)));
    for(int x=X1;x<X2;x++){
        for(int y=Y1;y<Y2;y++){
            if(X<=x&&Y<=y)_min(F,dp(X1,x,Y1,y)+qsum(x+1,X2,Y1,y)+qsum(X1,x,y+1,Y2));
            if(X>x&&Y>y)_min(F,dp(x+1,X2,y+1,Y2)+qsum(x+1,X2,Y1,y)+qsum(X1,x,y+1,Y2));
            if(X<=x&&Y>y)_min(F,dp(X1,x,y+1,Y2)+qsum(X1,x,Y1,y)+qsum(x+1,X2,y+1,Y2));
            if(X>x&&Y<=y)_min(F,dp(x+1,X2,Y1,y)+qsum(X1,x,Y1,y)+qsum(x+1,X2,y+1,Y2));
        }
    }
    return F;
}

signed main(){
    testid=read(),n=read(),m=read();
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            mp[i][j]=read();
            if(mp[i][j]==2)mp[i][j]=0,X=i,Y=j;
            sum[i][j]=sum[i][j-1]+sum[i-1][j]-sum[i-1][j-1]+mp[i][j];
        }
    }
    _write(dp(1,n,1,m));
    return 0;
}
