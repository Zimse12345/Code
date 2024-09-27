#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <stack>
#include <set>
#include <map>
#include <cstring>
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
const int N = 2e5 + 10, M = N << 1;
int n,m,k,U[N],V[N],f[N],g[N],t;

inline int c(int x,int T=t){
    return (x+T)%n;
}

void solve(){
    cin>>n>>m>>k;
    for(int i=1;i<=m;i++){
        cin>>U[i]>>V[i];
        --U[i],--V[i];
    }
    f[0]=1;
    t=n*k;
    while(k--){
        for(int i=1;i<=m;i++)g[c(U[i])]=f[c(U[i])];
        --t;
        for(int i=1;i<=m;i++)(f[c(V[i])]+=g[c(U[i],t+1)])%=mod;
    }
    int ans=0;
    for(int i=0;i<n;i++)(ans+=f[i])%=mod;
    printf("%lld\n",ans);
}

signed main(){

    // freopen(".in", "r", stdin);
    // freopen(".out", "w", stdout);
  
//    codeforces;
    
    int t = 1; // cin >> t;
    while(t--) solve();
    return 0;
}
