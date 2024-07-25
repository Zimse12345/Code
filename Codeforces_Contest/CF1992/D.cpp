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
char s[N];
int n,m,k;

void solve(){
    cin>>n>>m>>k;
    scanf("%s",s+1);
    for(int i=1,rm=m-1;i<=n;i++){
        if(s[i]=='L')rm=m-1;
        else{
            if(rm)--rm;
            else{
                if(s[i]=='W')--k;
                if(s[i]=='C')k=-1;
            }
        }
    }
    if(k<0)printf("NO\n");
    else printf("YES\n");
}

signed main(){

    // freopen(".in", "r", stdin);
//     freopen(".out", "w", stdout);
  
//    ios::sync_with_stdio(0);
//    cin.tie(0); cout.tie(0);
    
    int t = 1;  cin >> t;
    while(t--) solve();
    return 0;
}
