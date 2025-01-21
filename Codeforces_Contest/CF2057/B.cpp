#include <bits/stdc++.h>
using namespace std;

const int N=1.01e6;
int T,n,m,a[N],t,b[N];

signed main(){
    cin>>T;
    while(T--){
        cin>>n>>m;
        for(int i=1;i<=n;i++)cin>>a[i];
        sort(a+1,a+n+1),a[n+1]=0;
        t=0;
        for(int i=1,pre=0;i<=n;i++){
            if(a[i]!=a[i+1]){
                b[++t]=i-pre;
                pre=i;
            }
        }
        sort(b+1,b+t+1);
        int ans=t;
        for(int i=1;i<t;i++)if(b[i]<=m){
            m-=b[i];
            --ans;
        }
        printf("%d\n",ans);
    }
    return 0;
}


