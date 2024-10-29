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
#define codeforces cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(false)
#define bendl(x) x.begin(), x.end()
#define siz(x) ((int)(x).size())

using namespace std;

const int inf = 1 << 30;
const int mod = 998244353;
const int N = 1e6 + 10, M = N << 1;
int n,m,ans=inf,dis[N],vis[N];
vector<int> g[N];
struct node{
    int x,y;
    node(int x=0,int y=0):x(x),y(y){}
    bool operator < (const node& _)const{return y>_.y;}
};
priority_queue<node> Q;

void Dij(){
    for(int i=1;i<=n;i++)vis[i]=0,dis[i]=inf;
    while(!Q.empty())Q.pop();
    dis[n]=0,Q.push(node(n,0));
    while(!Q.empty()){
        int u=Q.top().x;
        Q.pop();
        if(vis[u]++)continue;
        for(unsigned i=0;i<g[u].size();i++){
            int v=g[u][i],w=1;
            if(dis[u]+w<dis[v])dis[v]=dis[u]+w,Q.push(node(v,dis[v]));
        }
    }
    return;
}

void solve(){
    cin>>n>>m;
    for(int i=1,u,v;i<=m;i++){
        cin>>u>>v;
        g[u].push_back(v);
        if(u==1)g[n+1].push_back(v);
    }
    ++n;
    Dij();
    ans=dis[1];
    if(ans==inf)ans=-1;
    printf("%d\n",ans);
}

signed main(){
    
    int t = 1; // cin >> t;
    while(t--) solve();
    return 0;
}
