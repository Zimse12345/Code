#include <bits/stdc++.h>
using namespace std;

const int N=1.01e6;
int n,a[N],c[N],cc[N];

signed main(){
    cin>>n;
    long long cnt=0,ans=0;
    for(int i=1;i<=n;i++){
        cin>>a[i];
        if(!c[a[i]])++cnt;
        ++c[a[i]];
    }
    for(int i=n;i>=1;i--){
        --c[a[i]];
        if(!c[a[i]])--cnt;
        ++cc[a[i]];
        if(cc[a[i]]==2){
            ans+=cnt;
            if(c[a[i]])--ans;
        }
    }
    printf("%lld\n",ans);
    return 0;
}


