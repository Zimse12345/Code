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

int n,h[N],ans=1;
void solve(){
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>h[i];
        for(int j=1;j<i;j++){
            int x=i,s=1;
            while(x-j>0&&h[x-j]==h[x])x-=j,++s;
            ans=max(ans,s);
        }
    }
    printf("%d\n",ans);
}

signed main(){

    // freopen(".in", "r", stdin);
    // freopen(".out", "w", stdout);
  
    
    int t = 1; // cin >> t;
    while(t--) solve();
    return 0;
}
