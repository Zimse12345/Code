#include <bits/stdc++.h>
using namespace std;

const int N=1.01e6;
int T,n,a[N]; 

signed main(){
    cin>>T;
    while(T--){
        cin>>n;
        for(int i=1;i<=n;i++)cin>>a[i];
        sort(a+1,a+n+1);
        int ans=0;
        for(int l=1,r=2;r<=n;r++){
            while(a[l]+a[l+1]<=a[r])++l;
            ans=max(ans,r-l+1);
        }
        printf("%d\n",n-ans);
    }
    return 0;
}


