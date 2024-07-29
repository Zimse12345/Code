#include <bits/stdc++.h>
#define int long long
using namespace std;

const int N=1.01e6;
int T,n,k,a[N],b[N];

int ck(int x){
    if(x==0)return 1000000000;
    int res=0;
    for(int i=1;i<=n;i++)if(a[i]>=x){
        res+=(a[i]-x)/b[i]+1;
    }
    return res;
}

signed main(){
    cin>>T;
    while(T--){
        cin>>n>>k;
        for(int i=1;i<=n;i++)cin>>a[i];
        for(int i=1;i<=n;i++)cin>>b[i];
        int L=1,R=1000000001,res=1000000001;
        while(L<=R){
            int M=(L+R)/2;
            if(ck(M)<=k)res=M,R=M-1;
            else L=M+1;
        }
        int ans=0;
        for(int i=1;i<=n;i++)if(a[i]>=res){
            int t=(a[i]-res)/b[i]+1;
            a[i]-=t*b[i],k-=t;
            ans+=a[i]*t+((t+1)*t/2)*b[i];
        }
        sort(a+1,a+n+1);
        for(int i=n;i>=max(1ll,n-k+1);i--)ans+=max(a[i],0ll);
        printf("%lld\n",ans);
    }
    return 0;
}


