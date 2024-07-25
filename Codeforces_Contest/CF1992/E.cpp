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

int a[N],b[N],ans,d[N];

void solve(){
    int n;
    cin>>n;
    int _n=n,w=0;
    while(_n)d[w++]=_n%10,_n/=10;
    ans=0;
    for(int i=1;i<=10000;i++){
        int j=w*i;
        _n=0;
        while(1){
            _n=_n*10+d[w-j%w-1];
            --j;
            if(_n>n*i-j||j<=0)break;
            if(_n==n*i-j&&j<=10000&&j<=i*n)++ans,a[ans]=i,b[ans]=j;
        }
    }
    printf("%d\n",ans);
    for(int i=1;i<=ans;i++)printf("%d %d\n",a[i],b[i]);
}

signed main(){

    // freopen(".in", "r", stdin);
    // freopen(".out", "w", stdout);
  
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    
    int t = 1;  cin >> t;
    while(t--) solve();
    return 0;
}
