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
const int N = 512, M = N << 1;
int n,m,t[N][N];
char a[N][N],b[N][N];

void solve(){
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        scanf("%s",a[i]+1);
    }
    for(int i=1;i<=n;i++){
        scanf("%s",b[i]+1);
    }
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            int x=a[i][j]-'0',y=b[i][j]-'0';
            t[i][j]=y-x+3;
        }
    }
    for(int i=1;i<n;i++){
        for(int j=1;j<m;j++)if(t[i][j]%3!=0){
            if(t[i][j]%3==1)t[i+1][j+1]+=2,t[i][j]+=2,t[i+1][j]+=1,t[i][j+1]+=1;
            if(t[i][j]%3==2)t[i+1][j+1]+=1,t[i][j]+=1,t[i+1][j]+=2,t[i][j+1]+=2;
        }
    }
    int tag=1;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            if(t[i][j]%3!=0)tag=0;
        }
    }
    if(tag)printf("YES\n");
    else printf("NO\n");
}

signed main(){

    // freopen(".in", "r", stdin);
    // freopen(".out", "w", stdout);
  
    // ios::sync_with_stdio(0);
    // cin.tie(0); cout.tie(0);
    
    int T = 1;  cin >> T;
    while(T--) solve();
    return 0;
}