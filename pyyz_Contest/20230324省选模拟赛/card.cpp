/********************
*FileName:
*Author: Zimse
*Data: 2023-03-
*Description:
********************/

#include <bits/stdc++.h>
#define gc getchar
#define pc putchar
#define pb push_back
#define inv fpow
//#define int long long
//#define M ((L+R)/2)
//#define Lid (id<<1)
//#define Rid (Lid|1)

namespace Zimse{
const int INF=1000114514,Mod=998244353;//1000000007
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

const int N=405;

int n,m,T,C[N*2][N*2],f[N][N][N],g[N][N][N],ans,tmp[N];
char str[N];

int ff(int i,int j,int k){
    return (2ll*Mod+f[i][j][k]-f[i-1][j][k]-f[i][j+1][k]+f[i-1][j+1][k])%Mod;
}

int solve(int l,int r,int x,int y){
    if(r<l)swap(l,r);
    int res=0,sum=0;
    if(!x){
        for(int k=m;k>=0;k--){
            addmod(res,1ll*sum*(g[l+1][r-1][k]+(k==0))%Mod);
            addmod(sum,ff(l,r,k));
        }
    }
    else{
        memset(tmp,0,sizeof (int)*N);
        int t=1;
        if(l^r)t-=y;
        addmod(tmp[max(0,t)],1);
        for(int k=0;k<=m;k++)
            addmod(tmp[max(0,k+t)],f[l-1][r+1][k]);
        for(int k=m;k>=0;k--){
            addmod(res,1ll*sum*(g[l+1][r-1][k]+(k==0))%Mod);
            addmod(sum,tmp[k]);
        }
        res=(Mod-res)%Mod;
    }
    return res;
}

signed main(){
    C[0][0]=1;
    for(int i=1;i<N*2;i++){
        C[i][0]=1;
        for(int j=1;j<N*2;j++)C[i][j]=(C[i-1][j-1]+C[i-1][j])%Mod;
    }
    n=read(),m=(n+1)/2,T=read();
    scanf("%s",str+1);
    for(int i=1;i<=n;i++)str[i]-='0';
    for(int len=n;len>=1;len--){
        for(int i=1,j=i+len-1;j<=n;i++,j++){
            int t=1-str[i];
            if(i^j)t-=str[j];
            int *F=f[i][j];
            addmod(F[max(0,t)],1);
            for(int k=0;k<=m;k++)
                addmod(F[max(0,k+t)],f[i-1][j+1][k]);
            for(int k=0;k<=m;k++){
                addmod(ans,1ll*F[k]*k%Mod);
                addmod(F[k],(1ll*f[i][j+1][k]+f[i-1][j][k]-f[i-1][j+1][k]+Mod)%Mod);
            }
        }
    }
    for(int len=1;len<=n;len++){
        for(int i=1,j=i+len-1;j<=n;i++,j++){
            int t=str[i]-1;
            if(i^j)t+=str[j];
            int *G=g[i][j];
            addmod(G[max(0,t)],1);
            for(int k=0;k<=m;k++)
                addmod(G[max(0,k+t)],g[i+1][j-1][k]);
            for(int k=0;k<=m;k++)
                addmod(G[k],(1ll*g[i][j-1][k]+g[i+1][j][k]-g[i+1][j-1][k]+Mod)%Mod);
        }
    }
    ans=(Mod-ans)%Mod;
    for(int i=0;i<=n;i++)addmod(ans,1ll*C[n][i]*((i+1)/2)%Mod);
    _write(ans);
    if(!T)return 0;
    for(int i=1;i<=n;i++){
        int _ans=ans;
        for(int j=1;j<=n;j++)addmod(_ans,solve(i,j,str[i],str[j]));
        write_(_ans);
    }
    pc(10);
    return 0;
}
