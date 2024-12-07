#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <stack>
#include <set>
#include <map>
#include <math.h>
#include <cstring>

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
const int N = 1e6 + 10;
char s[N];

void solve(){
    int q,n;
    scanf("%s",s+1);
    n=strlen(s+1),s[0]=s[n];
    cin>>q;
    while(q--){
        long long k;
        cin>>k;
        int t=0;
        for(long long i=0;i<=60;i++)if(((k-1)/n)&(1ll<<i))t^=1;
        char c=s[k%n];
        if(t){
            if('A'<=c&&c<='Z')c=c-'A'+'a';
            else c=c-'a'+'A';
        }
        printf("%c ",c);
    }
}

signed main(){

    // freopen(".in", "r", stdin);
    // freopen(".out", "w", stdout);
  
    // codeforces;
    
    int t = 1; // cin >> t;
    while(t--) solve();
    return 0;
}
