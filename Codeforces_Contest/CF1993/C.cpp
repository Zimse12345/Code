#include <bits/stdc++.h>
using namespace std;

const int N=1.01e6;
int T,n,k,a[N];

signed main(){
    cin>>T;
    while(T--){
        cin>>n>>k;
        for(int i=1;i<=n;i++)cin>>a[i];
        sort(a+1,a+n+1);
        int L=a[n],R=a[n]+k-1;
        for(int i=1;i<n;i++){
            a[i]+=(a[n]-a[i])/(2*k)*(2*k);
            if(a[i]+k-1<L)a[i]+=k*2;
            L=max(L,a[i]),R=min(R,a[i]+k-1);
        }
        if(L<=R)printf("%d\n",L);
        else printf("-1\n");
    }
    return 0;
}


