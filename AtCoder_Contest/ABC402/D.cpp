#include <bits/stdc++.h>
#define int long long
using namespace std;

const int N=1.01e6;
int n,m,a[N],ans;

signed main(){
    cin>>n>>m;
    ans=m*(m-1)/2;
    for(int i=1,l,r;i<=m;i++){
        cin>>l>>r;
        ++a[(l+r)%n];
    }
    for(int i=0;i<n;i++)ans-=a[i]*(a[i]-1)/2;
    printf("%lld\n",ans);
    return 0;
}


