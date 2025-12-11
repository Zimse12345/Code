#include <bits/stdc++.h>
#define LOG(FMT...) fprintf(stderr, FMT)
using namespace std;
typedef long long LL;
#define int long long
const int N = 1e6 + 10,inf=1e9;
int read(){
    int x = 0,f = 1; char ch = getchar();
    while (ch < '0' || ch > '9') {if (ch == '-') f = -1; ch = getchar();}
    while (ch >= '0' && ch <= '9') {x = x * 10 + ch - '0'; ch = getchar();}
    return x * f;
}
int n,x[N],y[N];

bool ck(int R){
    int l=-inf,r=inf,u=-inf,d=inf;
    for(int i=1;i<=n;i++){
        l=max(l,x[i]-R);
        r=min(r,x[i]+R);
        u=max(u,y[i]-R);
        d=min(d,y[i]+R);
    }
    return l<=r&&u<=d;
}

inline void solve() {
    cin>>n;
    for(int i=1;i<=n;i++)cin>>x[i]>>y[i];
    int l=0,r=inf,ans=inf;
    while(l<=r){
        int mid=(l+r)/2;
        if(ck(mid))ans=mid,r=mid-1;
        else l=mid+1;
    }
    printf("%lld\n",ans);
}
signed main() {
    int _ = 1; //cin >> _;
    while (_--) solve();
    return 0;
}
