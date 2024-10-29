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
int n;

void solve(){
    cin>>n;
    long double sum=0;
    long double a=0,b=0;
    while(n--){
        long double x,y;
        cin>>x>>y;
        sum+=sqrtl((x-a)*(x-a)+(y-b)*(y-b));
        a=x,b=y;
    }
    sum+=sqrtl(a*a+b*b);
    printf("%.12Lf\n",sum);
}

signed main(){
    
    int t = 1; // cin >> t;
    while(t--) solve();
    return 0;
}
