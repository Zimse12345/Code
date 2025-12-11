#include <bits/stdc++.h>
#define int long long
using namespace std;

const int N=1.01e6,Mod=998244353;
int T,n,k,s[N],f[N][3];

signed main(){
    cin>>T;
    while(T--){
        cin>>n>>k;
        f[0][1]=1;
        for(int i=1;i<=n;i++){
            cin>>s[i];
            if(s[i]==1){
                f[i][0]=0;
                f[i][1]=(f[i-1][0]+f[i-1][1])%Mod;
                f[i][2]=(f[i-1][1]+f[i-1][2])%Mod; 
            }
            else{
                f[i][0]=(f[i-1][0]+f[i-1][1])%Mod;
                f[i][1]=(f[i-1][1]+f[i-1][2])%Mod;
                f[i][2]=0;
            }
        }
        printf("%lld\n",f[n][1]);
    }
    return 0;
}


