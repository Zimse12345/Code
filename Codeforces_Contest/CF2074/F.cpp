#include <bits/stdc++.h>
#define int long long
using namespace std;

const int N=1.01e6;
int T,l1,r1,l2,r2;

inline int c(int l,int r,int d){
    return max(0ll,r/d-(l+d-1)/d);
}

signed main(){
    cin>>T;
    while(T--){
        cin>>l1>>r1>>l2>>r2;
        int ans=0;
        for(int i=0;i<=20;i++){
            int k=c(l1,r1,(1<<i))*c(l2,r2,(1<<i));
            if(i==0)ans+=k;
            else ans-=k*3;
        }
        printf("%lld\n",ans);
    }
    return 0;
}


