#include <bits/stdc++.h>
#define int long long
using namespace std;

const int N=1.01e6;
int n,a[N],s,ans;

signed main(){
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>a[i];
        s+=a[i];
        ans-=a[i]*a[i];
    }
    ans=(ans+s*s)/2;
    printf("%lld\n",ans);
    return 0;
}


