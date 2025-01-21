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
#define int long long

using namespace std;

const int inf = 1.01e9;
const int mod = 998244353;
const int N = 1e6 + 10;
const double eps=1e-10;

int n,x[N],y[N],c;
long double ans=-1;

void solve(){
    cin>>n;
    for(int i=1;i<=n;i++){
        ++c;
        cin>>x[c]>>y[c];
        while(c>2&&(y[c-1]-y[c])*(x[c-1]-x[c-2])<(y[c-2]-y[c-1])*(x[c]-x[c-1])){
            --c;
            x[c]=x[c+1],y[c]=y[c+1];
        }
        long double A=y[c-1]-y[c],B=x[c]-x[c-1],C=x[c],D=y[c];
        if(c>1)ans=max(ans,A/B*C+D);
    }
    if(ans<-1e-9)printf("-1\n");
    else printf("%.12Lf\n",ans);
}

signed main(){

    // freopen(".in", "r", stdin);
    // freopen(".out", "w", stdout);
  
    
    int t = 1; // cin >> t;
    while(t--) solve();
    return 0;
}
