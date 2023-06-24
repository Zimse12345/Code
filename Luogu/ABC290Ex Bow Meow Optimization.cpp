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

const int N=1.01e6;
int n,m,a[N],b[N],tot,nn,mm,pre[2],f[605][305][305];

struct node{
    int val,col;
    node(int val=0,int col=0):val(val),col(col){}
    bool operator < (const node &_)const{return val>_.val;}
}p[N];

signed main(){
    n=read(),m=read();
    for(int i=1;i<=n;i++)a[i]=read();
    for(int i=1;i<=m;i++)b[i]=read();
    sort(a+1,a+n+1),sort(b+1,b+m+1);
    if(n&1)--n,nn=1;
    if(m&1)--m,mm=1;
    for(int i=1;i<=n;i++)p[++tot]=node(a[i],0);
    for(int i=1;i<=m;i++)p[++tot]=node(b[i],1);
    sort(p+1,p+tot+1);
    for(int i=0;i<=tot;i++){
        for(int x=0;x<=n;x++){
            for(int y=0;y<=m;y++)f[i][x][y]=INF;
        }
    }
    f[0][0][0]=0;
    if(mm)f[0][0][0]+=a[n+1];
    if(nn)f[0][0][0]+=b[m+1];
    for(int i=1;i<=tot;i++){
        for(int x=0;x<=pre[0];x++){
            for(int y=0;y<=pre[1];y++)if(f[i-1][x][y]<INF){
                if(p[i].col==0){
                    _min(f[i][x+1][y],f[i-1][x][y]+p[i].val*(y*2+mm));
                    _min(f[i][x][y],f[i-1][x][y]+p[i].val*((pre[1]-y)*2+mm));
                }
                if(p[i].col==1){
                    _min(f[i][x][y+1],f[i-1][x][y]+p[i].val*(x*2+nn));
                    _min(f[i][x][y],f[i-1][x][y]+p[i].val*((pre[0]-x)*2+nn));
                }
            }
        }
        ++pre[p[i].col];
    }
    _wri(f[tot][n/2][m/2]);
    return 0;
}

