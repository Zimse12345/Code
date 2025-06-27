#include <bits/stdc++.h>
using namespace std;

const int N=1.01e6;
int n,a[N],k; 

signed main(){
    cin>>n;
    for(int i=1;i<=n;i++)cin>>a[i];
    cin>>k;
    int ans=0;
    for(int i=1;i<=n;i++)if(a[i]>=k)++ans;
    printf("%d\n",ans);
    return 0;
}


