#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <stack>
#include <set>
#include <map>
#include <cstring>
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
const int N = 2e5 + 10, M = N << 1;
int ans[N],n;

void solve(){
    int m;
    cin>>m;
    while(m){
        int v=1,t=0;
        while(v*3<=m&&t<10)v*=3,++t;
        m-=v;
        ans[++n]=t;
    }
    printf("%d\n",n);
    for(int i=1;i<=n;i++)printf("%d ",ans[i]);
}

signed main(){

    // freopen(".in", "r", stdin);
    // freopen(".out", "w", stdout);
  
    codeforces;
    
    int t = 1; // cin >> t;
    while(t--) solve();
    return 0;
}
