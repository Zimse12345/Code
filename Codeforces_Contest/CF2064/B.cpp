#include <bits/stdc++.h>
using namespace std;

const int N=1.01e6;
int T,n,a[N],vis[N];

signed main(){
    cin>>T;
    while(T--){
        cin>>n;
        for(int i=1;i<=n;i++)vis[i]=0;
        for(int i=1;i<=n;i++)cin>>a[i],++vis[a[i]];
        int ans=0,l=0,r=0;
        for(int i=1,s=0;i<=n;i++){
            if(vis[a[i]]==1)++s;
            else s=0;
            if(s>ans){
                ans=s,l=i-s+1,r=i;
            }
        }
        if(ans)printf("%d %d\n",l,r);
        else printf("0\n");
    }
    return 0;
}


