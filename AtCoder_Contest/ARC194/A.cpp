#include <bits/stdc++.h>
#define int long long
using namespace std;

const int N=1.01e6,inf=1e18;
int n,a[N],f[N][2];

signed main(){
    cin>>n;
    f[0][1]=-inf;
    for(int i=1;i<=n;i++){
        cin>>a[i];
        f[i][0]=f[i-1][1]-a[i-1];
        f[i][1]=max(f[i-1][0],f[i-1][1])+a[i];
    }
    printf("%lld\n",max(f[n][0],f[n][1]));
    return 0;
}


