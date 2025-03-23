#include <bits/stdc++.h>
#define int long long
using namespace std;

const int N=1.01e6,Mod=998244353;
int T,n,q,fac[N],ifac[N],ans[N],d[N],dd[N];
char s[N];

inline int fpow(long long x,int y=Mod-2){int z=1;
while(y){if(y&1)z=x*z%Mod;x=x*x%Mod,y/=2;}return z;}

int C(int x,int y){
	return fac[x]*ifac[y]%Mod*ifac[x-y]%Mod;
}

signed main(){
    fac[0]=ifac[0]=1;
	for(int i=1;i<N;i++)fac[i]=fac[i-1]*i%Mod,ifac[i]=fpow(fac[i]);
    cin>>T;
    while(T--){
        cin>>n>>q;
        scanf("%s",s+1);
        int z=0;
        for(int i=1;i<=n;i++){
            if(s[i]=='0')++z;
            ans[i]=d[i]=dd[i]=0;
        }
        ans[0]=d[0]=dd[0]=0;
        for(int i=0;i<=n;i++){
            (ans[0]+=C(n,i)*(i/2)%Mod*(i-i/2))%=Mod;
            if((i-n)&1){
                (d[1]-=C(n,i)*(i/2))%=Mod;
                (dd[3]+=C(n,i))%=Mod;
            }
            else{
                (d[1]-=C(n,i)*(i/2))%=Mod;
                (dd[2]+=C(n,i))%=Mod;
            }
        }
        for(int i=2;i<=n;i++)(dd[i]+=dd[i-2])%=Mod;
        for(int i=1;i<=n;i++)(d[i]+=dd[i]+d[i-1])%=Mod;
        for(int i=1;i<=n;i++)(ans[i]+=d[i]+ans[i-1])%=Mod;
        while(q--){
            int p=0;
            cin>>p;
            if(s[p]=='0')s[p]='1',--z;
            else s[p]='0',++z;
            printf("%lld\n",ans[z]);
        }
    }
    return 0;
}


