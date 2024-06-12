#include <bits/stdc++.h>
#define int long long
using namespace std;

const int N=1.01e6;
int n,k,a[N],b[N],ans,pos[N],t[N],vis[N];

void check(){
    for(int i=0;i<=n;i++)pos[i]=t[i]=0;
    for(int i=1;i<=k;i++)pos[a[i]]=i;
    for(int i=1;i<=k;i++)if(pos[b[i]])++t[(i-pos[b[i]]+k)%k];
    for(int i=0;i<k;i++)ans=max(ans,t[i]);
    return;
}

signed main(){
    cin>>n>>k;
    for(int i=1;i<=k;i++)cin>>a[i],vis[a[i]]=1;
    for(int i=1;i<=k;i++)cin>>b[i],vis[b[i]]=1;
    check();
    for(int i=1;i<=k/2;i++)swap(a[i],a[k-i+1]);
    check();
    for(int i=1;i<=n;i++)if(!vis[i])++ans;
    printf("%lld\n",ans);
    return 0;
}


