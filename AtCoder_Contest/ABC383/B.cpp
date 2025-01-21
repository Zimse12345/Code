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
const int N = 16;
int n,m,d,ans,cnt;
char s[N][N];
int _abs(int x){return x<0?-x:x;}

void solve(){
    cin>>n>>m>>d;
    for(int i=1;i<=n;i++)scanf("%s",s[i]+1);
    for(int ax=1;ax<=n;ax++){
        for(int ay=1;ay<=m;ay++)if(s[ax][ay]=='.'){
            for(int bx=ax;bx<=n;bx++){
                for(int by=1;by<=m;by++)if(s[bx][by]=='.'){
                    for(int x=1;x<=n;x++){
                        for(int y=1;y<=m;y++)if(s[x][y]=='.'){
                            if(_abs(x-ax)+_abs(y-ay)<=d||_abs(x-bx)+_abs(y-by)<=d)++cnt;
                        }
                    }
                    ans=max(ans,cnt);
                    cnt=0;
                }
            }
        }
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
