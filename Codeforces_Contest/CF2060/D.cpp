#include <bits/stdc++.h>
using namespace std;

const int N=1.01e6;
int T,n,a[N];

signed main(){
    cin>>T;
    while(T--){
        cin>>n;
        for(int i=1;i<=n;i++){
            cin>>a[i];
            if(a[i]>=a[i-1]){
                a[i]-=a[i-1];
                a[i-1]=0;
            }
        }
        int ans=1;
        for(int i=1;i<n;i++)if(a[i]>a[i+1])ans=0;
        if(ans)printf("YES\n");
        else printf("NO\n");
    }
    return 0;
}


