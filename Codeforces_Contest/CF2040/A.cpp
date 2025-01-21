#include <bits/stdc++.h>
using namespace std;

const int N=1.01e6;
int T,n,k,a[N]; 

signed main(){
    cin>>T;
    while(T--){
        cin>>n>>k;
        int ans=0;
        for(int i=1;i<=n;i++){
            cin>>a[i];
        }
        for(int i=1;i<=n;i++){
            int t=0;
            for(int j=1;j<=n;j++)if(i!=j){
                if((a[i]-a[j])%k==0)t=1;
            }
            if(t==0)ans=i;
        }
        if(ans)printf("YES\n%d\n",ans);
        else printf("NO\n");
    }
    return 0;
}


