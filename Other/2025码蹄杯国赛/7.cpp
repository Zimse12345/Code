#include <bits/stdc++.h>
#define int long long
using namespace std;

const int N=1.01e6,Mod=998244353;
int n,f[N],ans;
int pr[N],prime[N],cnt,d[N],mu[N];

int gcd(int x,int y){
    return y?gcd(y,x%y):x;
}

signed main(){
    scanf("%lld",&n);
    f[1]=f[2]=1;
    for(int i=3;i<=n;i++)f[i]=(f[i-1]+f[i-2])%Mod;
    
    for(int i=2;i<=n;i++){
        if(!pr[i]){
            prime[++cnt]=i;
            for(int j=i;j<=n;j+=i)if(!pr[j])pr[j]=i;
        }
    }
    for(int i=1;i<=n;i++){
        for(int j=i;j<=n;j+=i)++d[j];
    }
    for(int i=1;i<=n;i++)f[i]=(f[i]*d[i])%Mod;
    mu[1]=1;
    for(int i=2;i<=n;i++){
        if((i/pr[i])%pr[i]==0)mu[i]=0;
        else mu[i]=-mu[i/pr[i]];
    }
    
    for(int i=1;i<=n;i++){
        int m=n/i,s=0;
        for(int j=1;j<=m;j++)(s+=mu[j]*(m/j)*(m/j)*(m/j))%=Mod;
        (ans+=s*f[i])%=Mod;
    }
    (ans+=Mod)%=Mod;
    printf("%lld\n",ans);
    return 0;
}


