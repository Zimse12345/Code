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
#define codeforces cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(false)
#define bendl(x) x.begin(), x.end()
#define siz(x) ((int)(x).size())

using namespace std;

const int inf = 1 << 30;
const int mod = 998244353;
const int N = 1e6 + 10, M = N << 1;
int n,t,c;

void solve(){
    cin>>n>>c;
    int ans=1;
    cin>>t;
    for(int i=2;i<=n;i++){
        int x=0;
        cin>>x;
        if(x-t>=c)++ans,t=x;
    }
    printf("%d\n",ans);
}

signed main(){
    
    int t = 1; // cin >> t;
    while(t--) solve();
    return 0;
}
