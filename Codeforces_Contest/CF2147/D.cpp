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
int n,a[N],b[N],m,x,y;
inline void solve() {
    cin>>n;
    m=0,x=y=0;
    for(int i=1;i<=n;i++)cin>>a[i];
    sort(a+1,a+n+1);
    for(int l=1,r=0;l<=n;){
        r=l;
        while(r<n&&a[r+1]==a[l])++r;
        int len=r-l+1;
        if(a[l]&1){
            b[++m]=len;
            
        }
        x+=(a[l]/2)*len;
        l=r+1;
    }
    y=x;
    sort(b+1,b+m+1);
    for(int i=1;i<=m;i++){
        if((m-i)&1)y+=b[i];
        else x+=b[i];
    }
    printf("%lld %lld\n",x,y);
}
signed main() {
    int _ = 1; cin >> _;
    while (_--) solve();
    return 0;
}

