#include <bits/stdc++.h>
#define int long long
using namespace std;

const int N=1.01e6,Mod=1000000007;
int T,n,m,k,p[N],v[5100][5100],f[N],inv[N],pp[N];

inline int fpow(long long x,int y=Mod-2){int z=1;
while(y){if(y&1)z=x*z%Mod;x=x*x%Mod,y/=2;}return z;}

signed main(){
    cin>>T;
    for(int i=1;i<=5000;i++){
        inv[i]=fpow(i);
        v[i][i]=inv[i];
        for(int j=i-1,s=(1-inv[i]);j>=1;j--){
            v[i][j]=s*inv[j]%Mod;
            (s*=(1-inv[j]))%=Mod;
        }
    }
    while(T--){
        cin>>n>>m>>k;
        for(int i=0;i<n;i++)f[i]=p[i]=pp[i]=0;
        p[0]=1;
        while(m){
            for(int i=0;i<n;i++){
                int j=i,rm=m,ni=(i+1)%n;
                while(rm){
                    int val=p[j]*v[m][rm]%Mod;
                    f[i]+=val,pp[ni]+=val;
//                    (f[i]+=p[j]*v[m][rm])%=Mod;
//                    printf("  + %lld %lld %lld\n",i,j,p[j]*v[m][rm]);
//                    (pp[(i+1)%n]+=p[j]*v[m][rm])%=Mod;
                    --j;
                    if(j<0)j=n-1;
                    --rm;
                }
            }
            --m;
            for(int i=0;i<n;i++)p[i]=pp[i]%Mod,f[i]%=Mod,pp[i]=0;
//            for(int i=0;i<n;i++)printf("%lld ",(f[i]+Mod)%Mod);
//            printf("   |   ");
//            for(int i=0;i<n;i++)printf("%lld ",(p[i]+Mod)%Mod);
//            printf("\n");
        }
        for(int i=0;i<n;i++)printf("%lld ",(f[i]+Mod)%Mod);
        printf("\n");
    }
    return 0;
}


