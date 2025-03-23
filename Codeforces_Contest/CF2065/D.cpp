#include <bits/stdc++.h>
#define int long long
using namespace std;

const int N=1.01e6;
int T,n,m,s[N],ans;
vector<int> a[N];

signed main(){
    cin>>T;
    while(T--){
        cin>>n>>m;
        ans=0;
        for(int i=1;i<=n;i++){
            a[i].resize(m+1);
            for(int j=1;j<=m;j++){
                cin>>a[i][j],a[i][j]+=a[i][j-1];
                ans+=a[i][j];
            }
            s[i]=a[i][m];
        }
        sort(s+1,s+n+1);
        for(int i=n;i>=1;i--){
            ans+=(i-1)*s[i]*m;
        }
        printf("%lld\n",ans);
    }
    return 0;
}


