#include <bits/stdc++.h>
#define int long long
using namespace std;

const int N=1.01e6,mod=998244353;
int T,n,a[N],t[N],fac[N],ifac[N],p2[N],f[N],suf1[N],suf2[N];

inline int fpow(long long x,int y=mod-2){
int z=1;while(y){if(y&1)z=x*z%mod;x=x*x%mod,y/=2;}return z;}

int C(int x,int y){
    return fac[x]*ifac[y]%mod*ifac[x-y]%mod;
}

signed main(){
    cin>>T;
    fac[0]=ifac[0]=p2[0]=1;
    for(int i=1;i<N;i++){
        fac[i]=fac[i-1]*i%mod;
        ifac[i]=fpow(fac[i]);
        p2[i]=p2[i-1]*2%mod;
    }
    while(T--){
        cin>>n;
        for(int i=0;i<=n;i++){
            t[i]=0;
            f[i]=0;
        }
        for(int i=1;i<=n;i++){
            cin>>a[i],++t[a[i]];
        }
        int mx=n,ans=0,pre=0;
        f[mx]=1;
        for(int i=0;i<=n;i++){
            pre+=t[i];
            suf1[mx+1]=0;
            for(int x=mx;x>=0;x--)suf1[x]=(suf1[x+1]+f[x])%mod;
            suf2[t[i]+1]=0;
            for(int x=t[i];x>=0;x--)suf2[x]=(suf2[x+1]+C(t[i],x))%mod;
            for(int x=1;x<=min(t[i],mx);x++){
                f[x]=(f[x]*suf2[x]+C(t[i],x)*suf1[x+1])%mod;
                ans=(ans+f[x]*p2[n-pre]%mod*x)%mod;
            }
            mx=min(mx,t[i]);
        }
        printf("%lld\n",ans);
    }
    return 0;
}


