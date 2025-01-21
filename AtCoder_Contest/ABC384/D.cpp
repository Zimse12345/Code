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
#define int long long

using namespace std;

const int inf = 1.01e9;
const int mod = 998244353;
const int N = 1e6 + 10;
int n,S,a[N],s[N];
map<int,int> p;

void solve(){
    cin>>n>>S;
    for(int i=1;i<=n;i++){
        cin>>a[i];
        s[i]=s[i-1]+a[i];
    }
    for(int i=n+1;i<=n+n;i++)s[i]=s[i-1]+a[i-n];
    S%=s[n];
    p[0]=1;
    for(int i=1;i<=n*2;i++){
        p[s[i]]=1;
        if(p[s[i]-S]){
            printf("Yes\n");
            return;
        }
    }
    printf("No\n");
    return;
}

signed main(){

    // freopen(".in", "r", stdin);
    // freopen(".out", "w", stdout);
  
    
    int t = 1; // cin >> t;
    while(t--) solve();
    return 0;
}
