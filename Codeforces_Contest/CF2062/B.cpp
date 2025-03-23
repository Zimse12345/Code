#include <bits/stdc++.h>
using namespace std;

const int N=1.01e6,inf=2e9;
int T,n,a[N];

signed main(){
    cin>>T;
    while(T--){
        cin>>n;
        int ans=1;
        for(int i=1;i<=n;i++){
            cin>>a[i];
            int t=max((i-1)*2,(n-i)*2);
            if(a[i]<=t)ans=0;
        }
        if(ans)printf("YES\n");
        else printf("NO\n");
    }
    return 0;
}


