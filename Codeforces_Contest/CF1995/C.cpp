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

int n,a[N];

void solve(){
    cin>>n;
    a[0]=1;
    int p=0,ans=0,tag=0;
    for(int i=1;i<=n;i++){
        cin>>a[i];
        if(a[i]==1&&a[i-1]>1)tag=1,ans=-1;
        if(tag||a[i]==1)continue;
        int x=a[i];
        while(x<a[i-1])x=x*x,++p;
        if(a[i-1]==1)p=0;
        else{
            x=a[i-1];
            while(x*x<=a[i]&&p>0)x=x*x,--p;
        }
        ans+=p;
    }
    printf("%lld\n",ans);
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

