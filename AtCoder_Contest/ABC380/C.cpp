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
    int n,k;
    cin>>n>>k;
    scanf("%s",s+1);
    int t=0,pre=0;
    for(int i=1;i<=n;){
        if(s[i]=='0')++i;
        else{
            int l=i;
            while(s[i]=='1')++i;
            int r=i-1;
            ++t;
            if(t==k){
                for(int j=l;j<=r;j++){
                    s[j]='0';
                    s[pre]='1';
                    ++pre;
                }
                break;
            }
            pre=i;
        }
    }
    for(int i=1;i<=n;i++)printf("%c",s[i]);
}

signed main(){

    // freopen(".in", "r", stdin);
    // freopen(".out", "w", stdout);
  
    // codeforces;
    
    int t = 1; // cin >> t;
    while(t--) solve();
    return 0;
}
