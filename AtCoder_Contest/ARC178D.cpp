// Author:Zimse  Data:2023-07-
#include <bits/stdc++.h>
#define pc putchar
#define pb push_back
#define inv fpow
 #define int long long
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

const int N=512;
int n,m,p[N],f[N][N][N],vis[N],cnt,ans,mn; 

signed main(){
    n=read(),m=read();
    for(int i=1;i<=m;i++)p[i]=read(),vis[p[i]]=1;
    while(vis[mn])++mn;
    p[0]=p[m+1]=INF;
    f[0][0][m+1]=1;
    for(int x=n-1;x>=0;x--)if(!vis[x]){
        int L=0,R=m+1;
        while(x<p[L+1]&&L<m)++L;
        while(x<p[R-1]&&R>1)--R;
        for(int l=0;l<=m;l++){
            for(int r=l+1;r<=m+1;r++)if(f[cnt][l][r]){
                int v=f[cnt][l][r];
                if(x==0){
                    _mod(ans,v*(r-l));
                    continue;
                }
                _mod(f[cnt+1][l][r],v*2);
                _mod(f[cnt+1][l+1][r],-v);
                _mod(f[cnt+1][l][r-1],-v);
                _mod(f[cnt+1][l][R-1],-v);
                _mod(f[cnt+1][L+1][r],-v);
                _mod(f[cnt+1][l+1][R-1],v);
                _mod(f[cnt+1][L+1][r-1],v);
            }
        }
        ++cnt;
        for(int l=0;l<=m;l++){
            for(int r=m+1;r>l;r--){
                if(l>0)_mod(f[cnt][l][r],f[cnt][l-1][r]);
                if(r<m+1)_mod(f[cnt][l][r],f[cnt][l][r+1]);
                if(l>0&&r<m+1)_mod(f[cnt][l][r],-f[cnt][l-1][r+1]);
            }
        }
    }
    for(int l=0;l<=m;l++)for(int r=l+1;r<=m+1;r++)_mod(ans,f[cnt][l][r]);
    _mod(ans,Mod);
    _wri(ans);
    return 0;
}



