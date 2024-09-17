#include <bits/stdc++.h>
#define int long long
using namespace std;

const int N=1.01e6,Mod=998244353;
int n,k,a[N],f[N],p[N],S;
map<int,int> F;

signed main(){
    cin>>n>>k;
    f[0]=1,F[0]=1,S=1;
    for(int i=1;i<=n;i++){
        cin>>a[i];
        p[i]=a[i]+p[i-1];
        f[i]=(S-F[p[i]-k]+Mod)%Mod;
        F[p[i]]=(F[p[i]]+f[i])%Mod;
        S=(S+f[i])%Mod;
    }
    printf("%lld\n",f[n]);
    return 0;
}


