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

const int inf = 9223372036854775807;
const int mod = 998244353;
const int N = 3e5 + 10, M = N << 1;
int n,a[N],f[N][20];
vector<int> g[N];

void dfs(int u,int from){
    for(int i=0;i<20;i++)f[u][i]=(i+1)*a[u];
    for(unsigned i=0;i<g[u].size();i++){
        int v=g[u][i];
        if(v==from)continue;
        dfs(v,u);
        int mn=inf,p=0,se=inf;
        for(int j=0;j<20;j++){
            if(f[v][j]<mn)se=mn,mn=f[v][j],p=j;
            else if(f[v][j]<se)se=f[v][j];
        }
        for(int j=0;j<20;j++){
            if(p==j)f[u][j]+=se;
            else f[u][j]+=mn;
        }
    }
    return;
}

void solve(){
    cin>>n;
    for(int i=1;i<=n;i++)cin>>a[i],g[i].resize(0);
    for(int i=1,u,v;i<n;i++){
        cin>>u>>v;
        g[u].pb(v),g[v].pb(u); 
    }
    dfs(1,0);
    int ans=inf;
    for(int i=0;i<20;i++)ans=min(ans,f[1][i]);
    printf("%lld\n",ans);
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
