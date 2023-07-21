#include <bits/stdc++.h>
#define int long long
using namespace std;

const int N=1.01e6;
int n,k,a[N],b[N];

bool check(int t){
    int sum=0;
    for(int i=1;i<=n;i++)if(t<=a[i])sum+=b[i];
    return sum<=k;
}

signed main(){
    cin>>n>>k;
    for(int i=1;i<=n;i++)cin>>a[i]>>b[i];
    int L=1,R=1000000001,ans=1000000001;
    while(L<=R){
        int M=(L+R)/2;
        if(check(M))ans=M,R=M-1;
        else L=M+1;
    }
    printf("%lld\n",ans);
    return 0;
}


