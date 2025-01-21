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
#define int long long

using namespace std;

const int inf = 1.01e9;
const int mod = 998244353;
const int N = 1e6 + 10;

inline int gcd(int x,int y){
    return y?gcd(y,x%y):x;
}

void solve(){
    int l,r,G;
    cin>>l>>r>>G;
    int L=(l/G),R=(r/G);
    if(L*G<l)L++;
    int mx=-1,ansl=0,ansr=0;
    for(int i=L;i<=R&&i<=L+30;i++){
        for(int j=R;j>=i&&j>=R-30;j--){
            if(gcd(i,j)==1){
                if(j-i>mx||(j-i==mx&&i<ansl)){
                    mx=j-i,ansl=i,ansr=j;
                }
            }
        }
    }
    if(mx==-1)printf("-1 -1\n");
    else printf("%lld %lld\n",ansl*G,ansr*G);
}

signed main(){

    // freopen(".in", "r", stdin);
    // freopen(".out", "w", stdout);
  
    
    int t = 1;  cin >> t;
    while(t--) solve();
    return 0;
}
