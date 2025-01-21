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

int n,m,k,ans,a[N],b[N];
struct node{
    int x,y;
    node(int x=0,int y=0):x(x),y(y){}
    bool operator < (const node& _)const{return x<_.x;}
}s[N];
void solve(){
    cin>>n>>k;
    m=ans=0;
    for(int i=1;i<=n;i++){
        cin>>a[i];
        s[++m]=node(a[i]+1,1);
    }
    for(int i=1;i<=n;i++){
        cin>>b[i];
        s[++m]=node(b[i]+1,2);
    }
    sort(s+1,s+m+1);
    ans=n*(s[1].x-1);
    for(int i=1,cnt=n,t=0;i<=m;i++){
        if(s[i].y==1)++t;
        if(s[i].y==2)--t,--cnt;
        if(s[i].x!=s[i+1].x&&t<=k)ans=max(ans,cnt*(s[i+1].x-1));
    }
    printf("%lld\n",ans);
}

signed main(){

    // freopen(".in", "r", stdin);
    // freopen(".out", "w", stdout);
  
    
    int t = 1;  cin >> t;
    while(t--) solve();
    return 0;
}
