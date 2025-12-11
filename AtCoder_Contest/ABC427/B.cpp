#include <bits/stdc++.h>
#define int long long
using namespace std;

const int N=1.01e6;
int a[N],n;

signed main(){
    cin>>n;
    a[1]=1;
    for(int i=2;i<=n;i++){
        a[i]=a[i-1];
        while(a[i-1])a[i]+=a[i-1]%10,a[i-1]/=10;
    }
    printf("%lld\n",a[n]);
    return 0;
}


