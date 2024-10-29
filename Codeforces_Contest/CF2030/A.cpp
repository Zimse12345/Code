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
        printf("%d\n",(a[n]-a[1])*(n-1));
    }
    return 0;
}


