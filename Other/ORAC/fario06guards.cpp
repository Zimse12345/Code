#include <bits/stdc++.h>
using namespace std;

const int N=2.01e6,M=24;
int n,k,a[N],nxt[N][M],ans; 

signed main(){
    cin>>n>>k;
    for(int i=1;i<=n;i++)cin>>a[i],a[i+n]=a[i];
    for(int i=1;i<=n*2;i++)a[i]+=a[i-1];
    for(int i=1,x=1,y=1;i<=n*2;i++){
        while(x<n*2&&a[x+1]-a[i]<=k)++x;
        y=max(x,y);
        while(y<n*2&&a[y+1]-a[x]<=k)++y;
        nxt[i][0]=y+1;
    }
    nxt[n*2+1][0]=n*2+1;
    for(int j=1;j<M;j++){
        for(int i=1;i<=n*2+1;i++){
            nxt[i][j]=nxt[nxt[i][j-1]][j-1];
        }
    }
    ans=n;
    for(int i=1;i<=n;i++){
        int p=i,c=0;
        for(int j=M-1;j>=0;j--)if(nxt[p][j]<i+n){
            p=nxt[p][j],c+=(1<<j);
        }
        ++c;
        ans=min(ans,c);
    }
    printf("%d\n",ans);
    return 0;
}


