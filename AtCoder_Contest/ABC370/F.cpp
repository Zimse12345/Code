#include <bits/stdc++.h>
#define int long long
using namespace std;

const int N=4.01e5;
int n,k,a[N],nxt[N][20];

int ck(int x){
    for(int i=0;i<20;i++){
        nxt[n*2+1][i]=n*2+1;
        nxt[n*2+2][i]=n*2+1;
    }
    for(int i=n*2,t=n*2,s=0;i>=1;i--){
        s+=a[i];
        while(s-a[t]>=x)s-=a[t],--t;
        if(s>=x)nxt[i][0]=t;
        else nxt[i][0]=n*2+1;
        for(int j=1;j<20;j++)nxt[i][j]=nxt[nxt[i][j-1]+1][j-1];
    }
    int res=0;
    for(int i=1;i<=n;i++){
        int p=i;
        for(int j=0;j<20;j++)if(k&(1<<j))p=nxt[p][j]+1;
        if(p<=i+n)++res;
    }
    return res;
}

signed main(){
    cin>>n>>k;
    for(int i=1;i<=n;i++)cin>>a[i],a[i+n]=a[i];
    int L=1,R=2e9,ans=0,ans2=0;
    while(L<=R){
        int mid=(L+R)/2;
        int c=ck(mid);
        if(c>0)ans=mid,ans2=n-c,L=mid+1;
        else R=mid-1;
    }
    printf("%d %d\n",ans,ans2);
    return 0;
}


