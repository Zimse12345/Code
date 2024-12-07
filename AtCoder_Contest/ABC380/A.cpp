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
const int N = 2e5 + 10;
char s[N];

void solve(){
    scanf("%s",s+1);
    int x=0,y=0,z=0;
    for(int i=1;i<=6;i++){
        if(s[i]=='1')++x;
        if(s[i]=='2')++y;
        if(s[i]=='3')++z;
    }
    if(x==1&&y==2&&z==3)printf("Yes\n");
    else printf("No\n");
}

signed main(){

    // freopen(".in", "r", stdin);
    // freopen(".out", "w", stdout);
  
    // codeforces;
    
    int t = 1; // cin >> t;
    while(t--) solve();
    return 0;
}
