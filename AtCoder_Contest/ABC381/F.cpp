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
const int N = 1<<20;

int n,a[N],nxt[N][32],mn[N],ans;
void solve(){
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>a[i];
        --a[i];
    }
    for(int v=0;v<20;v++)nxt[n+1][v]=n+1,nxt[n+2][v]=n+1;
    for(int i=n;i>=1;i--){
        for(int v=0;v<20;v++)nxt[i][v]=nxt[i+1][v];
        nxt[i][a[i]]=i;
    }
    for(int i=1;i<N;i++)mn[i]=n+1;
    for(int i=0;i<N;i++)if(mn[i]<=n){
        int pc=0;
        for(int v=0;v<20;v++){
            if(i&(1<<v)){
                ++pc;
                continue;
            }
            int p=nxt[nxt[mn[i]+1][v]+1][v];
            int j=(i|(1<<v));
            mn[j]=min(mn[j],p);
        }
        if(mn[i]<=n)ans=max(ans,pc*2);
    }
    printf("%d\n",ans);
}

signed main(){

    // freopen(".in", "r", stdin);
    // freopen(".out", "w", stdout);
  
    
    int t = 1; // cin >> t;
    while(t--) solve();
    return 0;
}
