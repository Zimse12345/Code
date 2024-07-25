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
//#define int long long

using namespace std;

const int inf = 1e9 + 7;
const int mod = 1e9 + 7;
const int N = 5e3 + 10, M = N << 1;
int n,C[N][N];

int c(int x,int y){
    if(x<0||x>=N||y<0||y>=N)return 0;
    return C[x][y];
}

void solve(){
    cin>>n;
    int ans=0;
    for(int i=1;i<=n*2+1;i++){
        for(int j=0;j<=min(n,i-1);j++){
            int a=i-j-1,b=j-a;
            ans=(ans+1ll*i*c(min(i-1,n),a)%mod*c(max(n-i,0),b)%mod)%mod;
        }
    }
    printf("%d\n",ans);
}

signed main(){

    // freopen(".in", "r", stdin);
    // freopen(".out", "w", stdout);
  
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    
    C[0][0]=1;
    for(int i=1;i<N;i++){
        C[i][0]=1;
        for(int j=1;j<=i;j++)C[i][j]=(C[i-1][j]+C[i-1][j-1])%mod;
    }
    
    int t = 1;  cin >> t;
    while(t--) solve();
    return 0;
}
