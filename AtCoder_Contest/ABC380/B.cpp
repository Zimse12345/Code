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
const int N = 2e5 + 10;
char s[N];

void solve(){
    scanf("%s",s+1);
    int n=strlen(s+1);
    for(int i=1;i<=n;){
        if(s[i]=='|')++i;
        else{
            int c=0;
            while(s[i]=='-')++i,++c;
            printf("%d ",c);
        }
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
