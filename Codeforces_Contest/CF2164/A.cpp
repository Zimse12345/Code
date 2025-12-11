#include <bits/stdc++.h>
using namespace std;

const int N=1.01e6,inf=1.01e9;
int T,n,a[N],k;

signed main(){
    cin>>T;
    while(T--){
        int mx=-inf,mn=inf;
        cin>>n;
        while(n--){
            int x=0;
            cin>>x;
            mx=max(mx,x);
            mn=min(mn,x);
        } 
        cin>>k;
        if(mn<=k&&k<=mx)printf("YES\n");
        else printf("NO\n");
    }
    return 0;
}


