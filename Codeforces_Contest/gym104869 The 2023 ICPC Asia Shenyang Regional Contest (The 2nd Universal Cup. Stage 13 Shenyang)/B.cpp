// Author:Zimse  Data:2024-08-
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

const int N=64,inf=1.1e18;
int n,k,f[N][N][2],pre,ans[N],vis[N],sum,C[N][N],g[N];

inline void ad(int &x,int y){
    x=min(inf,x+y);
    return;
}

inline void mul(int &x,int y){
    if(x){
        if(inf/x<y)x=inf;
        else x*=y;
    }
    return;
}

inline int ck(int t){
    int res=0;
    int p=n+1,s=0,m=1,rm=n-t;
    for(int i=1;i<=n;i++){
        if(vis[i]){
            if((i&1)&&p<vis[i]){
                m=0;
                break;
            }
            if(((i+1)&1)&&p>vis[i]){
                m=0;
                break;
            }
            if(s){
                if((s&1)||s==i-1)mul(m,C[rm][s]),mul(m,g[s]),rm-=s;
                else{
                    m=0;
                    break;
                }
            }
            p=vis[i],s=0;
        }
        else{
            if((i&1)&&p<=t){
                m=0;
                break;
            }
            p=n+1,s++;
        }
    }
    mul(m,g[s]);
    ad(res,m);

    p=0,s=0,m=1,rm=n-t;
    for(int i=1;i<=n;i++){
        if(vis[i]){
            if(((i+1)&1)&&p<vis[i]){
                m=0;
                break;
            }
            if((i&1)&&p>vis[i]){
                m=0;
                break;
            }
            if(s){
                if(s&1)mul(m,C[rm][s]),mul(m,g[s]),rm-=s;
                else{
                    m=0;
                    break;
                }
            }
            p=vis[i],s=0;
        }
        else{
            if(((i+1)&1)&&p<=t){
                m=0;
                break;
            }
            p=n+1,s++;
        }
    }
    mul(m,g[s]);
    ad(res,m);
    return res;
}

signed main(){
    C[0][0]=1;
    for(int i=1;i<N;i++){
        C[i][0]=1;
        for(int j=1;j<=i;j++)C[i][j]=min(inf,C[i-1][j]+C[i-1][j-1]);
    }

    n=read(),k=read();
    g[0]=1;
    f[1][1][0]=f[1][1][1]=1,g[1]=1;
    f[2][2][0]=f[2][1][1]=1,g[2]=1;
    for(int i=2;i<n;i++){
        for(int j=1;j<=i;j++){
            int t=(i&1);
            for(int k=1;k<=j;k++)ad(f[i+1][k][t],f[i][j][t]);
            for(int k=j+1;k<=i+1;k++)ad(f[i+1][k][t^1],f[i][j][t^1]);
        }
        for(int j=1;j<=i+1;j++)ad(g[i+1],f[i+1][j][0]);
    }
    if(ck(0)<k){
        printf("-1\n");
        return 0;
    }
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++)if(!vis[j]){
            ans[i]=j,vis[j]=i;
            int x=ck(i);
            if(pre+x<k)pre+=x,vis[j]=0;
            else break;
        }
    }
    for(int i=1;i<=n;i++)printf("%lld ",ans[i]);
    printf("\n");
    return 0;
}

