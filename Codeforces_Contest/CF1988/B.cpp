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
int n;
char s[N];

void solve(){
    cin>>n;
    scanf("%s",s+1);
    int c0=0,c1=0;
    for(int i=1;i<=n;i++){
        if(s[i]=='1')++c1;
        if(s[i]=='0'&&s[i-1]!='0')++c0;
    }
    if(c1>c0)printf("YES\n");
    else printf("NO\n");
}

signed main(){

    // freopen(".in", "r", stdin);
    // freopen(".out", "w", stdout);
  
//    ios::sync_with_stdio(0);
//    cin.tie(0); cout.tie(0);
    
    int t = 1;  cin >> t;
    while(t--) solve();
    return 0;
}
