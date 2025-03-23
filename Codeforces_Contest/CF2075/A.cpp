#include <bits/stdc++.h>
using namespace std;

const int N=1.01e6;
int T,n,k; 

signed main(){
    cin>>T;
    while(T--){
        cin>>n>>k;
        int ans=0;
        if(n&1)n-=min(n,k),++ans;
        ans+=n/(k-1);
        if(n%(k-1))++ans;
        printf("%d\n",ans);
    }
    return 0;
}


