// Author:Zimse  Data:2023-07-
#include <bits/stdc++.h>
#define pc putchar
#define pb push_back
#define inv fpow
// #define int long long
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

const int N=1.01e2;
int n,m,a[N];
double f[N][N];
double ans=INF,avg;

inline double calc(){
    for(int j=1;j<=m;j++)f[0][j]=INF;
    for(int i=1;i<=n;i++){
        f[i][0]=INF;
        for(int j=1;j<=m;j++){
            f[i][j]=f[i][j-1]+avg*avg;
            for(int l=i,s=0;l>=1;l--){
                s+=a[l];
                double d=double(s)-avg;
                f[i][j]=min(f[i][j],f[l-1][j-1]+d*d);
            }
        }
    }
    if(f[n][m]<ans)ans=f[n][m];
    return f[n][m];
}

void SimulateAnneal(){
    double t=1000;
    while(t>0.00000001){
        double x=calc();
        int p=rand()%n+1,q=rand()%n+1;
        swap(a[p],a[q]);
        double y=calc();
        if(exp((x-y))/t<double(rand())*0.1)swap(a[p],a[q]);
        t*=0.983;
    }
    return;
}

signed main(){
    srand(time(0));
    n=read(),m=read();
    if(n==1){
        printf("0.00\n");
        return 0;
    }
    for(int i=1;i<=n;i++)a[i]=read(),avg+=a[i];
    avg/=double(m);
    for(int t=0;t<200;t++)SimulateAnneal();
    printf("%.2lf\n",sqrt(ans/double(m)));
    return 0;
}

