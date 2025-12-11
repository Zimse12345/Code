#include <bits/stdc++.h>
#define int long long
using namespace std;

const int N=1.01e6;
int n,a[N],s[N];

signed main(){
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>a[i];
        if(i>2)s[i]=s[i-2];
        s[i]+=a[i];
    }
    int ans=s[n];
    for(int i=n-2;i>=1;i-=2){
        ans=max(ans,s[i]+s[n-1]-s[i-1]);
    }
    for(int i=n-1;i>=2;i-=2){
        ans=max(ans,s[i]+s[n]-s[i-1]);
    }
    printf("%lld\n",ans);
    return 0;
}


