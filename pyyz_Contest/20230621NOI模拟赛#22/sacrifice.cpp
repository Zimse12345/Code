// Author:Zimse  Data:2023-06-
#include <bits/stdc++.h>
#define pc putchar
#define pb push_back
#define inv fpow
//#define int long long
//#define M ((L+R)/2)
namespace OI{const int INF=1.001e9,Mod=998244353;int read(){int x=0
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
int n,m,x[N],y[N],cnt,mp[20][20],ans;

signed main(){
    iF("sacrifice.in");
    oF("sacrifice.out");

    n=read(),m=read();
    cnt=read();
    for(int i=1;i<=cnt;i++)x[i]=read(),y[i]=read(),++mp[x[i]][y[i]];
    for(int i=0;i<=n;i++){
        for(int j=0;j<=m;j++){
            if(i)mp[i][j]+=mp[i-1][j];
            if(j)mp[i][j]+=mp[i][j-1];
            if(i&&j)mp[i][j]-=mp[i-1][j-1];
        }
    }
    for(int l1=0;l1<=n;l1++){
        for(int r1=l1+1;r1<=n;r1++){
            for(int u1=0;u1<=m;u1++){
                for(int d1=u1+1;d1<=m;d1++){
                    if(mp[r1][d1]-mp[l1][d1]-mp[r1][u1]+mp[l1][u1])continue;
    for(int l2=0;l2<=n;l2++){
        for(int r2=l2+1;r2<=n;r2++){
            for(int u2=0;u2<=m;u2++){
                for(int d2=u2+1;d2<=m;d2++){
                    if(mp[r2][d2]-mp[l2][d2]-mp[r2][u2]+mp[l2][u2])continue;
                    if(r1<l2)++ans;
                    if(d1<u2)++ans;
                }
            }
        }
    }
                }
            }
        }
    }
    _wri(ans);
    return 0;
}

