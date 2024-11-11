#include <bits/stdc++.h>
#define int long long
using namespace std;

const int N=1.01e6;
int T,p2[62];

int calc(int x){
    int res=0;
    for(int i=0;i<=60;i++){
        int s=(x+1)/p2[i+1]*p2[i];
        if((x+1)%p2[i+1]>p2[i])s+=(x+1)%p2[i+1]-p2[i];
        if(s&1)res|=p2[i];
    }
    return res;
}

signed main(){
    p2[0]=1;
    for(int i=1;i<62;i++)p2[i]=p2[i-1]*2;
    cin>>T;
    while(T--){
        int l,r,p,k;
        cin>>l>>r>>p>>k;
        int ans=calc(r)^calc(l-1);
        ans^=(calc((r-k)/p2[p])^calc((l-1-k)/p2[p]))*p2[p];
        if(((r-k+p2[p])/p2[p]-(l-1-k+p2[p])/p2[p])&1)ans^=k;
        printf("%lld\n",ans);
    }
    return 0;
}


