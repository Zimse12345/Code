#include <bits/stdc++.h>
#define int long long
using namespace std;

const int N=1.01e6;
int T,n,a[N],suf[N];

signed main(){
    cin>>T;
    while(T--){
        cin>>n;
        for(int i=1;i<=n;i++)cin>>a[i];
        suf[n+1]=0;
        for(int i=n,sum=0;i>=1;i--){
            sum+=a[i];
            suf[i]=max(suf[i+1],sum);
        }
        int x=0,mx=0,ans=0;
        for(int i=1;i<=n;i++){
            if(x+suf[i]>mx)mx=x+suf[i],ans=x;
            x+=a[i];
        }
        printf("%lld\n",ans);
    }
    return 0;
}



