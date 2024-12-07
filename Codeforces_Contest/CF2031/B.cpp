#include <bits/stdc++.h>
using namespace std;

const int N=1.01e6;
int T,n,a[N],f[N];

signed main(){
    cin>>T;
    while(T--){
        cin>>n;
        for(int i=1;i<=n;i++)cin>>a[i];
        for(int i=1;i<n;i++)if(a[i]-a[i+1]==1)swap(a[i],a[i+1]);
        for(int i=1;i<n;i++)if(a[i]-a[i+1]==1)swap(a[i],a[i+1]);
        int tag=1;
        for(int i=1;i<=n;i++)if(a[i]!=i)tag=0;
        if(tag)printf("YES\n");
        else printf("NO\n");
    }
    return 0;
}


