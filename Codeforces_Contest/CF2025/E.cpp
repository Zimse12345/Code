#include <bits/stdc++.h>
using namespace std;

const int N=512,Mod=998244353;
int n,m,f[N][N],g[N][N],ans;

signed main(){
    cin>>n>>m;
    f[0][0]=1;
    for(int i=1;i<=m;i++){
        for(int j=0;j<=m;j++)if(f[i-1][j]){
            (f[i][j+1]+=f[i-1][j])%=Mod;
            if(j)(f[i][j-1]+=f[i-1][j])%=Mod;
        }
    }
    g[0][0]=1;
    for(int i=1;i<n;i++){
        for(int j=0;j<=m;j+=2){
            for(int k=0;k<=j;k+=2)(g[i][j]+=1ll*g[i-1][j-k]*f[m][k]%Mod)%=Mod;
        }
    }
    for(int i=0;i<=m;i+=2)(ans+=1ll*g[n-1][i]*f[m][i]%Mod)%=Mod;
    printf("%d\n",ans);
    return 0;
}


