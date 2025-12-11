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
int n,x;
char s[N]; 
inline void solve() {
    cin>>n>>x;
    scanf("%s",s+1);
    s[n+1]=' ';
    int l=x,r=x;
    while(l>0&&s[l]!='#')--l;
    while(r<=n&&s[r]!='#')++r;
    int ans=max(min(l+1,n-x+1),min(n-r+2,x));
    printf("%d\n",ans);
}
int main() {
    int _ = 1; cin >> _;
    while (_--) solve();
    return 0;
}
