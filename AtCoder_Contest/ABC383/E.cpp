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
//#define int long long

using namespace std;

const int inf = 1.01e9;
const int mod = 998244353;
const int N = 1e6 + 10;
int n,m,k,a[N],b[N],ca[N],cb[N],fa[N];
long long ans;
struct edge{
    int u,v,w;
    bool operator < (const edge& _)const{
        return w<_.w;
    } 
}e[N];

int Find(int x){
    if(fa[x]!=x)fa[x]=Find(fa[x]);
    return fa[x];
}

void solve(){
    cin>>n>>m>>k;
    for(int i=1;i<=m;i++)cin>>e[i].u>>e[i].v>>e[i].w;
    for(int i=1;i<=k;i++){
        cin>>a[i];
        ++ca[a[i]];
    }
    for(int i=1;i<=k;i++){
        cin>>b[i];
        ++cb[b[i]];
    }
    sort(e+1,e+m+1);
    for(int i=1;i<=n;i++)fa[i]=i;
    for(int i=1;i<=m;i++){
        int u=Find(e[i].u),v=Find(e[i].v);
        if(u!=v){
            fa[v]=u;
            ca[u]+=ca[v];
            cb[u]+=cb[v];
            int t=min(ca[u],cb[u]);
            ans+=1ll*t*e[i].w;
            ca[u]-=t,cb[u]-=t;
        }
    }
    printf("%lld\n",ans);
}

signed main(){

    // freopen(".in", "r", stdin);
    // freopen(".out", "w", stdout);
  
    
    int t = 1; // cin >> t;
    while(t--) solve();
    return 0;
}
