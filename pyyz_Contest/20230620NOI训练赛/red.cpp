// Author:Zimse  Data:2023-06-
#include <bits/stdc++.h>
#define pc putchar
#define pb push_back
#define inv fpow
#define int long long
//#define M ((L+R)/2)
namespace OI{const int INF=1.01e18,Mod=998244353;int read(){int x=0
,y=1;char c=getchar();while(c<48||57<c){if(c==45)y=-1;c=getchar();}
while(47<c&&c<58)x=x*10+c-48,c=getchar();return x*y;}void wr(int x)
{if(x<0)pc(45),x=-x;if(x>=10)wr(x/10);pc(48+x%10);}void wri(int x){
wr(x),pc(32);}void _wri(int x){wr(x),pc(10);}void iF(const char*x){
freopen(x,"r",stdin);}void oF(const char*x){freopen(x,"w",stdout);}
inline int fpow(long long x,int y=Mod-2){int z=1;while(y){if(y&1)z=
x*z%Mod;x=x*x%Mod,y/=2;}return z;}inline void _max(int&x,int y){if(
x<y)x=y;}inline void _min(int&x,int y){if(y<x)x=y;}inline void _mod
(int&x,int y){(x+=y)%=Mod;}}using namespace OI;using namespace std;

const int N=105,M=20005;
int n,m,F,w[N][M],h[N][M],a[N][M],f[N][M],l,r;

struct point{
    int x,y;
    point(int x=0,int y=0):x(x),y(y){}
}stk[M];

signed main(){
    iF("red.in");
    oF("red.out");
    
    n=read(),m=read(),F=read();
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++)w[i][j]=read();
    }
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++)h[i][j]=read();
    }
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++)a[i][j]=read();
    }
    f[0][1]=F;
    for(int i=2;i<=m;i++)f[0][i]=-INF;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++)f[i][j]=f[i-1][j]-w[i-1][j];
        
        l=r=1,stk[1]=point(h[i][1],f[i][1]-w[i][1]);
        for(int j=2;j<=m;j++){
            while(l<r&&(stk[l].y-stk[l+1].y)<=-a[i][j]*(stk[l].x-stk[l+1].x))++l;
            _max(f[i][j],stk[l].y+a[i][j]*stk[l].x);
            point t=point(h[i][j],f[i][j]-w[i][j]);
            while(l<=r&&t.x>=stk[r].x)_max(t.y,stk[r].y),--r;
            while(l<r&&(t.y-stk[r].y)*(stk[r].x-stk[r-1].x)<=(stk[r].y-stk[r-1].y)*(t.x-stk[r].x))--r;
            stk[++r]=t;
        }
    }
    if(f[n][m]<0)f[n][m]=-1;
    _wri(f[n][m]);
    return 0;
}



