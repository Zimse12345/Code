#include <bits/stdc++.h>
#define int long long
using namespace std;

const int N=1.01e6;
int T,n,m,a[N];

signed main(){
    cin>>T;
    while(T--){
        cin>>n>>m;
        for(int i=1;i<=m;i++)cin>>a[i];
        sort(a+1,a+m+1);
        int l=1,r=m+1,ans=0;
        for(int i=1;i<n;i++){
            //ai>=i,aj>=n-i 
            while(l<=m&&a[l]<i)++l;//[l,n]
            while(r>1&&a[r-1]>=n-i)--r;//[r,n]
            ans+=(m-l+1)*(m-r+1)-(m-max(l,r)+1);
        }
        printf("%lld\n",ans);
    }
    return 0;
}


