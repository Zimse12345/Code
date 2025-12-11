#include <bits/stdc++.h>
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
int n,a[N];
inline void solve() {
    cin>>n;
    for(int i=n-1,l=2,r=n*2;i>=1;i--){
        a[l]=a[r]=i;
        ++l,--r;
    }
    a[1]=a[n+1]=n;
    for(int i=1;i<=n*2;i++)printf("%d ",a[i]);
    printf("\n");
}
int main() {
    int _ = 1; cin >> _;
    while (_--) solve();
    return 0;
}

