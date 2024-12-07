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
int p1[N],p2[N],ans;
void solve(){
    cin>>n;
    scanf("%s",s+1);
    for(int i=1;i<=n;i++){
        if(s[i]=='1')p1[i]=1+p1[i-1];
    }
    for(int i=n;i>=1;i--){
        if(s[i]=='2')p2[i]=1+p2[i+1];
        if(s[i]=='/')ans=max(ans,1+min(p1[i-1],p2[i+1])*2);
    }
    printf("%d\n",ans);
}

signed main(){

    // freopen(".in", "r", stdin);
    // freopen(".out", "w", stdout);
  
    
    int t = 1; // cin >> t;
    while(t--) solve();
    return 0;
}
