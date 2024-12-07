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

int n,d; 
char s[N];
void solve(){
    cin>>n>>d;
    scanf("%s",s+1);
    for(int i=n;i>=1;i--)if(s[i]=='@'&&d>0)--d,s[i]='.';
    for(int i=1;i<=n;i++)printf("%c",s[i]);
}

signed main(){

    // freopen(".in", "r", stdin);
    // freopen(".out", "w", stdout);
  
    
    int t = 1; // cin >> t;
    while(t--) solve();
    return 0;
}
