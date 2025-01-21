#include <bits/stdc++.h>
#define int long long
using namespace std;

const int N=1.01e6;
int T,n,k,L,a[N];

signed main(){
    cin>>T;
    while(T--){
        cin>>n>>k>>L;
        k*=2,L*=2;
        int t=0,p=0,ans=1e18;
        for(int i=1;i<=n;i++){
            cin>>a[i];
            a[i]*=2;
            if(i==1){
                t=a[i],p=0;
                ans=min(ans,t+max(0ll,L-(p+k)));
                continue;
            }
            if(a[i]<=p+k){
                p=min(a[i]+t,p+k);
            }
            else{
                if(a[i]-t>p+k){
                    t+=((a[i]-t)-(p+k))/2;
                    p=a[i]-t;
                }
                else p+=k;
            }
            ans=min(ans,t+max(0ll,L-(p+k)));
        }
        printf("%lld\n",ans);
    }
    return 0;
}


