#include <bits/stdc++.h>
#define int long long
using namespace std;

const int N=1.01e6;
int T,n,a[N],x[N],y[N];

signed main(){
    cin>>T;
    while(T--){
        cin>>n;
        for(int i=1;i<=n;i++){
            cin>>a[i];
            x[i]=x[i-1];
            if(a[i]>0)x[i]+=a[i];
        }
        y[n+1]=0;
        int ans=x[n];
        for(int i=n;i>=1;i--){
            y[i]=y[i+1];
            if(a[i]<0)y[i]-=a[i];
            ans=max(ans,x[i-1]+y[i]);
        }
        printf("%lld\n",ans);
    }
    return 0;
}


