#include <bits/stdc++.h>
#define int long long
using namespace std;

const int N=1.01e6;
int T,n,k,a[N];

signed main(){
    cin>>T;
    while(T--){
        cin>>n>>k;
        for(int i=1;i<=n;i++)cin>>a[i];
        sort(a+1,a+n+1);
        int p=1,t=k,s=0,ss=0;
        for(int i=1;i<=n;i++)ss+=a[i];
        for(int i=1;i<=n;i++){
            s+=a[i];
            if(i*a[i]-s<=t)p=i;
            else{
                s-=a[i];
                break;
            }
        }
        t-=p*a[p]-s;
        for(int i=1;i<=p;i++){
            if(i==n)continue;
            a[i]=a[p]+t/p;
            if(p-i<t%p)++a[i]; 
        }
        ss+=k;
        int ans=1;
        for(int i=2;i<=n;i++){
            if(ss%i<=k&&(ss-ss%i)/i>=a[n])ans=i;
        }
        printf("%lld\n",ans);
    }
    return 0;
}


