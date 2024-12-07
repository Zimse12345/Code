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
const int N = 1e6 + 10;

int n;
char s[N]; 
void solve(){
    cin>>n;
    scanf("%s",s+1);
    if(n%2==0){
        printf("No\n");
        return;
    }
    int tag=1;
    int mid=n/2+1;
    if(s[mid]!='/')tag=0;
    for(int i=1;i<=n;i++){
        if(i<mid&&s[i]!='1')tag=0;
        if(i>mid&&s[i]!='2')tag=0;
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
