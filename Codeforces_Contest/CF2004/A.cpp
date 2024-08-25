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
        if(n==1||(n==2&&a[1]+1<a[2]))printf("YES\n");
        else printf("NO\n");
    }
    return 0;
}


