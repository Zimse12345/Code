/********************
*FileName:
*Author: Zimse
*Data: 2023-03-
*Description:
********************/

#include <algorithm>
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
#define inv fpow
//#define int long long
//#define M ((L+R)/2)
//#define Lid (id<<1)
//#define Rid (Lid|1)

namespace Zimse{
const int INF=1000114514,Mod=998244353;//1000000007
inline int read(){int x=0,y=1;char c=gc();while(c<48||57<c)
{if(c==45)y=-1;c=gc();}while(47<c&&c<58)x=x*10+c-48,c=gc();return x*y;}
inline void WRI(int x){if(x<0)pc(45),x=-x;if(x>=10)WRI(x/10);pc(48+x%10);return;}
inline void write_(int x){WRI(x),pc(32);return;}
inline void _write(int x){WRI(x),pc(10);return;}
inline void _ck(bool x){x?yes:no;return;}
inline int fpow(int x,int y=Mod-2){int res=1;while(y)
{if(y&1)res=1ll*res*x%Mod;x=1ll*x*x%Mod,y/=2;}return res;}
inline int _gcd(int x,int y){return y?_gcd(y,x%y):x;}
inline int _lcm(int x,int y){return x/_gcd(x,y)*y;}
inline int _abs(int x){return x<0?-x:x;}
inline void _max(int& x,int y){if(x<y)x=y;return;}
inline void _min(int& x,int y){if(y<x)x=y;return;}
inline void addmod(int& x,int y){(x+=y)%=Mod;return;}
}using namespace Zimse;using namespace std;

const int N=512;

int n,T,a[N],f[N][N][24],F[N],g[N][N],ans[N][N][2],V,tt,Ans,_a[N];
map<int,int> mp;

signed main(){
    n=read(),T=read();
    for(int i=1;i<=n;i++)a[i]=_a[i]=read();
    sort(_a+1,_a+n+1);
    for(int i=1;i<=n;i++)if(_a[i]!=_a[i-1])mp[_a[i]]=++V;
    for(int i=1;i<=n;i++)a[i]=mp[a[i]];
    for(int i=1;i<=V;i++){
        for(int j=1;j<=V;j++)F[j]=-INF;
        F[i]=0;
        for(int j=1;j<=n;j++){
            int Mx=-INF;
            for(int k=1;k<=a[j];k++)_max(Mx,F[k]);
            _max(F[a[j]],Mx+1);
        }
        int Mx=0;
        for(int j=i;j<=V;j++)_max(Mx,F[j]),f[i][j][0]=Mx;
    }
    for(int w=0;w<24;w++){
        if(w>0){
            for(int i=1;i<=V;i++){
                for(int j=i;j<=V;j++){
                    f[i][j][w]=-INF;
                    for(int k=i;k<=j;k++)_max(f[i][j][w],f[i][k][w-1]+f[k][j][w-1]);
                }
            }
        }
        if(T&(1<<w)){
            tt^=1;
            for(int i=1;i<=V;i++){
                for(int j=i;j<=V;j++){
                    ans[i][j][tt]=-INF;
                    for(int k=i;k<=j;k++)_max(ans[i][j][tt],ans[i][k][tt^1]+f[k][j][w]);
                }
            }
        }
    }
    for(int i=1;i<=V;i++)for(int j=i;j<=V;j++)_max(Ans,ans[i][j][tt]);
    _write(Ans);
    return 0;
}
