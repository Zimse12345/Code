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
const int N = 4096, M = N << 1;
int n,W,w[N],v[N],f[N];
priority_queue<int> q[N];

void solve(){
    cin>>n>>W;
    for(int i=1;i<=n;i++){
        cin>>w[i]>>v[i];
        q[w[i]].push(v[i]-1);;
    }
    for(int i=1;i<=W;i++)if(!q[i].empty()){
        for(int t=1;t*i<=W;t++){
            int x=q[i].top();
            q[i].pop();
            for(int j=W;j>=i;j--)f[j]=max(f[j],f[j-i]+x);
            q[i].push(x-2);
        }
    }
    int ans=0;
    for(int i=1;i<=W;i++)ans=max(ans,f[i]);
    printf("%lld\n",ans);
}

signed main(){
    
    int t = 1; // cin >> t;
    while(t--) solve();
    return 0;
}
