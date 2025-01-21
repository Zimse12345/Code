#include <bits/stdc++.h>
using namespace std;

const int N=1.01e6;
int n,d,a[N],b[N];

signed main(){
    cin>>n>>d;
    for(int i=1;i<=n;i++){
        cin>>a[i]>>b[i];
    }
    for(int i=1;i<=d;i++){
        int ans=0;
        for(int j=1;j<=n;j++){
            ++b[j];
            ans=max(ans,b[j]*a[j]); 
        }
        printf("%d\n",ans);
    }
    return 0;
}


