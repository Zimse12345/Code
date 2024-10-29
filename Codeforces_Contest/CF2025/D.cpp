#include <bits/stdc++.h>
using namespace std;

const int N=2100000;
int n,m,a[N],f[N],x[N],y[N],K,ans;

signed main(){
    cin>>n>>m;
    for(int i=1;i<=n;i++)cin>>a[i];
    for(int i=1;i<=n;i++){
        if(a[i]>0)++x[a[i]];
        if(a[i]<0)++y[-a[i]];
        if((a[i]==0&&K<m*2)||i==n){
            for(int j=1;j<=K;j++)x[j]+=x[j-1],y[j]+=y[j-1];
            for(int j=0;j<=K;j++)f[j]+=x[j]+y[K-j];
            for(int j=K+1;j>0;j--)f[j]=max(f[j],f[j-1]);
            ++K;
            for(int j=1;j<=K;j++)x[j]=y[j]=0;
        }
    }
    for(int i=0;i<=K;i++)ans=max(ans,f[i]);
    printf("%d\n",ans);
    return 0;
}


