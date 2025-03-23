#include <bits/stdc++.h>
#define int long long
using namespace std;

const int N=1.01e6;
int T,n,k,a[N];

signed main(){
    cin>>T;
    while(T--){
        cin>>n>>k;
        int mx=0;
        for(int i=1;i<=n;i++){
            cin>>a[i];
            if(i>1&&i<n)mx=max(mx,a[i]);
        }
        if(k==1){
            printf("%lld\n",max(mx+max(a[1],a[n]),a[1]+a[n]));
        }
        else{
            sort(a+1,a+n+1);
            int s=0;
            for(int i=n;i>=n-k;i--)s+=a[i];
            printf("%lld\n",s);
        }
    }
    return 0;
}


