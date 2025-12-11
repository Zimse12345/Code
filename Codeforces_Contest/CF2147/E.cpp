#include <bits/stdc++.h>
#define LOG(FMT...) fprintf(stderr, FMT)
using namespace std;
typedef long long LL;
#define int long long
const int N = 1e6 + 10;
int read(){
    int x = 0,f = 1; char ch = getchar();
    while (ch < '0' || ch > '9') {if (ch == '-') f = -1; ch = getchar();}
    while (ch >= '0' && ch <= '9') {x = x * 10 + ch - '0'; ch = getchar();}
    return x * f;
}
int n,m,a[N],_a[N],ans[N];

int calc(int mx){
    int res=0;
    for(int i=1;i<=n;i++)_a[i]=a[i];
    for(int j=mx;j>=0;j--){
        int x=0;
        for(int i=1;i<=n;i++)x|=_a[i];
        if(x&(1ll<<j))continue;
        int mn=(1ll<<j),p=0;
        for(int i=1;i<=n;i++){
            int v=(_a[i]&((1ll<<j)-1));
            v=(1ll<<j)-v;
            if(v<mn)mn=v,p=i;
        }
        _a[p]+=mn,res+=mn;
    }
    return res;
}

inline void solve() {
    cin>>n>>m;
    int z=0,bc=0;
    for(int i=1;i<=n;i++)cin>>a[i],z|=a[i];
    for(int j=0;j<32;j++)if(z&(1ll<<j))++bc;
    for(int j=0;j<=bc;j++)ans[j]=0;
    for(int j=0;j<32;j++)if((z&(1ll<<j))==0){
        ++bc;
        ans[bc]=calc(j);
    }
    ans[32]=1.01e9;
    while(m--){
        int b=0;
        cin>>b;
        int x=0;
        while(ans[x+1]<=b)++x;
        printf("%lld\n",x);
    }
}
signed main() {
    int _ = 1; cin >> _;
    while (_--) solve();
    return 0;
}

