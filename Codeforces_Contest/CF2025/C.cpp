#include <bits/stdc++.h>
using namespace std;

const int N=1.01e6;
int T,n,k,a[N];

signed main(){
    cin>>T;
    while(T--){
        cin>>n>>k;
        int l=1,ans=1,cnt=0;
        for(int i=1;i<=n;i++)cin>>a[i];
        sort(a+1,a+n+1);
        for(int i=1;i<=n;i++){
            if(a[i]>a[i-1]+1){
                l=i;
                cnt=1;
                continue;
            }
            if(a[i]!=a[i-1])++cnt;
            while(cnt>k){
                if(a[l]!=a[l+1])--cnt;
                ++l;
            }
            ans=max(ans,i-l+1);
        }
        printf("%d\n",ans);
    }
    return 0;
}


