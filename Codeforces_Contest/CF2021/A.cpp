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
        for(int i=1;i<n;i++)a[i+1]=(a[i]+a[i+1])/2;
        printf("%d\n",a[n]);
    }
    return 0;
}


