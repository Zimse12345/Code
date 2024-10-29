#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <stack>
#include <set>
#include <map>
#include <list>
#include <math.h>
#include <iostream>
#include <cstring>
#include <functional> 

#define endl '\n'
#define pii pair<int, int>
#define pdd pair<double, double> 
#define fi first
#define se second
#define pb push_back
#define eb emplace_back
#define bendl(x) x.begin(), x.end()
#define siz(x) ((int)(x).size())
#define int long long

using namespace std;

const int inf = 1 << 30;
const int mod = 998244353;
const int N = 1e6 + 10, M = N << 1;
int n,m,x[N],vis[N];
struct edge{
    int to,w;
    edge(int to=0,int w=0):to(to),w(w){}
};
vector<edge> g[N]; 

void dfs(int u,int val){
    vis[u]=1,x[u]=val;
    for(unsigned i=0;i<g[u].size();i++){
        int v=g[u][i].to;
        if(vis[v])continue;
        dfs(v,val+g[u][i].w);
    }
    return;
}

void solve(){
    cin>>n>>m;
    for(int i=1,u,v,w;i<=m;i++){
        cin>>u>>v>>w;
        g[u].push_back(edge(v,w));
        g[v].push_back(edge(u,-w));
    }
    for(int i=1;i<=n;i++)if(!vis[i])dfs(i,0);
    for(int i=1;i<=n;i++)printf("%lld ",x[i]);
    printf("\n");
}

signed main(){
    
    int t = 1; // cin >> t;
    while(t--) solve();
    return 0;
}
