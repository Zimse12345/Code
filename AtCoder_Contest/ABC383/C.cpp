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
const int N = 1024;
int n,m,d,vis[N][N],l,r,x[N*N],y[N*N],t[N*N];
char s[N][N];

void solve(){
    cin>>n>>m>>d;
    l=1;
    for(int i=1;i<=n;i++){
        scanf("%s",s[i]+1);
        for(int j=1;j<=m;j++)if(s[i][j]=='H'){
            ++r;
            x[r]=i;
            y[r]=j;
            vis[i][j]=1;
        }
    }
    int wx[4]={1,-1,0,0},wy[4]={0,0,-1,1};
    while(l<=r){
        if(t[l]==d){
            ++l;
            continue;
        }
        for(int w=0;w<4;w++){
            int _x=x[l]+wx[w],_y=y[l]+wy[w];
            if(1<=_x&&_x<=n&&1<=_y&&_y<=m){
                if(s[_x][_y]=='.'&&!vis[_x][_y]){
                    ++r;
                    x[r]=_x,y[r]=_y,t[r]=t[l]+1;
                    vis[_x][_y]=1;
                }
            }
        }
        ++l;
    }
    printf("%d\n",r);
}

signed main(){

    // freopen(".in", "r", stdin);
    // freopen(".out", "w", stdout);
  
    
    int t = 1; // cin >> t;
    while(t--) solve();
    return 0;
}
