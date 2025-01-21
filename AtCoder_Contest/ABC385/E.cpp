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
//#define int long long

using namespace std;

const int inf = 1.01e9;
const int mod = 998244353;
const int N = 1e6 + 10;
int n,cnt[N],ans;
vector<int> g[N];
vector<int> c[N];

void solve(){
    cin>>n;
    for(int i=1,u,v;i<n;i++){
        cin>>u>>v;
        g[u].push_back(v);
        g[v].push_back(u);
    }
    for(int u=1;u<=n;u++){
        for(unsigned i=0;i<g[u].size();i++){
            int v=g[u][i];
            c[u].push_back(g[v].size()-1);
        }
    }
    for(int i=1;i<=n;i++){
        sort(c[i].begin(),c[i].end());
        int sz=c[i].size();
        for(int j=sz-1;j>=0;j--){
            ans=max(ans,1+(sz-j)*(1+c[i][j]));
        }
    }
    printf("%d\n",n-ans);
}

signed main(){

    // freopen(".in", "r", stdin);
    // freopen(".out", "w", stdout);
  
    
    int t = 1; // cin >> t;
    while(t--) solve();
    return 0;
}
