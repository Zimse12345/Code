#include <bits/stdc++.h>
#define int long long
using namespace std;

const int N=1.01e6;
int T,n,a[N],l[N],r[N],v[N],t;

signed main(){
    cin>>T;
    while(T--){
        cin>>n;
        for(int i=1;i<=n;i++)cin>>a[i];
        for(int i=1;i*2<=n;i++)swap(a[i],a[n-i+1]);
        t=1,l[1]=r[1]=1,v[1]=a[1];
        v[0]=1e18;
        for(int i=2;i<=n;i++){
            while(t>1&&(r[t]-l[t]+1)*(v[t-1]-v[t])<=a[i]-v[t-1]){
                a[i]-=(r[t]-l[t]+1)*(v[t-1]-v[t]);
                --t,r[t]=r[t+1];
            }
            if(a[i]>v[t]){
                l[t+1]=l[t]+(a[i]-v[t])%(i-l[t]+1);
                if(l[t+1]==l[t])l[t+1]=i+1;
                r[t+1]=i;
                r[t]=l[t+1]-1;
                v[t]+=(a[i]-v[t]-1)/(i-l[t]+1)+1;
                v[t+1]=v[t]-1;
                ++t;
                if(r[t]<l[t])--t;
            }
            else{
                ++t;
                l[t]=r[t]=i;
                v[t]=a[i];
            }
        }
        printf("%lld\n",v[1]-v[t]);
    }
    return 0;
}


