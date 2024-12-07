#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <stack>
#include <set>
#include <map>
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

int n,vis[N];
char s[N]; 
void solve(){
    scanf("%s",s+1);
    n=strlen(s+1);
    if(n%2==1){
        printf("No\n");
        return;
    }
    int tag=1;
    for(int i=1;i<=n/2;i++){
        if(s[i*2]!=s[i*2-1])tag=0;
        if(vis[s[i*2]])tag=0;
        vis[s[i*2]]=1;
    }
    if(tag)printf("Yes\n");
    else printf("No\n");
}

signed main(){

    // freopen(".in", "r", stdin);
    // freopen(".out", "w", stdout);
  
    
    int t = 1; // cin >> t;
    while(t--) solve();
    return 0;
}
