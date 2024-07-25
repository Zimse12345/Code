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
#define int long long

using namespace std;

const int inf = 1e9 + 7;
const int mod = 998244353;
const int N = 2e5 + 10, M = N << 1;
int n,a[3][N],ans[6],q;

bool dfs(int t,int p,int id){
    if(t==7)return 1;
    for(int i=0;i<3;i++)if(!(t&(1<<i))){
        int sum=0;
        int j=p;
        while(sum<q&&j<n){
            ++j,sum+=a[i][j];
        }
        ans[i*2]=p+1,ans[i*2+1]=j;
        if(sum>=q&&dfs(t|(1<<i),j,id+2)){
            return true;
        }
    }
    return false;
}

void solve(){
    int sum=0;
    cin>>n;
    for(int i=1;i<=n;i++)cin>>a[0][i],sum+=a[0][i];
    q=(sum+2)/3;
    for(int i=1;i<=n;i++)cin>>a[1][i];
    for(int i=1;i<=n;i++)cin>>a[2][i];
    if(dfs(0,0,0)){
        for(int i=0;i<6;i++)printf("%d ",ans[i]);
        printf("\n");
    }
    else printf("-1\n");
}

signed main(){

    // freopen(".in", "r", stdin);
    // freopen(".out", "w", stdout);
  
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    
    int T = 1;  cin >> T;
    while(T--) solve();
    return 0;
}