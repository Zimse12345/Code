#include <bits/stdc++.h>
using namespace std;

const int N=1.01e6;
int T,n,a[N];

signed main(){
    cin>>T;
    while(T--){
        cin>>n;
        int ans=0;
        for(int i=1,x=(1<<30)-1;i<=n;i++){
            cin>>a[i];
            x&=a[i];
            if(!x)++ans,x=(1<<30)-1;
        }
        if(ans==0)ans=1;
        printf("%d\n",ans);
    }
    return 0;
}


