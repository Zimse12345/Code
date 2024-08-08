#include <bits/stdc++.h>
using namespace std;

const int N=1.01e6;
int T,n,k,a[N],f[N];

bool ck(int x){
    int t=n%k;
    if(!t)t=k;
    for(int i=1;i<=n;i++){
        if((i-1)%k==k-1&&t==k&&f[i-1]+(a[i]>=x?1:0)>=t/2+1)return true;
        if((i-1)%k<t&&(i-1)%k!=k-1)f[i]=f[i-1]+(a[i]>=x?1:0);
        else f[i]=-n;
        if(i-k>=0)f[i]=max(f[i],f[i-k]);
        if(f[i]>=t/2+1)return true;
    }
    return false;
}

signed main(){
    cin>>T;
    while(T--){
        cin>>n>>k;
        for(int i=1;i<=n;i++)cin>>a[i];
        int L=1,R=1000000000,ans=0;
        while(L<=R){
            int M=(L+R)/2;
            if(ck(M))ans=M,L=M+1;
            else R=M-1;
        }
        printf("%d\n",ans);
    }
    return 0;
}


