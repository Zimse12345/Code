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


using namespace std;

const int inf = 1 << 30;
const int mod = 998244353;
const int N = 512, M = N << 1;
int n,f[N][N],sum;

void solve(){
    cin>>n;
    for(int i=0;i<N;i++){
        for(int j=0;j<N;j++)f[i][j]=inf;
    }
    f[0][0]=0;
    for(int i=1,a,b;i<=n;i++){
        cin>>a>>b;
        sum+=b;
        for(int x=min(500,sum);x>=0;x--){
            for(int y=min(500,sum-x);y>=0;y--){
                f[x][y]+=(a==3?0:1);
                if(x>=b)f[x][y]=min(f[x][y],f[x-b][y]+(a==1?0:1));
                if(y>=b)f[x][y]=min(f[x][y],f[x][y-b]+(a==2?0:1));
            }
        }
    }
    if(sum%3==0&&f[sum/3][sum/3]<inf){
        printf("%d\n",f[sum/3][sum/3]);
    }
    else{
        printf("-1");
    }
}

signed main(){
    
    int t = 1; // cin >> t;
    while(t--) solve();
    return 0;
}
