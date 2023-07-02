// Author:Zimse  Data:2023-06-
#include <bits/stdc++.h>
#define pc putchar
#define pb push_back
#define inv fpow
#define int long long
namespace OI{const int INF=1.01e9,Mod=1000003;int read(){int x=0
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
int T,n,a[N][N],indeg[N],outdeg[N],fac[N*N];

inline int GetDet(){
    --n;
    int det=1; 
    for(int i=1;i<=n;i++)if(outdeg[i]){
        int t=0;
        for(int j=i;j<=n;j++)if(a[j][i]){t=j;break;}
        if(t^i){
            for(int j=1;j<=n;j++)swap(a[i][j],a[t][j]);
            det=-det;
        }
        for(int j=i+1;j<=n;j++)if(i^j){
            if(a[j][i]>a[i][i]){
                for(int k=1;k<=n;k++)swap(a[i][k],a[j][k]);
                det=-det;
            }
            while(a[j][i]){
                int x=a[i][i]/a[j][i];
                for(int k=1;k<=n;k++)_mod(a[i][k],-a[j][k]*x%Mod+Mod),swap(a[i][k],a[j][k]);
                det=-det;
            }
        }
        det=(det*a[i][i])%Mod;
    }
    ++n;
    for(int i=1;i<=n;i++)for(int j=1;j<=n;j++)a[i][j]=0;
    _mod(det,Mod);
    return det;
}

signed main(){
    fac[0]=1;
    for(int i=1;i<N*N;i++)fac[i]=fac[i-1]*i%Mod;
    T=read();
    while(T--){
        n=read();
        int emp=1;
        for(int i=1;i<=n;i++){
            outdeg[i]=read();
            for(int j=1,v;j<=outdeg[i];j++){
                v=read();
                ++a[v][v],--a[i][v];
                ++indeg[v];
                emp=0;
            }
        }
        int ans=GetDet();
        for(int i=1;i<=n;i++)if(outdeg[i])ans=ans*fac[outdeg[i]-1]%Mod;
        ans=ans*outdeg[1]%Mod;
        for(int i=1;i<=n;i++)if(indeg[i]!=outdeg[i])ans=0; 
        if(emp)ans=1;
        _wri(ans);
        for(int i=1;i<=n;i++)indeg[i]=0;
    }
    return 0;
}
