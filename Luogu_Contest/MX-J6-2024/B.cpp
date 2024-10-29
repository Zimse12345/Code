#include <bits/stdc++.h>
#define int long long
using namespace std;

const int N=1.01e6;
int T,n,k,d;

signed main(){
    cin>>T;
    while(T--){
        cin>>n>>k>>d;
        int ans=0;
        if(d%2==0)ans=(n+1)*n/2;
        else ans=(n+(n%2))*((n+2)/2)/2;
        printf("%lld\n",ans);
    }
    return 0;
}


