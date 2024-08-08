#include <bits/stdc++.h>
#define int long long
using namespace std;

const int N=1.01e6,Mod=1000000007;
int T,n,k,a,b,ans,fac[N];

inline int fpow(long long x,int y=Mod-2){int z=1;while(y){if(y&1)z=x*z%Mod;x=x*x%Mod,y/=2;}return z;}

inline int C(int x,int y){
    if(x<y)return 0;
    return fac[x]*fpow(fac[y])%Mod*fpow(fac[x-y])%Mod;
}

signed main(){
    cin>>T;
    fac[0]=1;
    for(int i=1;i<N;i++)fac[i]=fac[i-1]*i%Mod;
    while(T--){
        cin>>n>>k;
        a=b=ans=0;
        for(int i=1,x;i<=n;i++){
            cin>>x;
            if(x)++a;
            else ++b;
        }
        for(int i=k/2+1;i<=k&&i<=a;i++){
            ans=(ans+C(a,i)*C(b,k-i))%Mod;
        }
        printf("%lld\n",ans);
    }
    return 0;
}


