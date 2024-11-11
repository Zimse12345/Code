#include <bits/stdc++.h>
#define int long long
using namespace std;

const int N=1.01e6;
int T,n,m,v,a[N],s[N],f[N],g[N],ans;

signed main(){
    cin>>T;
    while(T--){
        cin>>n>>m>>v;
        for(int i=1;i<=n;i++){
            cin>>a[i];
            s[i]=a[i]+s[i-1];
        }
        f[0]=g[n+1]=0;
        for(int i=1,s=0,c=0;i<=n;i++){
            s+=a[i];
            if(s>=v)s=0,++c;
            f[i]=c;
        }
        for(int i=n,s=0,c=0;i>=1;i--){
            s+=a[i];
            if(s>=v)s=0,++c;
            g[i]=c;
        }
        if(f[n]<m){
            printf("-1\n");
            continue;
        }
        ans=0;
        for(int i=1,t=0;i<=n+1;i++){
            while(t<i&&f[t]+g[i]<m)++t;
            if(f[t]+g[i]>=m&&t<i)ans=max(ans,s[i-1]-s[t]);
        }
        printf("%lld\n",ans);
    }
    return 0;
}


