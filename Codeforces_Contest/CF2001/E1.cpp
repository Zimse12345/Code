#include <bits/stdc++.h>
using namespace std;

const int N=1.01e6;
int T,n,k,p,f[512][512],p2[512],g[512][512];

signed main(){
    cin>>T;
    while(T--){
        cin>>n>>k>>p;
        p2[0]=1;
        for(int i=1;i<=n;i++)p2[i]=p2[i-1]*2%p;
        for(int i=0;i<=n;i++)for(int j=0;j<=k;j++)f[i][j]=g[i][j]=0;
        for(int i=0;i<=k;i++)f[1][i]=g[1][i]=1;
        for(int i=2;i<=n;i++){
            for(int j=0;j<=k;j++){
                for(int l=0;l<=j;l++)if(l!=j-l){
                    int x=min(l,j-l),y=max(l,j-l);
                    f[i][j]=(1ll*f[i-1][y]*g[i-1][x]%p+f[i][j])%p;
                }
                for(int l=0;l<=j;l++){
                    g[i][j]=(1ll*g[i-1][l]*g[i-1][j-l]%p+g[i][j])%p;
                }
                if(j){
                    f[i][j]=(f[i][j]+f[i][j-1])%p;
                    g[i][j]=(g[i][j]+g[i][j-1])%p;
                }
            }
        }
        printf("%d\n",f[n][k]);
    }
    return 0;
}


