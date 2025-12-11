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
int x,y;
inline void solve() {
    cin>>x>>y;
    if(x<y)printf("2\n");
    else if(x-1>y&&y>1)printf("3\n");
    else printf("-1\n");
}
int main() {
    int _ = 1; cin >> _;
    while (_--) solve();
    return 0;
}

