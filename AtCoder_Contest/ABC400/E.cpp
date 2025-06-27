#include <bits/stdc++.h>
#define int long long
using namespace std;

const int N=1.01e6;
int prime[N],pr[N],pc;
int q,n,ans[N];

signed main(){
    for(int i=2;i<N;i++){
        if(!pr[i])pr[i]=i,prime[++pc]=i;
        for(int j=1;j<=pc&&i*prime[j]<N;j++){
            pr[i*prime[j]]=prime[j];
            if(pr[i]==prime[j])break;
        }
    }
    for(int i=6,x=6;i<N;i++){
        int p1=pr[i],k=i;
        while(pr[k]==p1)k/=p1;
        if(k==1){
            ans[i]=x*x;
            continue;
        }
        int p2=pr[k];
        while(pr[k]==p2)k/=p2;
        if(k==1)x=i;
        ans[i]=x*x;
    }
    cin>>q;
    while(q--){
        cin>>n;
        int v=floor(sqrt(n));
        while(v*v>n)--v;
        while((v+1)*(v+1)<=n)++v;
        printf("%lld\n",ans[v]);
    }
    return 0;
}


