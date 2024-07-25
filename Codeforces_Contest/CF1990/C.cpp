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
#define int long long

using namespace std;

const int inf = 1e9 + 7;
const int mod = 998244353;
const int N = 2e5 + 10, M = N << 1;
int n,a[N],sum,vis[N];

void solve(){
    cin>>n;
    sum=0;
    for(int i=1;i<=n;i++)vis[i]=0;
    int mx=0;
    for(int i=1;i<=n;i++){
        cin>>a[i];
        sum+=a[i];
        if(vis[a[i]])mx=max(mx,a[i]);
        vis[a[i]]=1,a[i]=mx;
    }
    for(int i=1;i<=n;i++)vis[i]=0;
    mx=0;
    for(int i=1;i<=n;i++){
        sum+=a[i];
        if(vis[a[i]])mx=max(mx,a[i]);
        vis[a[i]]=1,a[i]=mx;
    }
    for(int i=1;i<=n;i++)sum+=a[i]*(n-i+1);
    printf("%lld\n",sum);
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

