#include <bits/stdc++.h>
#define int long long
using namespace std;

const int N=1.01e6;
int T,n,s,t;

signed main(){
    cin>>T;
    while(T--){
        cin>>n>>s>>t;
        int m=(1ll<<n)-1;
        if(s==t){
            printf("0\n");
            continue;
        }
        if((s|t)==m){
            printf("%lld\n",s^t);
            continue;
        }
        int x=m;
        int ans=(s^x);
        s=x;
        printf("%lld\n",ans+(s^t));
    }
    return 0;
}


