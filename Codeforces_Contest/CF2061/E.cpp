#include <bits/stdc++.h>
using namespace std;

const int N=1.01e6;
int T,n,m,k,a[N],b[N],c[N],t,B[N],pc[N],mn[N];
long long s;

signed main(){
    cin>>T;
    while(T--){
        cin>>n>>m>>k;
        s=0;
        t=0;
        for(int i=1;i<=n;i++)cin>>a[i],s+=a[i];
        for(int i=0;i<m;i++)cin>>b[i];
        for(int i=0;i<(1<<m);i++){
            B[i]=(1<<30)-1,pc[i]=0;
            for(int j=0;j<m;j++)if(i&(1<<j))B[i]&=b[j],++pc[i];
        }
        for(int i=1;i<=n;i++){
            for(int j=0;j<=m;j++)mn[j]=a[i];
            for(int j=0;j<(1<<m);j++){
                mn[pc[j]]=min(mn[pc[j]],a[i]&B[j]);
            }
            for(int j=1;j<=m;j++)c[++t]=mn[j-1]-mn[j];
        }
        sort(c+1,c+t+1);
        for(int i=t;i>=1&&i>=t-k+1;i--)s-=c[i];
        printf("%lld\n",s);
    }
    return 0;
}


