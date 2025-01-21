#include <bits/stdc++.h>
using namespace std;

const int N=1.01e6;
int n,k;
long long a[N],ans,x;

inline void dfs(int p,int cnt){
    if(cnt==k){
        ans=max(ans,x);
        return;
    }
    if(cnt==k-1){
        for(int i=p+1;i<=n;i++)ans=max(ans,x^a[i]);
        return;
    }
    for(int i=p+1;i<=n-(k-cnt-1);i++){
        x^=a[i];
        dfs(i,cnt+1);
        x^=a[i];
    }
    return;
}

signed main(){
    cin>>n>>k;
    for(int i=1;i<=n;i++)cin>>a[i];
    if(n-k<k){
        for(int i=1;i<=n;i++)x^=a[i];
        k=n-k;
    }
    k=min(k,61);
    dfs(0,0);
    printf("%lld\n",ans);
    return 0;
}


