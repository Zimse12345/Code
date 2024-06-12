#include <bits/stdc++.h>
#define int long long
using namespace std;

const int N=1.01e6;
int n,x[N],sum[N],q; 

inline int calc(int p,int l,int r){
    return (x[p]*p-sum[p])*l+(sum[n]-sum[p]-x[p]*(n-p))*r;
}

signed main(){
    cin>>n;
    for(int i=1;i<=n;i++)cin>>x[i];
    sort(x+1,x+n+1);
    for(int i=1;i<=n;i++)sum[i]=sum[i-1]+x[i];
    cin>>q;
    while(q--){
        int l,r;
        cin>>l>>r;
        int x=max(1ll,n*r/(l+r));
        x=max(x,1ll);
        int ans=calc(x,l,r);
        if(x+1<=n)ans=min(ans,calc(x+1,l,r));
        printf("%lld\n",ans);
        for(int i=1;i<=n;i++)if(calc(i,l,r)<ans)printf("!!!!!!(%lld)\n",i);
    }
    return 0;
}


