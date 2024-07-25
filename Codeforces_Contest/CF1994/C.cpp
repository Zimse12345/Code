#include <bits/stdc++.h>
#define int long long
using namespace std;

const int N=1.01e6;
int T,n,x,a[N],s[N],c[N];

signed main(){
    cin>>T;
    while(T--){
        cin>>n>>x;
        for(int i=1;i<=n;i++)cin>>a[i],s[i]=s[i-1]+a[i];
        int ans=n*(n+1)/2;
        for(int i=1,l=-1;i<=n;i++){
            c[i]=0;
            while(s[i]-s[l+1]>x){
                ++l;
                c[i]+=c[l]+1;
            }
            ans-=c[i];
        }
        printf("%lld\n",ans);
    }
    return 0;
}



