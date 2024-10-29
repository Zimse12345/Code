#include <bits/stdc++.h>
using namespace std;

const int N=1.01e6;
int T,n,a[N]; 

signed main(){
    cin>>T;
    while(T--){
        cin>>n;
        int ans=0;
        for(int i=1;i<=n;i++){
            cin>>a[i];
            ans=max(ans,a[i]+(i-1)/2+(n-i)/2+1);
        }
        printf("%d\n",ans);
    }
    return 0;
}


