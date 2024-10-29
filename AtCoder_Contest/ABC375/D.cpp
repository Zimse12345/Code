#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <stack>
#include <set>
#include <map>
#include <list>
#include <math.h>
#include <cstring> 

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
const int N = 1.01e6, M = N << 1;
int n,l[256],r[256];
long long ans,sum;
char s[N];

void solve(){
    scanf("%s",s+1);
    n=strlen(s+1);
    for(int i=1;i<=n;i++)++r[s[i]];
    for(int i=1;i<=n;i++){
        sum-=l[s[i]];
        --r[s[i]];
        if(i>1){
            sum+=r[s[i-1]];
            ++l[s[i-1]];
        }
        ans+=sum;
    }
    printf("%lld\n",ans);
}

signed main(){
    
    int t = 1; // cin >> t;
    while(t--) solve();
    return 0;
}
