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
#define codeforces cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(false)
#define bendl(x) x.begin(), x.end()
#define siz(x) ((int)(x).size())
#define int long long

using namespace std;

const int inf = 1 << 30;
const int mod = 998244353;
const int N = 1e6 + 10, M = N << 1;
int n,k;
struct node{
    int x,y;
    node(int x=0,int y=0):x(x),y(y){}
    bool operator < (const node& _)const{return x<_.x;}
}p[N];
priority_queue<int> Q;
int sum;

void solve(){
    cin>>n>>k;
    for(int i=1;i<=n;i++)cin>>p[i].x;
    for(int i=1;i<=n;i++)cin>>p[i].y;
    sort(p+1,p+n+1);
    while(!Q.empty())Q.pop();
    sum=0;
    for(int i=1;i<=k;i++)Q.push(p[i].y),sum+=p[i].y;
    int ans=p[k].x*sum;
    for(int i=k+1;i<=n;i++){
        Q.push(p[i].y),sum+=p[i].y;
        sum-=Q.top(),Q.pop();
        ans=min(ans,sum*p[i].x);
    }
    printf("%lld\n",ans);
}

signed main(){
    
    int t = 1;  cin >> t;
    while(t--) solve();
    return 0;
}
