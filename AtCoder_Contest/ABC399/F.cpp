#include <bits/stdc++.h>
#define int long long
using namespace std;

const int N=1.01e6,K=16,Mod=998244353;
int n,k,a[N],f[N][K],C[K][K],pa[K],ans;

signed main(){
    C[0][0]=1;
    for(int i=1;i<K;i++){
        C[i][0]=1;
        for(int j=1;j<=i;j++)C[i][j]=(C[i-1][j]+C[i-1][j-1])%Mod;
    }
    cin>>n>>k;
    for(int i=1;i<=n;i++){
        cin>>a[i];
        pa[0]=1;
        for(int j=1;j<=k;j++)pa[j]=(pa[j-1]*a[i])%Mod;
        for(int j=0;j<=k;j++){
            for(int p=0;p<=j;p++){
                (f[i][j]+=f[i-1][p]*pa[j-p]%Mod*C[j][p])%=Mod;
            }
        }
        for(int j=0;j<=k;j++)(f[i][j]+=pa[j])%=Mod;
        (ans+=f[i][k])%=Mod;
    }
    printf("%lld\n",ans);
    return 0;
}


