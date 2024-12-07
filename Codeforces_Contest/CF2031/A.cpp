#include <bits/stdc++.h>
using namespace std;

const int N=1.01e6;
int T,n,a[N],f[N];

signed main(){
    cin>>T;
    while(T--){
        cin>>n;
        int ans=0;
        for(int i=1;i<=n;i++){
            cin>>a[i];
            f[i]=1;
            for(int j=1;j<i;j++){
                if(a[j]<=a[i])f[i]=max(f[i],f[j]+1);
            }
            ans=max(ans,f[i]);
        }
        printf("%d\n",n-ans);
    }
    return 0;
}


