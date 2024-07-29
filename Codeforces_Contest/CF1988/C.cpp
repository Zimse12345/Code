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
int n,a[N],cnt;

void solve(){
    cin>>n;
    cnt=0;
    for(int i=60;i>=0;i--)if(n&(1ll<<i))a[++cnt]=n-(1ll<<i);
    if(a[cnt]==0)a[cnt]=n;
    else a[++cnt]=n;
    printf("%lld\n",cnt);
    for(int i=1;i<=cnt;i++)printf("%lld ",a[i]);
    printf("\n");
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