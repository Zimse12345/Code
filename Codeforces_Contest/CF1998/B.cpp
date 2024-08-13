#include <bits/stdc++.h>
using namespace std;

const int N=1.01e6;
int T,n,a[N];

signed main(){
    cin>>T;
    while(T--){
        cin>>n;
        for(int i=1;i<=n;i++)cin>>a[i];
        for(int i=2;i<=n;i++)printf("%d ",a[i]);
        printf("%d\n",a[1]);
    }
    return 0;
}


