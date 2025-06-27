#include <bits/stdc++.h>
#define int long long
using namespace std;

const int N=1.01e6,inf=1e18;
int T,n,k,a[N],m,s[N];

signed main(){
    cin>>T;
    while(T--){
        cin>>n>>k;
        m=0;
        int sum=0;
        for(int i=1;i<=n;i++){
            cin>>a[i];
            for(int j=0;j<32;j++)if(a[i]&(1ll<<j))++sum;
            while(a[i]<inf){
                int w=0;
                while(a[i]&(1ll<<w))++w;
                w=(1ll<<w);
                w=(w-1)*2+1;
                int _v=(a[i]|w);
                s[++m]=_v-a[i];
                a[i]=_v;
            }
        }
        sort(s+1,s+m+1);
        int ans=0;
        while(k>=s[ans+1]&&ans<m)++ans,k-=s[ans];
        printf("%lld\n",ans+sum);
    }
    return 0;
}


