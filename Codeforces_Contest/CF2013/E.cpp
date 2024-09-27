#include <bits/stdc++.h>
#define int long long
using namespace std;

const int N=1.01e6;
int T,n,a[N];

inline int gcd(int x,int y){
    return y?gcd(y,x%y):x;
}

signed main(){
    cin>>T;
    while(T--){
        cin>>n;
        int G=0;
        for(int i=1;i<=n;i++)cin>>a[i],G=gcd(a[i],G);
        sort(a+1,a+n+1);
        int ans=a[1],g=a[1],rm=n-1;
        a[1]=0;
        while(g!=G){
            int mn=1e9,p=0;
            for(int i=1;i<=n;i++)if(a[i]&&gcd(a[i],g)<mn)mn=gcd(a[i],g),p=i;
            ans+=mn,g=mn,--rm,a[p]=0;
        }
        ans+=g*rm;
        printf("%lld\n",ans);
    }
    return 0;
}


