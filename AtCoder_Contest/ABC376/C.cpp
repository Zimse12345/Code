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
const int N = 1e6 + 10, M = N << 1;
int n,a[N],b[N];

void solve(){
    cin>>n;
    for(int i=1;i<=n;i++)cin>>a[i];
    for(int i=1;i<n;i++)cin>>b[i];
    sort(a+1,a+n+1);
    sort(b+1,b+n);
    int t=n-1,ans=0;
    for(int i=n;i>=1;i--){
        if(t>0&&b[t]>=a[i]){
            --t;
            continue;
        }
        if(!ans)ans=a[i];
        else{
            ans=-1;
            break;
        }
    }
    printf("%d\n",ans);
}

signed main(){
    
    int t = 1; // cin >> t;
    while(t--) solve();
    return 0;
}
