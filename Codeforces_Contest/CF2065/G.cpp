#include <bits/stdc++.h>
using namespace std;

const int N=2.01e5;
int T,n,a[N],pr[N],vis[N];
long long ans;

signed main(){
    cin>>T;
    for(int i=2;i<N;i++)if(!pr[i]){
        for(int j=i+i;j<N;j+=i)if(!pr[j])pr[j]=i;
    }
    pr[1]=1;
    while(T--){
        cin>>n;
        ans=0;
        for(int i=1;i<=n;i++)vis[i]=0;
        int cnt=0;
        for(int i=1;i<=n;i++){
            cin>>a[i];
            if(pr[a[i]]&&!pr[a[i]/pr[a[i]]])++vis[a[i]],ans+=vis[a[i]];
            if(!pr[a[i]]){
                vis[a[i]]++,++cnt;
                ans+=cnt-vis[a[i]];
            }
        }
        for(int i=1;i<=n;i++){
            if(pr[a[i]]&&!pr[a[i]/pr[a[i]]]){
                int x=pr[a[i]],y=a[i]/x;
                if(vis[x])ans+=vis[x];
                if(x!=y&&vis[y])ans+=vis[y];
            }
        }
        printf("%lld\n",ans);
    }
    return 0;
}


