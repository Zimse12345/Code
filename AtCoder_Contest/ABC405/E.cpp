#include <bits/stdc++.h>
#define int long long
using namespace std;

const int N=4.01e6,Mod=998244353;
int a,b,c,d,ans;
int fac[N],ifac[N];

inline int fpow(long long x,int y=Mod-2){int z=1;
while(y){if(y&1)z=x*z%Mod;x=x*x%Mod,y/=2;}return z;}

inline int C(int x,int y){
    return fac[x]*ifac[y]%Mod*ifac[x-y]%Mod;
}

signed main(){
    fac[0]=ifac[0]=1;
    for(int i=1;i<N;i++)fac[i]=fac[i-1]*i%Mod;
    ifac[N-1]=fpow(fac[N-1]);
    for(int i=N-2;i>=1;i--)ifac[i]=ifac[i+1]*(i+1)%Mod;
    
    cin>>a>>b>>c>>d;
    for(int i=0;i<=b;i++){
        (ans+=C(a+i,a)*C(b-i+c-1+d,b-i+d))%=Mod;
    }
    (ans+=C(a+b,a)*C(c+d-1,d-1))%=Mod;
    printf("%lld\n",ans);
    return 0;
}


