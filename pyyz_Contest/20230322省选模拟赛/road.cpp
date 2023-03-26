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

int Mod;
namespace Zimse{
const int INF=1000114514;//Mod=998244353;//1000000007
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
inline void addmod(int& x,int y){(x+=y)%=Mod;return;}
}using namespace Zimse;using namespace std;

const int N=105;

int n,m,q,f[N][N][N],g[N][N][N],h[N][N][N];

struct mixtra{
    int x[N][N];
}F[N];

mixtra mul(const mixtra& x,const mixtra &y){
    mixtra res;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            res.x[i][j]=0;
            for(int k=1;k<=n;k++)res.x[i][j]=(res.x[i][j]+1ll*x.x[i][k]*y.x[k][j]%Mod)%Mod;
        }
    }
    return res;
}

signed main(){
    // ifile("road.in");
    // ofile("road.out");

    n=read(),m=read(),Mod=read();
    for(int i=1;i<=n;i++)F[0].x[i][i]=1;
    for(int i=1,u,v;i<=m;i++)u=read(),v=read(),F[1].x[u][v]=1;
    for(int i=2;i<=50;i++)F[i]=mul(F[i-1],F[1]);
    for(int d=1;d<=50;d++){
        for(int u=1;u<=n;u++){
            for(int v=1;v<=n;v++){
                g[u][v][d]=F[d].x[u][v];
                for(int p=1;p<d;p++)addmod(g[u][v][d],-1ll*F[p].x[u][u]*g[u][v][d-p]%Mod);
                f[u][v][d]=g[u][v][d];
                if(u==v)continue;
                for(int p=1;p<d;p++)addmod(f[u][v][d],-1ll*h[u][v][p]*f[u][v][d-p]%Mod);
                h[u][v][d]=F[d].x[v][v];
                for(int p=1;p<d;p++)addmod(h[u][v][d],-1ll*F[p].x[v][u]*g[u][v][d-p]%Mod);
            }
        }
    }
    q=read();
    while(q--){
        int S=read(),T=read(),D=read();
        if(f[S][T][D]<0)f[S][T][D]+=Mod;
        _write(f[S][T][D]);
    }
    return 0;
}
