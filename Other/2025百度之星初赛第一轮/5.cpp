#include <bits/stdc++.h>
#define int long long
using namespace std;

const int N=2.01e6;
int T,n,a[N],p[N],vis[N];

signed main(){
    for(int i=1;i<=20;i++)p[(1<<i)-1]=1;
    cin>>T;
    while(T--){
        cin>>n;
        for(int i=1;i<=n;i++)cin>>a[i];
        int ans=1;
        for(int l=1,r;l<=n;){
            r=l;
            while(r<n&&a[r+1]==a[l])++r;
            if(vis[a[l]]||p[r-l+1]==0){
                ans=0;
                break;
            }
            vis[a[l]]=1;
            l=r+1;
        }
        
        if(ans)printf("Yes\n");
        else printf("No\n");
        for(int i=1;i<=n;i++)vis[a[i]]=0;
    }
    return 0;
}


