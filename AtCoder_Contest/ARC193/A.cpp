#include <bits/stdc++.h>
#define int long long
using namespace std;

const int N=1.01e6,inf=1e17;
int n,m,w[N],L[N],R[N],q,lm[N],rm[N]; 

signed main(){
    cin>>n;
    m=n*2+1;
    for(int i=1;i<=n;i++)cin>>w[i];
    for(int i=0;i<=m;i++)lm[i]=rm[i]=inf;
    for(int i=1;i<=n;i++){
        cin>>L[i]>>R[i];
        lm[R[i]]=min(lm[R[i]],w[i]);
        rm[L[i]]=min(rm[L[i]],w[i]);
    }
    for(int i=1;i<=m;i++)lm[i]=min(lm[i-1],lm[i]);
    for(int i=m-1;i>=0;i--)rm[i]=min(rm[i+1],rm[i]);
    cin>>q;
    while(q--){
        int s,t;
        cin>>s>>t;
        if(L[t]<L[s])swap(s,t);
        if(R[s]<L[t]){
            printf("%lld\n",w[s]+w[t]);
            continue;
        }
        else{
            int ans=lm[L[s]-1];
            ans=min(ans,rm[max(R[s],R[t])+1]);
            ans=min(ans,rm[R[s]+1]+lm[L[t]-1]);
            if(ans==inf)printf("-1\n");
            else printf("%lld\n",ans+w[s]+w[t]);
        }
    }
    return 0;
}


