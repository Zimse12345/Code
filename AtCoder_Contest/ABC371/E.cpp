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
#define int long long

using namespace std;

const int inf = 1 << 30;
const int mod = 998244353;
const int N = 1.01e6;
int n,a[N],ans;
vector<int> p[N];

inline int f(int x){
    return x*(x+1)/2;
}

void solve(){
    cin>>n;
    for(int i=1;i<=n;i++)p[i].push_back(0);
    for(int i=1;i<=n;i++)cin>>a[i],p[a[i]].push_back(i);
    for(int i=1;i<=n;i++){
        p[i].push_back(n+1);
        ans+=f(n);
        for(unsigned j=0;j+1<p[i].size();j++){
            ans-=f(p[i][j+1]-p[i][j]-1);
        }
    }
    printf("%lld\n",ans);
    return; 
}

signed main(){
    int t = 1; // cin >> t;
    while(t--) solve();
    return 0;
}


