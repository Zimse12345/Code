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
const int N = 1.01e6;
int n,q;
struct node{
    int x,y;
    node(int x=0,int y=0):x(x),y(y){}
    bool operator < (const node& _)const{return x<_.x;}
}p[N];
map<int,int> mp;

void solve(){
    cin>>n;
    for(int i=1;i<=n;i++)cin>>p[i].x;
    for(int i=1;i<=n;i++)cin>>p[i].y;
    sort(p+1,p+n+1);
    mp[-inf]=0;
    for(int i=1,s=0;i<=n;i++){
        s+=p[i].y,mp[p[i].x]=s;
        if(i==n)mp[inf]=s;
    }
    cin>>q;
    while(q--){
        int l,r;
        cin>>l>>r;
        map<int,int>::iterator R=mp.upper_bound(r),L=mp.lower_bound(l);
        --L,--R;
        printf("%lld\n",R->second-L->second);
    }
    return; 
}

signed main(){
    int t = 1; // cin >> t;
    while(t--) solve();
    return 0;
}


