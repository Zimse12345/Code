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
char s[N];

void solve(){
    scanf("%s",s+1);
    int n=strlen(s+1);
    for(int i=1;i<=n;i++)if(s[i]!='.')putchar(s[i]);
    putchar('\n');
}

signed main(){

    // freopen(".in", "r", stdin);
    // freopen(".out", "w", stdout);
  
    codeforces;
    
    int t = 1; // cin >> t;
    while(t--) solve();
    return 0;
}
