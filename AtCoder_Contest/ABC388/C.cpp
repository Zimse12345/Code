#include <bits/stdc++.h>
using namespace std;

const int N=1.01e6;
int n,a[N];
long long ans;

signed main(){
    cin>>n;
    for(int i=1;i<=n;i++)cin>>a[i];
    sort(a+1,a+n+1);
    for(int i=1,j=0;i<=n;i++){
        while(a[j+1]*2<=a[i])++j;
        ans+=j;
    }
    printf("%lld\n",ans);
    return 0;
}


