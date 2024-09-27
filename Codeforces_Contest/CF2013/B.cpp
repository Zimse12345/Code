#include <bits/stdc++.h>
using namespace std;

const int N=1.01e6;
int T,n,a[N];

signed main(){
    cin>>T;
    while(T--){
        cin>>n;
        long long s=0;
        for(int i=1;i<=n;i++){
            cin>>a[i];
            if(i==n)s+=a[i];
            else if(i==n-1)s-=a[i];
            else s+=a[i];
        }
        printf("%lld\n",s);
    }
    return 0;
}


