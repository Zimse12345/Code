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
const int N = 2e5 + 10, M = N << 1;

int n,k;
char s[N];
void solve(){
    cin>>n>>k;
    scanf("%s",s);
    int ans=0;
    for(int i=0,r=0;i<n;i++){
        if(s[i]=='O')++r;
        else r=0;
        if(r>=k)r-=k,++ans;
    }
    printf("%d\n",ans);
}

signed main(){

    // freopen(".in", "r", stdin);
    // freopen(".out", "w", stdout);
  
    // codeforces;
    
    int t = 1; // cin >> t;
    while(t--) solve();
    return 0;
}
