#include <bits/stdc++.h>
using namespace std;

const int N=1.01e6;
int T,n,k; 

signed main(){
    cin>>T;
    while(T--){
        cin>>n>>k;
        int ans=0;
        if(k==1)ans=n;
        else while(n){
            ans+=n%k;
            n/=k;
        }
        printf("%d\n",ans);
    }
    return 0;
}


