#include <bits/stdc++.h>
using namespace std;

const int N=1.01e6;
int T,n,a[N],f[N];

signed main(){
    cin>>T;
    while(T--){
        cin>>n;
        for(int i=1;i<=n;i++)cin>>a[i];
        for(int i=0;i<256;i++)f[i]=0;
        f[0]=1;
        int ans=0;
        for(int i=1,x=0;i<=n;i++){
            x^=a[i];
            for(int j=0;j<256;j++)if(f[j])ans=max(ans,j^x);
            f[x]=1;
        }
        printf("%d\n",ans);
    }
    return 0;
}


