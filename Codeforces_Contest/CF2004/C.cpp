#include <bits/stdc++.h>
#define int long long
using namespace std;

const int N=1.01e6;
int T,n,k,a[N],ans;

signed main(){
    cin>>T;
    while(T--){
        cin>>n>>k;
        ans=0;
        for(int i=1;i<=n;i++)cin>>a[i];
        sort(a+1,a+n+1);
        for(int i=n-1;i>=1;i-=2){
            int t=min(k,a[i+1]-a[i]);
            a[i]+=t,k-=t;
            if(!k)k=0;
        }
        for(int i=n;i>=1;i--){
            if((n-i)&1)ans-=a[i];
            else ans+=a[i];
        }
        printf("%lld\n",ans);
    }
    return 0;
}


