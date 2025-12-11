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
int k,x,ans[N],t;
inline void solve() {
    cin>>k>>x;
    t=0;
    int l=x,r=(1ll<<(k+1))-l;
    while(l!=r){
        if(l<r)r-=l,l*=2,ans[++t]=1;
        else l-=r,r*=2,ans[++t]=2;
    }
    printf("%lld\n",t);
    for(int i=t;i>=1;i--)printf("%lld ",ans[i]);
    printf("\n");
}
signed main() {
    int _ = 1; cin >> _;
    while (_--) solve();
    return 0;
}
