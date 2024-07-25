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
int n,x,y;

void solve(){
    cin>>n>>x>>y;
    int mid=x-y+1,A=y-1,B=n-x;
    for(int i=1,t=(A&1)?-1:1;i<=A;i++)printf("%d ",t),t=-t;
    for(int i=1;i<=mid;i++)printf("1 ");
    for(int i=1,t=-1;i<=B;i++)printf("%d ",t),t=-t;
    printf("\n");
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

