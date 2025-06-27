#include <bits/stdc++.h>
#define int long long
using namespace std;

const int N=1.01e6,Mod=998244353;
int T,n,k,f[64][64][2],g[64][64][2];

signed main(){
    cin>>T;
    while(T--){
        for(int i=0;i<64;i++){
            for(int j=0;j<64;j++){
                f[i][j][0]=f[i][j][1]=0;
                g[i][j][0]=g[i][j][1]=0;
            }
        }
        cin>>n>>k;
        f[61][0][1]=1;
        for(int i=60;i>=0;i--){
            int d=(1ll<<i),dm=d%Mod;
            for(int j=0;j<=k;j++)if(f[i+1][j][0]||f[i+1][j][1]){
                int f0=f[i+1][j][0],f1=f[i+1][j][1];
                int g0=g[i+1][j][0],g1=g[i+1][j][1];
                if(n&d){
                    (f[i][j+1][1]+=f1)%=Mod;
                    (g[i][j+1][1]+=g1+f1*dm)%=Mod;
                    
                    (f[i][j+1][0]+=f0)%=Mod;
                    (g[i][j+1][0]+=g0+f0*dm)%=Mod;
                    
                    (f[i][j][0]+=f0+f1)%=Mod;
                    (g[i][j][0]+=g0+g1)%=Mod;
                }
                else{
                    (f[i][j+1][0]+=f0)%=Mod;
                    (g[i][j+1][0]+=g0+f0*dm)%=Mod;
                    
                    (f[i][j][1]+=f1)%=Mod;
                    (g[i][j][1]+=g1)%=Mod;
                    
                    (f[i][j][0]+=f0)%=Mod;
                    (g[i][j][0]+=g0)%=Mod;
                }
            }
        }
        printf("%lld\n",(g[0][k][0]+g[0][k][1])%Mod);
    }
    return 0;
}


