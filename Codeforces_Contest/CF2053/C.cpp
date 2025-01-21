#include <bits/stdc++.h>
#define int long long
using namespace std;

const int N=1.01e6;
int T,n,k;

signed main(){
    cin>>T;
    while(T--){
        cin>>n>>k;
        int len=n,cnt=1,sum=0,ans=0;
        while(len>=k){
            if(len&1)ans+=sum+cnt*(len/2+1);
            sum=sum*2+cnt*((len+1)/2),cnt*=2,len/=2;
        }
        printf("%lld\n",ans);
    }
    return 0;
}


