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
const int N = 1e6 + 10, M = N << 1;

int n,a[N];
char s[N];
void solve(){
    cin>>n;
    scanf("%s",s);
    for(int i=1;i<=n;i++)a[i]=s[n-i]-'0';
    for(int i=1;i<=n;i++)a[i]*=(n-i+1);
    for(int i=n-1;i>=1;i--)a[i]+=a[i+1];
    for(int i=1;i<n;i++){
        a[i+1]+=a[i]/10;
        a[i]%=10;
    }
    while(a[n]>=10)a[n+1]=a[n]/10,a[n]%=10,++n;
    for(int i=n;i>=1;i--)printf("%lld",a[i]);
    printf("\n");
}

signed main(){

    // freopen(".in", "r", stdin);
    // freopen(".out", "w", stdout);
  
    // codeforces;
    
    int t = 1; // cin >> t;
    while(t--) solve();
    return 0;
}
