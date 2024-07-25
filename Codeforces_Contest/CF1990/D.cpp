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
int n,a[N],f[N][4];

void solve(){
    cin>>n;
    f[0][1]=f[0][2]=f[0][3]=inf;
    for(int i=1;i<=n;i++){
        cin>>a[i];
        f[i][1]=f[i][2]=f[i][3]=inf;
        f[i][0]=min(min(f[i-1][0],f[i-1][1]),min(f[i-1][2],f[i-1][3]))+1;
        if(a[i]==4||a[i]==3){
            f[i][0]=min(f[i][0],f[i-1][3]);
            f[i][1]=f[i-1][2]+1;
            f[i][2]=f[i-1][1]+1;
            f[i][3]=f[i-1][0]+2;
        }
        if(a[i]==2||a[i]==1){
            f[i][0]=min(f[i][0],min(f[i-1][3],f[i-1][1]));
            f[i][1]=f[i-1][0]+1;
        }
        if(a[i]==0)f[i][0]=min(min(f[i-1][0],f[i-1][1]),min(f[i-1][2],f[i-1][3]));
    }
    printf("%d\n",min(min(f[n][0],f[n][1]),min(f[n][2],f[n][3])));
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

