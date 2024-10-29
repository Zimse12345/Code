#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <stack>
#include <set>
#include <map>
#include <list>
#include <math.h>
#include <cstring> 

#define endl '\n'
#define pii pair<int, int>
#define pdd pair<double, double> 
#define fi first
#define se second
#define pb push_back
#define eb emplace_back
#define codeforces cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(false)
#define bendl(x) x.begin(), x.end()
#define siz(x) ((int)(x).size())
#define int long long

using namespace std;

const int inf = 1ll << 60;
const int mod = 998244353;
const int N = 512, M = 2.01e5;
int n,m,q,u[M],v[M],w[M],d[N][N],qx[M],qy[M],tag[M],ans[M];

void solve(){
    cin>>n>>m>>q;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++)d[i][j]=inf;
        d[i][i]=0;
    }
    for(int i=1;i<=m;i++){
        cin>>u[i]>>v[i]>>w[i];
    }
    for(int i=1,ty;i<=q;i++){
        cin>>ty;
        cin>>qx[i];
        if(ty==2)cin>>qy[i];
        else tag[qx[i]]=1;
    }
    for(int i=1;i<=m;i++)if(!tag[i]){
        d[u[i]][v[i]]=min(d[u[i]][v[i]],w[i]);
        d[v[i]][u[i]]=min(d[v[i]][u[i]],w[i]);
    }
    for(int mid=1;mid<=n;mid++){
        for(int i=1;i<=n;i++){
            for(int j=1;j<=n;j++){
                d[i][j]=min(d[i][j],d[i][mid]+d[mid][j]);
            }
        }
    }
    for(int i=q;i>=1;i--){
        if(!qy[i]){
            int U=u[qx[i]],V=v[qx[i]],W=w[qx[i]];
            for(int x=1;x<=n;x++){
                for(int y=1;y<=n;y++){
                    d[x][y]=min(d[x][y],min(d[x][U]+d[V][y]+W,d[x][V]+d[U][y]+W));
                }
            }
        }
        else ans[i]=d[qx[i]][qy[i]];
    }
    for(int i=1;i<=q;i++)if(qy[i]){
        if(ans[i]>=inf)ans[i]=-1;
        printf("%lld\n",ans[i]);
    }
}

signed main(){
    
    int t = 1; // cin >> t;
    while(t--) solve();
    return 0;
}
