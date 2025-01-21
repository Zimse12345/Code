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

const int inf = 1.01e18;
const int mod = 998244353;
const int N = 1e6 + 10;
int n,ll,rr,a[N],s; 

void solve(){
    cin>>n>>ll>>rr;
    s=0;
    for(int i=1;i<=n;i++)cin>>a[i],s+=a[i];
    //s-a-b in [l,r]
    //a+b in [s-r,s-l]
    int l=s-rr,r=s-ll;
    sort(a+1,a+n+1);
    int L=n+1,R=n,ans=0; 
    for(int i=1;i<=n;i++){
        while(L>1&&a[i]+a[L-1]>=l)--L;
        while(R>=L&&a[i]+a[R]>r)--R;
        ans+=R-L+1;
    }
    for(int i=1;i<=n;i++)if(a[i]*2>=l&&a[i]*2<=r)--ans;
    ans/=2;
    printf("%lld\n",ans);
}

signed main(){

    // freopen(".in", "r", stdin);
    // freopen(".out", "w", stdout);
  
    
    int t = 1;  cin >> t;
    while(t--) solve();
    return 0;
}
