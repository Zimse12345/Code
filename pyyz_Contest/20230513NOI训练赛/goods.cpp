// Author: Zimse
// Data: 2023-05-

#include <bits/stdc++.h>
#define gc getchar
#define pc putchar
#define pb push_back
#define inv fpow
#define int long long
//#define M ((L+R)/2)

namespace Zimse{const int INF=1.01e18,Mod=998244353;
int read(){int x=0,y=1;char c=gc();while(c<48||57<c){if(c==45)
y=-1;c=gc();}while(47<c&&c<58)x=x*10+c-48,c=gc();return x*y;}
void WRI(int x){if(x<0)pc(45),x=-x;if(x>=10)WRI(x/10);pc(48+x%10);}
void write_(int x){WRI(x),pc(32);}void _write(int x){WRI(x),pc(10);}
void ifile(const char *x){freopen(x,"r",stdin);}
void ofile(const char *x){freopen(x,"w",stdout);}
inline int fpow(long long x,int y=Mod-2){int z=1;
while(y){if(y&1)z=x*z%Mod;x=x*x%Mod,y/=2;}return z;}
inline void _max(int &x,int y){if(x<y)x=y;}
inline void _min(int &x,int y){if(y<x)x=y;}
inline void addmod(int &x,int y){(x+=y)%=Mod;}
}using namespace Zimse;using namespace std;

const int N=1.01e6;
int m,L,a[N],b[N],sum,cnt,f[N],vis[N],g[N],V,M;

void upt(int x,int y){
    if(y<-V||y>V||y==0)return;
    for(int i=1;i<=V;i++){
        _max(g[i],f[i]);
        if(1<=i+y&&i+y<=V)_max(g[i+y],f[i]+x);
    }
    for(int x=1;x<=V;x++)f[x]=g[x],g[x]-INF;
    return;
}

signed main(){
    m=read(),L=read();
    for(int i=0;i<=m*2;i++)a[i]=read();
    for(int i=0;i<m;i++)sum+=(i-m)*a[i],cnt+=a[i],b[i]=a[i];
    for(int i=1;i<=m;i++){
        if(sum+i<=L){
            int t=min((L-sum)/i,a[m+i]);
            sum+=t*i,cnt+=t,b[m+i]=t;
        }
    }
    for(int i=0;i<m;i++){
        if(sum-(i-m)<=L){
            int t=min((L-sum)/(-i+m),a[i]);
            sum+=t*(-i+m),cnt-=t,b[i]-=t;
        }
    }
    if(sum+m<L||sum-m>L){
        printf("impossible\n");
        return 0;
    }
    cnt+=a[m],b[m]=a[m];
    V=m*m*2+2,M=V/2;
    for(int i=1;i<=V;i++)f[i]=g[i]=-INF;
    f[sum-L+M]=0;
    for(int i=0,x;i<=m*2;i++)if(i!=m){
        x=a[i]-b[i];
        for(int j=1;j<=x;j*=2)upt(j,j*(i-m)),x-=j;
        upt(x,x*(i-m));
        x=b[i];
        for(int j=1;j<=x;j*=2)upt(-j,-j*(i-m)),x-=j;
        upt(-x,-x*(i-m));
    }
    if(f[M]>-INF/2)printf("%lld\n",cnt+f[M]);
    else printf("impossible\n");
    
    return 0;
}

