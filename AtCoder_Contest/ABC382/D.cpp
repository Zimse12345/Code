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
const int N = 2e5 + 10;

int n,m,a[N];
vector< vector<int> > ans;
void dfs(int t,int val){
    if(val+(n-t)*10>m)return;
    if(t==n){
        vector<int> v;
        for(int i=1;i<=n;i++)v.push_back(a[i]);
        ans.push_back(v);
    }
    for(int i=val+10;i<=m;i++){
        a[t+1]=i;
        dfs(t+1,i);
    }
    return;
}
void solve(){
    cin>>n>>m;
    dfs(0,-9);
    printf("%llu\n",ans.size());
    for(unsigned i=0;i<ans.size();i++){
        for(int j=0;j<n;j++)printf("%d ",ans[i][j]);
        printf("\n");
    }
}

signed main(){

    // freopen(".in", "r", stdin);
    // freopen(".out", "w", stdout);
  
    
    int t = 1; // cin >> t;
    while(t--) solve();
    return 0;
}
