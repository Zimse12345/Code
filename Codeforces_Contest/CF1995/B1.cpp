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

struct node{
    int x,y;
    node(int x=0,int y=0):x(x),y(y){}
    bool operator < (const node& _)const{
        return x<_.x;
    }
}s[N];
int n,m,a[N],tot;

void solve(){
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    sort(a+1,a+n+1);
    tot=0;
    for(int l=1;l<=n;){
        int r=l;
        while(r<n&&a[r+1]==a[r])++r;
        s[++tot]=node(a[l],r-l+1);
        l=r+1;
    }
    int ans=0;
    for(int i=1;i<=tot;i++)ans=max(ans,s[i].x*min(s[i].y,m/s[i].x));
    for(int i=1;i<tot;i++)if(s[i].x+1==s[i+1].x){
        for(int j=0;j<=s[i].y&&j*s[i].x<=m;j++)ans=max(ans,j*s[i].x+s[i+1].x*min(s[i+1].y,(m-j*s[i].x)/s[i+1].x));
    }
    printf("%lld\n",ans);
}

signed main(){

    // freopen(".in", "r", stdin);
    // freopen(".out", "w", stdout);

    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    int t = 1;  cin >> t;
    while(t--) solve();
    return 0;
}

