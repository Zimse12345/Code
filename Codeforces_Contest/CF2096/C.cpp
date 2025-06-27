#include <bits/stdc++.h>
#define int long long
using namespace std;

const int N=1.01e3,inf=1e15;
int T,n,h[N][N],a[N],b[N],ans;
int e[N],l[N],r[N],fe[N],fr[N];

void sol(){
    for(int i=1;i<=n;i++){
        e[i]=l[i]=r[i]=0;
        fe[i]=fr[i]=inf;
        for(int j=1;j<=n;j++){
            if(h[i][j]==h[i-1][j])e[i]=1;
            if(h[i][j]==h[i-1][j]-1)l[i]=1;
            if(h[i][j]==h[i-1][j]+1)r[i]=1;
        }
        if(!e[i]){
            fe[i]=min(fe[i],fe[i-1]);
            fr[i]=min(fr[i],fr[i-1]+a[i]);
        }
        if(!l[i]){
            fr[i]=min(fr[i],fe[i-1]+a[i]);
        }
        if(!r[i]){
            fe[i]=min(fe[i],fr[i-1]);
        }
    }
    ans+=min(fe[n],fr[n]);
    return;
}

signed main(){
    cin>>T;
    while(T--){
        cin>>n;
        for(int i=1;i<=n;i++){
            h[0][i]=-1;
            for(int j=1;j<=n;j++){
                cin>>h[i][j];
            }
        }
        for(int i=1;i<=n;i++)cin>>a[i];
        for(int i=1;i<=n;i++)cin>>b[i];
        ans=0;
        sol();
        for(int i=1;i<=n;i++){
            for(int j=1;j<i;j++)swap(h[i][j],h[j][i]);
            swap(a[i],b[i]);
        }
        sol();
        if(ans>=inf)ans=-1;
        printf("%lld\n",ans);
    }
    return 0;
}


