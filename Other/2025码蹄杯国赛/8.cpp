#include <bits/stdc++.h>
#define int long long
using namespace std;

const int N=1.01e6,Mod=998244353;
int n,m,a,b,fac[N],ifac[N],p[N],ans;
char s[N];

inline int fpow(long long x,int y=Mod-2){int z=1;while(y){if(y&1)z=
x*z%Mod;x=x*x%Mod,y/=2;}return z;}

inline int C(int x,int y){
    return fac[x]*ifac[y]%Mod*ifac[x-y]%Mod;
}

signed main(){
    fac[0]=ifac[0]=1;
    for(int i=1;i<N;i++){
        fac[i]=fac[i-1]*i%Mod;
        ifac[i]=fpow(fac[i]);
    }
    cin>>n>>m;
    scanf("%s",s+1);
    for(int i=1;i<=n;i++){
        if(s[i]=='A')++a;
        if(s[i]=='B')++b;
    }
    p[0]=1;
    for(int i=1;i<=b;i++)p[i]=(p[i-1]+C(b,i))%Mod;
    for(int i=0;i<=a&&i<=m;i++){
        (ans+=fpow(2,i)*C(a,i)%Mod*p[min(m-i,b)])%=Mod;
    }
    printf("%lld\n",ans);
    return 0;
}


