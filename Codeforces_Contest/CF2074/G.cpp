#include <bits/stdc++.h>
#define int long long
using namespace std;

const int N=1024;
int T,n,a[N],f[N][N],vis[N][N];

int dp(int l,int r){
    if(r-l+1<3)return 0;
    if(vis[l][r]++)return f[l][r];
    for(int i=l+1;i<r;i++){
        f[l][r]=max(f[l][r],a[l]*a[i]*a[r]+dp(l+1,i-1)+dp(i+1,r-1));
        f[l][r]=max(f[l][r],dp(l,i)+dp(i+1,r));
    }
    f[l][r]=max(f[l][r],max(dp(l+1,r),dp(l,r-1)));
    return f[l][r];
}

signed main(){
    cin>>T;
    while(T--){
        cin>>n;
        for(int i=1;i<=n;i++)cin>>a[i],a[i+n]=a[i];
        for(int i=1;i<=n*2;i++)for(int j=1;j<=n*2;j++)f[i][j]=vis[i][j]=0;
        dp(1,n*2);
        int ans=0;
        for(int i=1;i<=n;i++)ans=max(ans,f[i][i+n-1]);
        printf("%lld\n",ans);
    }
    return 0;
}


