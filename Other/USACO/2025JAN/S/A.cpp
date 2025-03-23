#include <bits/stdc++.h>
#define int long long
using namespace std;

const int N=1.01e6;
int n,a[N],b[N];
vector<int> pa[N],pb[N];
int ans; 

signed main(){
    cin>>n;
    for(int i=1;i<=n;i++)cin>>a[i],pa[a[i]].push_back(min(i,n-i+1));
    for(int i=1;i<=n;i++)cin>>b[i],pb[b[i]].push_back(min(i,n-i+1));
    for(int i=1;i<=n;i++)if(pa[i].size()&&pb[i].size()){
        sort(pa[i].begin(),pa[i].end());
        sort(pb[i].begin(),pb[i].end());
        int x=pa[i].size(),y=pb[i].size(),s=0,c=0;
        for(int j=0;j<y;j++)s+=pb[i][j];
        int p=y-1;
        for(int j=x-1;j>=0;j--){
            while(p>=0&&pb[i][p]>pa[i][j]){
                s-=pb[i][p];
                --p;
                ++c;
            }
            ans+=s+c*pa[i][j];
        }
    }
    for(int i=1;i<=n;i++)if(a[i]==b[i]){
        ans+=n*(n+1)/2-i*(n-i+1);
    }
    printf("%lld\n",ans);
    return 0;
}

