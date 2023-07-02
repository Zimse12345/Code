// Author:Zimse  Data:2023-06-
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
int n,m,id[N];
double f[N][N],p2[N];
char s[N][N];

signed main(){
    n=read(),m=read();
    p2[0]=1;
    for(int i=1;i<N;i++)p2[i]=p2[i-1]/2.0;
    for(int i=1;i<=n;i++){
        scanf("%s",s[i]+1);
    }
    for(int i=1;i<=n;i++){
        f[i][n+1]-=p2[m];
        for(int j=1;j<=n;j++){
            for(int a=1;a<=m;a++){
                int tag=1;
                for(int t=1;t<=a;t++)if(s[i][t]!=s[j][m-a+t]){tag=0;break;}
                if(tag)f[i][j]+=p2[m-a];
            }
        }
    }
    for(int i=1;i<=n;i++)f[n+1][i]=1;
    f[n+1][n+2]=1;
    ++n;
    for(int i=1;i<=n;i++)id[i]=i;
    for(int i=1;i<=n;i++){
        int t=i;
        for(int j=i;j<=n;j++)if(abs(f[j][i])>abs(f[t][i]))t=j;
        for(int j=1;j<=n+1;j++)swap(f[i][j],f[t][j]);
        swap(id[i],id[t]);
        for(int j=1;j<=n;j++)if(j^i){
            double v=f[j][i]/f[i][i];
            for(int k=1;k<=n+1;k++)f[j][k]-=v*f[i][k];
        }
    }
    for(int i=1;i<n;i++)printf("%.7lf\n",f[id[i]][n+1]/f[id[i]][id[i]]);
    return 0;
}

