#include <bits/stdc++.h>
#define LOG(FMT...) fprintf(stderr, FMT)
using namespace std;
typedef long long LL;
#define int long long
const int N = 1e6 + 10,inf=1e18;
int read(){
    int x = 0,f = 1; char ch = getchar();
    while (ch < '0' || ch > '9') {if (ch == '-') f = -1; ch = getchar();}
    while (ch >= '0' && ch <= '9') {x = x * 10 + ch - '0'; ch = getchar();}
    return x * f;
}
int n,x,ans;
struct node{
    int a,b;
    node(int a=0,int b=0):a(a),b(b){}
    bool operator < (const node& _)const{return a<_.a;}
}p[N];
inline void solve() {
    cin>>n>>x;
    ans=0;
    for(int i=1;i<=n;i++)cin>>p[i].a;
    for(int i=1;i<=n;i++){
        cin>>p[i].b;
        if(p[i].b<p[i].a)swap(p[i].a,p[i].b);
        ans+=p[i].b-p[i].a;
    }
    sort(p+1,p+n+1);
    int mn=inf;
    for(int i=2,t=0;i<=n;i++){
        t=max(t,p[i-1].b);
        mn=min(mn,2*(p[i].a-min(p[i].b,t)));
    }
    printf("%lld\n",ans+max(mn,0ll));
}
signed main() {
    int _ = 1; cin >> _;
    while (_--) solve();
    return 0;
}
