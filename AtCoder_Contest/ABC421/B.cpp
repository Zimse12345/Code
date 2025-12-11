#include <bits/stdc++.h>
#define int long long
#define LOG(FMT...) fprintf(stderr, FMT)
using namespace std;
typedef long long LL;
const int N = 1e6 + 10;
int read(){
    int x = 0,f = 1; char ch = getchar();
    while (ch < '0' || ch > '9') {if (ch == '-') f = -1; ch = getchar();}
    while (ch >= '0' && ch <= '9') {x = x * 10 + ch - '0'; ch = getchar();}
    return x * f;
}
int s[N],w;
int f(int v){
    w=0;
    while(v)s[++w]=v%10,v/=10;
    for(int i=1;i<=w;i++)v=v*10+s[i];
    return v;
}
int x,y,a[N];
inline void solve() {
    cin>>x>>y;
    a[1]=x,a[2]=y;
    for(int i=3;i<=10;i++)a[i]=f(a[i-1]+a[i-2]);
    printf("%lld\n",a[10]);
}
signed main() {
    int _ = 1; //cin >> _;
    while (_--) solve();
    return 0;
}

