#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <stack>
#include <set>
#include <map>
#include <math.h>
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
const int Mod = 998244353;
const int N = 1e6 + 10;
int n,k,p[N];

inline int fpow(long long x,int y=Mod-2){
int z=1;while(y){if(y&1)z=x*z%Mod;x=x*x%Mod,y/=2;}return z;}

struct TreeArray{
    int tr[N];
    inline void ub(int& x){x+=(x&(-x));return;}
    inline void db(int& x){x-=(x&(-x));return;}
    inline void a(int x,int y){for(;x<N;ub(x))tr[x]+=y;return;}
    inline int q(int x){int s=0;for(;x;db(x))s+=tr[x];return s;}
    inline void clear(int sz=N){for(int i=0;i<sz;i++)tr[i]=0;return;}
}tree;
int ans=0;

void solve(){
    cin>>n>>k;
    for(int i=1;i<=n;i++){
        cin>>p[i];
        tree.a(p[i],1);
        (ans+=i-tree.q(p[i]))%=mod;
    }
    tree.clear();
    int cnt=0;
    for(int i=1;i<k;i++){
        tree.a(p[i],1);
        cnt+=(i-tree.q(p[i]));
    }
    for(int i=k;i<=n;i++){
        tree.a(p[i],1);
        cnt+=(tree.q(n)-tree.q(p[i]));
        if(i>k){
            tree.a(p[i-k],-1);
            cnt-=tree.q(p[i-k]);
        }
        int ex=(k*(k-1)/2%mod)*fpow(2)%mod;
        (ans+=(ex-cnt)%mod*fpow(n-k+1)%mod)%=mod; 
    }
    (ans+=mod)%=mod;
    printf("%lld\n",ans);
}

signed main(){

    // freopen(".in", "r", stdin);
    // freopen(".out", "w", stdout);
  
    // codeforces;
    
    int t = 1; // cin >> t;
    while(t--) solve();
    return 0;
}
