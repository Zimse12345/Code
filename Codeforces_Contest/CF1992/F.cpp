#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <stack>
#include <set>
#include <map>
#include <list>
#include <math.h>
#include <functional> 

#define endl '\n'
#define pii pair<int, int>
#define pdd pair<double, double> 
#define fi first
#define se second
#define pb push_back
#define eb emplace_back

using namespace std;

const int inf = 1e9 + 7;
const int mod = 998244353;
const int N = 2e5 + 10, M = N << 1;

int n,x,a[N],d[N],cnt,vis[N];
void solve(){
    cin>>n>>x;
    for(int i=1;i<=n;i++)cin>>a[i];
    for(int i=2;i*i<=x;i++)if(x%i==0){
        d[++cnt]=i;
        if(x/i!=i)d[++cnt]=x/i;
    }
    sort(d+1,d+cnt+1);
    int ans=1;
    for(int i=1;i<=n;i++)if(x%a[i]==0&&a[i]>1){
        if(vis[x/a[i]]){
            ++ans;
            for(int j=1;j<=cnt;j++)vis[d[j]]=0;
        }
        for(int j=cnt;j>=1;j--)if(vis[d[j]]&&(x/d[j])%a[i]==0)vis[d[j]*a[i]]=1;
        vis[a[i]]=1;
    }
    for(int j=1;j<=cnt;j++)vis[d[j]]=0;
    cnt=0;
    printf("%d\n",ans);
}

signed main(){

    // freopen(".in", "r", stdin);
    // freopen(".out", "w", stdout);
  
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    
    int t = 1;  cin >> t;
    while(t--) solve();
    return 0;
}
