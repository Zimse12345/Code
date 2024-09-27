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

using namespace std;

const int inf = 1 << 30;
const int mod = 998244353;
const int N = 2e5 + 10, M = N << 1;
int n,q,f[N],mx[N][12],Mx[12];

inline int F(int x){
    if(f[x]!=x)f[x]=F(f[x]);
    return f[x];
}

void solve(){
    cin>>n>>q;
    for(int i=1;i<=n;i++){
        f[i]=i;
        mx[i][1]=i;
        for(int j=2;j<=11;j++)mx[i][j]=-1;
    }
    while(q--){
        int t,u,v;
        cin>>t>>u>>v;
        if(t==1){
            u=F(u),v=F(v);
            if(u!=v){
                f[v]=u;
                int p1=1,p2=1;
                for(int i=1;i<=10;i++){
                    if(mx[u][p1]>mx[v][p2])Mx[i]=mx[u][p1],++p1;
                    else Mx[i]=mx[v][p2],++p2;
                }
                for(int i=1;i<=10;i++)mx[u][i]=Mx[i];
            }
        }
        else printf("%d\n",mx[F(u)][v]);
    }
}

signed main(){

    // freopen(".in", "r", stdin);
    // freopen(".out", "w", stdout);
  
//    codeforces;
    
    int t = 1; // cin >> t;
    while(t--) solve();
    return 0;
}
