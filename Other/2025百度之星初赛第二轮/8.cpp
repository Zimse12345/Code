#include <bits/stdc++.h>
#define int long long
using namespace std;

const int N=1.01e6,inf=1e18;
int T,n,x,y,a[N];

signed main(){
    cin>>T;
    while(T--){
        cin>>n>>x>>y;
        for(int i=1;i<=n;i++)cin>>a[i];
        sort(a+1,a+n+1);
        int ans=inf;
        for(int i=0;i<=n;i++)ans=min(ans,(n-i)*y+a[i]*x);
        int mx=0;
        for(int l=1,r=0;l<=n;){
            r=l;
            while(r<n&&a[r+1]==a[l])++r;
            mx=max(mx,r-l+1);
            l=r+1;
        }
        ans=min(ans,(n-mx)*y);
        printf("%lld\n",ans);
    }
    return 0;
}


