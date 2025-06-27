#include <bits/stdc++.h>
using namespace std;

const int N=1.01e6;
int T,n,k,l[N],r[N],a[N];

signed main(){
    cin>>T;
    while(T--){
        cin>>n>>k;
        for(int i=1;i<=n;i++)cin>>l[i];
        long long ans=0;
        for(int i=1;i<=n;i++){
            cin>>r[i];
            ans+=max(l[i],r[i]);
            a[i]=min(l[i],r[i]);
        }
        sort(a+1,a+n+1);
        for(int i=n;i>n-k+1;i--)ans+=a[i];
        ans+=1;
        printf("%lld\n",ans);
    }
    return 0;
}


