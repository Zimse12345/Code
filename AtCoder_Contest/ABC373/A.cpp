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

using namespace std;

const int inf = 1 << 30;
const int mod = 998244353;
const int N = 2e5 + 10, M = N << 1;
char s[N];

void solve(){
    int ans=0;
    for(int i=1;i<=12;i++){
        scanf("%s",s+1);
        if(strlen(s+1)==i)++ans;
    }
    printf("%d\n",ans);
}

signed main(){
    
    int t = 1; // cin >> t;
    while(t--) solve();
    return 0;
}
