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
const int N = 32, M = N << 1;
int n,m1,g1[N][N],m2,g2[N][N],a[N][N],ans=1e9;
int p[N],vis[N]; 

void dfs(int x){
    if(x>n){
        int sum=0;
        for(int i=1;i<=n;i++){
            for(int j=i+1;j<=n;j++){
                int _i=p[i],_j=p[j];
                if(_i>_j)swap(_i,_j);
                if(g1[i][j]!=g2[_i][_j])sum+=a[_i][_j];
            }
        }
        ans=min(ans,sum);
    }
    else{
        for(int i=1;i<=n;i++)if(!vis[i]){
            p[x]=i,vis[i]=1;
            dfs(x+1);
            vis[i]=0;
        }
    }
    return;
}

void solve(){
    cin>>n;
    cin>>m1;
    while(m1--){
        int u,v;
        cin>>u>>v;
        if(u>v)swap(u,v);
        g1[u][v]=1;
    }
    cin>>m2;
    while(m2--){
        int u,v;
        cin>>u>>v;
        if(u>v)swap(u,v);
        g2[u][v]=1;
    }
    for(int i=1;i<=n;i++){
        for(int j=i+1;j<=n;j++){
            cin>>a[i][j];
        }
    }
    dfs(1);
    printf("%d\n",ans);
    return; 
}

signed main(){

    // freopen(".in", "r", stdin);
    // freopen(".out", "w", stdout);
  
//    codeforces;
    
    int t = 1; // cin >> t;
    while(t--) solve();
    return 0;
}


