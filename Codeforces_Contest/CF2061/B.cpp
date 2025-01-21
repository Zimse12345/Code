#include <bits/stdc++.h>
using namespace std;

const int N=1.01e6;
int T,n,a[N];

signed main(){
    cin>>T;
    while(T--){
        cin>>n;
        for(int i=1;i<=n;i++)cin>>a[i];
        sort(a+1,a+n+1);
        int x=0;
        for(int i=n-1;i>=1;i--)if(a[i]==a[i+1]){
            x=a[i];
            a[i]=1e9;
            a[i+1]=-1e9;
            break;
        }
        if(!x){
            printf("-1\n");
            continue;
        }
        int ans=0;
        sort(a+1,a+n+1);
        for(int i=2;i+1<n;i++){
            if(a[i]+x*2>a[i+1]){
                printf("%d %d %d %d\n",x,x,a[i],a[i+1]);
                ans=1;
                break;
            }
        }
        if(!ans)printf("-1\n");
        
    }
    return 0;
}


