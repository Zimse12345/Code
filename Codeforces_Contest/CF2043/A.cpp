#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <stack>
#include <set>
#include <map>
#include <cmath>
#include <cstring>

#define fi first
#define se second
#define pb push_back
#define eb emplace_back
#define bendl(x) x.begin(), x.end()
#define siz(x) ((int)(x).size())
#define int long long

using namespace std;

const int inf = 1.01e9;
const int mod = 998244353;
const int N = 1e6 + 10;

void solve(){
    int n,c=1;
    cin>>n;
    while(n>3)n/=4,c*=2;
    printf("%lld\n",c); 
}

signed main(){

    // freopen(".in", "r", stdin);
    // freopen(".out", "w", stdout);
  
    
    int t = 1;  cin >> t;
    while(t--) solve();
    return 0;
}
