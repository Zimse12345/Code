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
int n,vis[N],fa[N],cnt[N],pos,son[N],a[N],m;
vector<int> g[N];

int query(int x){
    printf("? %d\n",x);
    fflush(stdout);
    int res;
    cin>>res;
    return res;
}

void dfs(int u,int from){
    cnt[u]=1,son[u]=0,fa[u]=from;
    for(unsigned i=0;i<g[u].size();i++){
        int v=g[u][i];
        if(vis[v]||v==from)continue;
        dfs(v,u);
        cnt[u]+=cnt[v],++son[u];
    }
    return;
}

void solve(){
    cin>>n;
    for(int i=1,u,v;i<n;i++){
        cin>>u>>v;
        g[u].push_back(v);
        g[v].push_back(u);
        vis[i]=0;
    }
    pos=1;
    dfs(1,0);
    int T=0,tag=0;
    for(int i=1;i<=n;i++)if(cnt[i]==1){
        T=i;
        if(query(i)){
            tag=1;
        }
        break;
    }
    if(tag){
        printf("! %d\n",T);
        fflush(stdout);
        return;
    }
    while(1){
        dfs(1,0);
        while(son[pos]==1){
            for(unsigned i=0;i<g[pos].size();i++){
                if(!vis[g[pos][i]]&&g[pos][i]!=fa[pos]){
                    pos=g[pos][i];
                    break;
                }
            }
        }
        if(!son[pos])break;
        unsigned mx=n+1;
        for(unsigned i=0;i<g[pos].size();i++)if(g[pos][i]!=fa[pos]&&(mx>n||cnt[g[pos][i]]>cnt[g[pos][mx]]))mx=i;
        if(query(g[pos][mx]))pos=g[pos][mx],query(T);
        else vis[g[pos][mx]]=1;
        for(int i=1;i<=n;i++){
            if(!son[i])vis[i]=1;
            son[i]=0;
        }
        if(vis[pos])break;
    }
    m=0;
    while(pos)a[++m]=pos,pos=fa[pos];
    for(int i=1;i<=m;i++)query(T);
    int L=m;
//    int L=1,R=m;
//    while(L<R){
//        int M=(L+R)/2;
//        if(query(a[M]))R=min(M+1,m),L=min(L+1,m),query(T);
//        else R=min(m,R+1),L=min(M+2,m);
//    }
    printf("! %d\n",a[L]);
    fflush(stdout);
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

