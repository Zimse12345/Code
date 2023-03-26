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
#define pb push_back
#define inv fpow
//#define int long long
//#define M ((L+R)/2)
//#define Lid (id<<1)
//#define Rid (Lid|1)

namespace Zimse{
const int INF=1000114514,Mod=1000000007;//1000000007
inline int read(){int x=0,y=1;char c=gc();while(c<48||57<c)
{if(c==45)y=-1;c=gc();}while(47<c&&c<58)x=x*10+c-48,c=gc();return x*y;}
inline void WRI(int x){if(x<0)pc(45),x=-x;if(x>=10)WRI(x/10);pc(48+x%10);return;}
inline void write_(int x){WRI(x),pc(32);return;}
inline void _write(int x){WRI(x),pc(10);return;}
inline void ifile(const char str[]){freopen(str,"r",stdin);return;}
inline void ofile(const char str[]){freopen(str,"w",stdout);return;}
inline int fpow(int x,int y=Mod-2){int res=1;while(y)
{if(y&1)res=1ll*res*x%Mod;x=1ll*x*x%Mod,y/=2;}return res;}
inline void _max(int& x,int y){if(x<y)x=y;return;}
inline void _min(int& x,int y){if(y<x)x=y;return;}
inline void addmod(int& x,int y){if(!x)x=y;else (x+=y)%=Mod;return;}
}using namespace Zimse;using namespace std;

const int N=2200000;

int n,d,a[N],ans,f[2][10][N],t,lim;

signed main(){
    // ifile("stone.in");
    // ofile("stone.out");

    n=read(),d=read();
    for(int i=1;i<=n;i++)a[i]=read();
    sort(a+1,a+n+1);
    f[t][0][0]=1;
    for(int i=1;i<=n;i++){
        t^=1;
        for(int j=0,_j=1;j<d;j++,_j++){
            if(_j==d)_j=0;
            for(int k=0;k<(1<<lim);k++)if(f[t^1][j][k]){
                addmod(f[t][j][k^a[i]],f[t^1][j][k]);
                addmod(f[t][_j][k],f[t^1][j][k]);
                f[t^1][j][k]=0;
            }
        }
        while((1<<lim)<=a[i])++lim;
    }
    ans=f[t][0][0];
    if(n%d==0)addmod(ans,Mod-1);
    _write(ans);
    return 0;
}
