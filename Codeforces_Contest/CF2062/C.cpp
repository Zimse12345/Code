#include <bits/stdc++.h>
#define int long long
using namespace std;

const int N=1.01e6;
int T,n,a[N];

signed main(){
    cin>>T;
    while(T--){
        cin>>n;
        int ans=-2e18;
        for(int i=1;i<=n;i++)cin>>a[i];
        int _n=n;
        while(n>=1){
            int s=0;
            for(int i=1;i<=n;i++){
                s+=a[i];
                a[i]=a[i+1]-a[i];
            }
            ans=max(ans,s);
            if(n!=_n)ans=max(ans,-s);
            --n;
        }
        printf("%lld\n",ans);
    }
    return 0;
}


