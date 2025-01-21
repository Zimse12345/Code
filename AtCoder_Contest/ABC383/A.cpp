#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <stack>
#include <set>
#include <map>
#include <math.h>

#define fi first
#define se second
#define pb push_back
#define eb emplace_back
#define bendl(x) x.begin(), x.end()
#define siz(x) ((int)(x).size())
//#define int long long

using namespace std;

const int inf = 1.01e9;
const int mod = 998244353;
const int N = 1e6 + 10;
int n,t[N],v[N];

void solve(){
    cin>>n;
    int r=0;
    for(int i=1;i<=n;i++){
        cin>>t[i]>>v[i];
        r=max(0,r-(t[i]-t[i-1]));
        r+=v[i];
    }
    printf("%d\n",r);
}

signed main(){

    // freopen(".in", "r", stdin);
    // freopen(".out", "w", stdout);
  
    
    int t = 1; // cin >> t;
    while(t--) solve();
    return 0;
}
