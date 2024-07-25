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
#define int long long

using namespace std;

const int inf = 1e9 + 7;
const int mod = 1e9 + 7;
const int N = 2e6 + 10, M = N << 1;

#define inv fpow
inline int fpow(long long x,int y=mod-2){int z=1;while(y){if(y&1)z=x*z%mod;x=x*x%mod,y/=2;}return z;}

int n,k,a[N],v1,v2,sum;

void solve(){
    cin>>n>>k;
    v1=v2=sum=0;
    for(int i=1;i<=n;i++){
        cin>>a[i];
        if(i<=k)(v1+=a[i])%=mod;
        else (v2+=a[i])%=mod;
        (sum+=a[i])%=mod;
    }
    (v1*=inv(k))%=mod;
    (v2*=inv(n-k))%=mod;

    int t=k*inv(n-k+1)%mod;
    int c=(n-k+1)/2;
    int ans=c*(v2+v1*t%mod)%mod;
    if((n-k)%2==0)ans=(ans+v1*t)%mod;
    printf("%lld %lld\n",ans,(sum-ans+mod)%mod);
}

signed main(){

    // freopen(".in", "r", stdin);
    // freopen(".out", "w", stdout);
  
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    
    int T = 1;  cin >> T;
    while(T--) solve();
    return 0;
}