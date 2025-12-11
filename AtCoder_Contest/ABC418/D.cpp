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
int n,x,y,ans;
char s[N];
inline void solve() {
    cin>>n;
    scanf("%s",s+1);
    for(int i=1;i<=n;i++){
        if(s[i]=='0'){
            swap(x,y);
            ++y;
        }
        else ++x;
        ans+=x;
    }
    printf("%lld\n",ans);
}
signed main() {
    int _ = 1; 
    while (_--) solve();
    return 0;
}
