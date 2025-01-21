#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <stack>
#include <set>
#include <map>
#include <math.h>

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
int n,m,k,p[N],u[N],c[N],f[N],g[N];

void solve(){
    cin>>n>>m>>k;
    for(int i=1;i<=n;i++)cin>>p[i]>>u[i]>>c[i];
    for(int col=1;col<=n;col++){
        for(int i=1;i<=n;i++)if(col==c[i]){
            for(int x=m;x>=p[i];x--){
                f[x]=max(f[x],f[x-p[i]]+u[i]);
                g[x]=max(g[x],g[x-p[i]]+u[i]);
                g[x]=max(g[x],f[x-p[i]]+u[i]+k);
            }
        }
        for(int x=0;x<=m;x++)f[x]=max(f[x],g[x]),g[x]=0;
    }
    int ans=0;
    for(int x=0;x<=m;x++)ans=max(ans,f[x]);
    printf("%lld\n",ans);
}

signed main(){

    // freopen(".in", "r", stdin);
    // freopen(".out", "w", stdout);
  
    
    int t = 1; // cin >> t;
    while(t--) solve();
    return 0;
}
