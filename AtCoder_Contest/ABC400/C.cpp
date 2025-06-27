#include <bits/stdc++.h>
#define int long long
using namespace std;

const int N=1.01e6;
int n,ans;

signed main(){
    cin>>n;
    n/=2;
    while(n){
        int v=floor(sqrt(n));
        while(v*v>n)--v;
        while((v+1)*(v+1)<=n)++v;
        ans+=(v+1)/2;
        n/=2;
    }
    printf("%lld\n",ans);
    return 0;
}


