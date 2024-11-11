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

int q,que[N],l,r;
void solve(){
    cin>>q;
    l=1;
    int T=0;
    while(q--){
        int ty,t=0,h=0;
        cin>>ty;
        if(ty==1){
            que[++r]=T;
        }
        else if(ty==2){
            cin>>t;
            T+=t;
        }
        else{
            cin>>h;
            int ans=0;
            while(l<=r&&T-que[l]>=h)++ans,++l;
            printf("%lld\n",ans);
        }
    }
}

signed main(){

    // freopen(".in", "r", stdin);
    // freopen(".out", "w", stdout);
  
    // codeforces;
    
    int t = 1; // cin >> t;
    while(t--) solve();
    return 0;
}
