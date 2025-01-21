#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <stack>
#include <set>
#include <map>
#include <cmath>
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
const int N = 1e3 + 10;

int n,m,x,y,len,cnt,vis[N][N];
char s[N][N],t[N*10];
void solve(){
    cin>>n>>m>>x>>y;
    for(int i=1;i<=n;i++)scanf("%s",s[i]+1);
    scanf("%s",t+1);
    len=strlen(t+1);
    for(int i=1;i<=len;i++){
        if(t[i]=='U'){
            if(x>1&&s[x-1][y]!='#')--x;
        }
        if(t[i]=='D'){
            if(x<n&&s[x+1][y]!='#')++x;
        }
        if(t[i]=='L'){
            if(y>1&&s[x][y-1]!='#')--y;
        }
        if(t[i]=='R'){
            if(y<m&&s[x][y+1]!='#')++y;
        }
        if(s[x][y]=='@'&&!vis[x][y]){
            vis[x][y]=1;
            ++cnt;
        }
    }
    printf("%d %d %d\n",x,y,cnt);
}

signed main(){

    // freopen(".in", "r", stdin);
    // freopen(".out", "w", stdout);
  
    
    int t = 1; // cin >> t;
    while(t--) solve();
    return 0;
}
