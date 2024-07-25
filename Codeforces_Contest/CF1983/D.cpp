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
const int N = 2e6 + 10, M = N << 1;
int n,a[N],b[N];
map<int,int> mp;

struct TreeArray{
    int tr[N];
    inline void ub(int& x){x+=(x&(-x));return;}
    inline void db(int& x){x-=(x&(-x));return;}
    inline void a(int x,int y){for(;x<N;ub(x))tr[x]+=y;return;}
    inline int q(int x){int s=0;for(;x;db(x))s+=tr[x];return s;}
    inline void clear(int sz=N){for(int i=0;i<sz;i++)tr[i]=0;return;}
}s;

void solve(){
    cin>>n;
    mp.clear();
    s.clear(n*4);
    for(int i=1;i<=n;i++)cin>>a[i],mp[a[i]]=i;
    int tag=1;
    for(int i=1;i<=n;i++){
        cin>>b[i];
        if(mp.find(b[i])==mp.end())tag=0;
        b[i]=mp[b[i]];
    }
    if(!tag){
        printf("NO\n");
        return;
    }
    long long sum=0;
    for(int i=1;i<=n;i++){
        sum+=s.q(n)-s.q(b[i]-1);
        s.a(b[i],1);
    }
    if(sum&1ll)printf("NO\n");
    else printf("YES\n");
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