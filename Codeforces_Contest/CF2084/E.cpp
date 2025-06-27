#include <bits/stdc++.h>
#define int long long
using namespace std;

const int N=5100,mod=1000000007;
int T,n,a[N],p[N],A[N][N],f[N],pre[N];

void add(int l1,int r1,int l2,int r2,int x){
    for(int i=l1;i<=r1;i++){
        for(int j=max(i,l2);j<=r2;j++){
            f[pre[j]-pre[i-1]]+=x;
//            printf("+%lld\n",pre[j]-pre[i-1]);
        }
    }
    return;
}

signed main(){
    A[0][0]=1;
    for(int i=1;i<N;i++){
        A[i][0]=1;
        for(int j=1;j<=i;j++)A[i][j]=(A[i][j-1]*(i-j+1))%mod;
    }
    cin>>T;
    while(T--){
        cin>>n;
        for(int i=0;i<=n;i++)p[i]=f[i]=pre[i]=0;
        int z=0;
        for(int i=1;i<=n;i++){
            cin>>a[i];
            pre[i]=pre[i-1];
            if(a[i]>=0)p[a[i]]=i;
            else ++pre[i],++z;
        }
        add(1,n,1,n,1);
        int m=0,ans=0;
        while(!p[m]&&m<n){
            for(int i=0;i<=n;i++)(ans+=f[i]*A[i][m+1]%mod*A[z-m-1][z-m-1])%=mod;//printf("m=%lld %lld*%lld\n",m,f[i],A[i][m]);
            ++m;
        }
        int l=p[m],r=p[m],e=m;
        add(1,l-1,1,l-1,-1),add(r+1,n,r+1,n,-1);
        while(m<n){
            if(p[m]){
                if(p[m]<l){
                    add(p[m]+1,l,r,n,-1);
                    l=p[m];
                }
                if(p[m]>r){
                    add(1,l,r,p[m]-1,-1);
                    r=p[m];
                }
            }
            else{
                ++e;
            }
            for(int i=0;i<=n;i++)(ans+=f[i]*A[i][e]%mod*A[z-e][z-e])%=mod;//printf("m=%lld %lld*%lld\n",m,f[i],A[i][e]);
            ++m;
        }
        printf("%lld\n",ans);
    }
    return 0;
}


