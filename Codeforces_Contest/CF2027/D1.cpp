#include <bits/stdc++.h>
#define int long long
using namespace std;

const int N=1.01e6,inf=1e18;
int T,n,m,a[N],b[N],s[N];
vector<int> pre[N],f[N];

signed main(){
    cin>>T;
    while(T--){
        cin>>n>>m;
        for(int i=1;i<=n;i++){
            cin>>a[i],s[i]=s[i-1]+a[i];
            pre[i].resize(m+1);
        }
        for(int i=1;i<=m;i++){
            cin>>b[i];
            for(int j=1,p=1;j<=n;j++){
                while(p<=j&&s[j]-s[p-1]>b[i])++p;
                pre[j][i]=((s[j]-s[p-1]<=b[i])?p:-1);
            }
        }
        f[0].resize(m+1);
        for(int i=1;i<=n;i++){
            f[i].resize(m+1);
            f[i][0]=inf;
            for(int j=1;j<=m;j++){
                f[i][j]=f[i][j-1];
                if(pre[i][j]>0)f[i][j]=min(f[i][j],f[pre[i][j]-1][j]+(m-j));
            }
        }
        if(f[n][m]==inf)f[n][m]=-1;
        printf("%lld\n",f[n][m]);
    }
    return 0;
}


