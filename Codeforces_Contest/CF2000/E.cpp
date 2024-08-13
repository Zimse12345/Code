#include <bits/stdc++.h>
#define int long long
using namespace std;

const int N=1.01e6;
int T,n,m,k,w,a[N],b[N];

vector<int> mp[N];

signed main(){
    cin>>T;
    while(T--){
        cin>>n>>m>>k;
        cin>>w;
        for(int i=1;i<=w;i++)cin>>a[i];
        sort(a+1,a+w+1);
        for(int i=0;i<=n+1;i++){
            mp[i].resize(m+2);
            for(int j=0;j<=m+1;j++)mp[i][j]=0;
        }
        for(int i=1;i<=n-k+1;i++){
            for(int j=1;j<=m-k+1;j++){
                ++mp[i][j];
                --mp[i+k][j];
                --mp[i][j+k];
                ++mp[i+k][j+k];
            }
        }
        int _w=0,ans=0;
        for(int i=1;i<=n;i++){
            for(int j=1;j<=m;j++){
                mp[i][j]+=mp[i-1][j]+mp[i][j-1]-mp[i-1][j-1];
                b[++_w]=mp[i][j];
            }
        }
        sort(b+1,b+_w+1);
        for(int i=1;i<=w;i++)ans+=a[i]*b[_w-w+i];
        printf("%lld\n",ans);
    }
    return 0;
}


