#include <bits/stdc++.h>
#define int long long
using namespace std;

const int N=1.01e2,Mod=1000000007;
int T,n,c,m,f[N][N*N],fac[N*N],ifac[N*N];

inline int fpow(long long x,int y=Mod-2){int z=1;
while(y){if(y&1)z=x*z%Mod;x=x*x%Mod,y/=2;}return z;}

inline int C(int x,int y){
    return fac[x]*ifac[y]%Mod*ifac[x-y]%Mod;
}

signed main(){
    fac[0]=ifac[0]=1;
    for(int i=1;i<N*N;i++)fac[i]=fac[i-1]*i%Mod,ifac[i]=fpow(fac[i]);
    cin>>T;
    while(T--){
        cin>>n>>c>>m;
        for(int i=1,a=0;i<=m;i++){
            cin>>a;
        }
        for(int i=0;i<=n;i++){
            for(int j=0;j<=m;j++)f[i][j]=0;
        }
        f[n][c]=1;
        for(int i=n-1;i>=1;i--){
            for(int j=0;j<=m;j++)if(f[i+1][j]){
                for(int k=0;k<=c&&j+k<=m;k++){
                    int w=min(c-k,j)+1;
                    (f[i][j+k]+=f[i+1][j]*C(k+w-1,w-1)%Mod)%=Mod;
                }
            }
        }
        printf("%lld\n",f[1][m]);
    }
    return 0;
}


