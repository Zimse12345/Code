#include <bits/stdc++.h>
using namespace std;

const int N=1.01e6;
int T,n,a[N];

signed main(){
    cin>>T;
    while(T--){
        cin>>n;
        for(int i=1;i<=n;i++)cin>>a[i];
        for(int i=2;i<=n;i++){
            a[i]=a[i-1]+a[i]-1;
        }
        printf("%d\n",a[n]);
    }
    return 0;
}


