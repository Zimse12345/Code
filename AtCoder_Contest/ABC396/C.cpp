#include <bits/stdc++.h>
#define int long long
using namespace std;

const int N=1.01e6;
int n,m,a[N],b[N],ans;

signed main(){
    cin>>n>>m;
    for(int i=1;i<=n;i++)cin>>a[i],a[i]=-a[i];
    sort(a+1,a+n+1);
    for(int i=1;i<=m;i++)cin>>b[i],b[i]=-b[i];
    sort(b+1,b+m+1);
    for(int i=1,s=0;i<=n;i++){
        s-=a[i];
        if(b[i]<0)s-=b[i];
        ans=max(ans,s);
    }
    printf("%lld\n",ans);
    return 0;
}


