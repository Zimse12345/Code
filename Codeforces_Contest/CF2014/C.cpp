#include <bits/stdc++.h>
#define int long long
using namespace std;

const int N=1.01e6;
int T,n,a[N];

bool ck(int x){
    int s=x;
    for(int i=1;i<=n;i++)s+=a[i];
    int cnt=0;
    for(int i=1;i<n;i++)if(a[i]*n*2<s)++cnt;
    return cnt*2>n;
}

signed main(){
    cin>>T;
    while(T--){
        cin>>n;
        for(int i=1;i<=n;i++)cin>>a[i];
        sort(a+1,a+n+1);
        int L=0,R=1e12,ans=-1;
        while(L<=R){
            int mid=(L+R)/2;
            if(ck(mid))ans=mid,R=mid-1;
            else L=mid+1;
        }
        printf("%lld\n",ans);
    }
    return 0;
}


