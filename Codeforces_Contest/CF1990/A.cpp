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
int n,a[N]; 

void solve(){
    cin>>n;
    int mx=0,cnt=0;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    sort(a+1,a+n+1);
    int tag=0;
    for(int l=1;l<=n;){
        int r=l;
        while(r<n&&a[r+1]==a[r])++r;
        if((r-l+1)&1)tag=1;
        l=r+1;
    }
    if(tag)printf("YES\n");
    else printf("NO\n");
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

