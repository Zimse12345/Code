#include <bits/stdc++.h>
using namespace std;

const int N=1.01e6,Mod=998244353;
int n,a[N],p[N],f[N],prime[N],cnt;
int s[N],m,sf[N];

signed main(){
    p[1]=1;
    for(int i=2;i<N;i++){
        if(!p[i]){
            for(int j=i+i;j<N;j+=i)p[j]=1;
            prime[++cnt]=i;
        }
    }
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>a[i];
        m=0;
        for(int j=1;prime[j]*prime[j]<=a[i];j++){
            if(a[i]%prime[j]==0)s[m++]=prime[j];
            while(a[i]%prime[j]==0)a[i]/=prime[j];
        }
        if(!p[a[i]])s[m++]=a[i];
        if(i==1)f[1]=1;
        else{
            for(int j=1;j<(1<<m);j++){
                int mul=1,pc=-1;
                for(int k=0;k<m;k++)if(j&(1<<k)){
                    mul*=s[k];
                    pc*=-1;
                }
                (f[i]+=sf[mul]*pc)%=Mod;
            }
        }
        for(int j=1;j<(1<<m);j++){
            int mul=1,pc=-1;
            for(int k=0;k<m;k++)if(j&(1<<k)){
                mul*=s[k];
                pc*=-1;
            }
            (sf[mul]+=f[i])%=Mod;
        }
    }
    (f[n]+=Mod)%=Mod;
    printf("%d\n",f[n]);
    return 0;
}


