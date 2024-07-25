#include <bits/stdc++.h>
using namespace std;

const int N=1.01e6;
int T,n,k[N];

signed main(){
    cin>>T;
    while(T--){
        cin>>n;
        for(int i=1;i<=n;i++){
            cin>>k[i];
            for(int j=1,x=0;j<k[i];j++)cin>>x;
        }
        int ans=0;
        for(int i=20;i>=0;i--){
            int cnt=0;
            for(int j=1;j<=n;j++)if(k[j]&(1<<i))++cnt;
            if(cnt)ans+=(1<<i);
            if(cnt>1){
                ans+=(1<<i)-1;
                break;
            }
        }
        printf("%d\n",ans);
    }
    return 0;
}



