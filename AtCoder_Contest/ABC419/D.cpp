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
int n,m,a[N];
char s[N],t[N];

inline void solve() {
    cin>>n>>m;
    scanf("%s",s+1);
    scanf("%s",t+1);
    while(m--){
        int l,r;
        cin>>l>>r;
        a[l]^=1,a[r+1]^=1;
    }
    for(int i=1;i<=n;i++){
        a[i]^=a[i-1];
        if(a[i])putchar(t[i]);
        else putchar(s[i]);
    }
}
signed main() {
    int _ = 1; //cin >> _;
    while (_--) solve();
    return 0;
}
