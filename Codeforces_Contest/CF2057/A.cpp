#include <bits/stdc++.h>
#define int long long 
using namespace std;

const int N=1.01e6;
int T,n,m;

signed main(){
    cin>>T;
    while(T--){
        cin>>n>>m;
        n=max(n,m);
        printf("%lld\n",n+1);
    }
    return 0;
}


