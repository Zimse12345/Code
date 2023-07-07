#include <bits/stdc++.h>
using namespace std;

const int N=1.01e6;
int T,n,k,a[N]; 

signed main(){
    cin>>T;
    while(T--){
        cin>>n>>k;
        for(int i=1;i<=n;i++)cin>>a[i];
        for(int i=1;i<n;i++)a[i]=(a[i]>a[i+1]?a[i]-a[i+1]:a[i+1]-a[i]);
        --n;
        sort(a+1,a+n+1);
        int ans=0;
        for(int i=1;i<=n+1-k;i++)ans+=a[i];
        printf("%d\n",ans);
    }
    return 0;
}


