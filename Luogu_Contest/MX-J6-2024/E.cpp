#include <bits/stdc++.h>
using namespace std;

const int N=1.01e6;
int T,n,m,a[N],vis[N];

signed main(){
    cin>>T;
    while(T--){
        cin>>n>>m;
        int ans=1;
        for(int i=n;i>1;i--)if(n%i==0){
            if(n/m<=n/i&&m>=i){
                ans=i;
                break;
            }
        }
        for(int i=1;i<=n;i++)a[i]=vis[i]=0;
        int t=n;
        for(int i=m;i<=n;i+=m)a[i]=t,vis[t]=1,t-=ans;
        t=n;
        for(int i=1;i<=n;i++)if(!a[i]){
            while(vis[t])--t;
            a[i]=t,vis[t]=1;
        }
        for(int i=1;i<=n;i++)printf("%d ",a[i]);
        printf("\n");
    }
    return 0;
}


