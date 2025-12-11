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
int n;
char s[N];
int _abs(int x){
    return x<0?-x:x;
}
inline void solve() {
    cin>>n;
    scanf("%s",s+1);
    int a=0,b=0;
    for(int i=1,x=1,y=2;i<=n*2;i++){
        if(s[i]=='A'){
            a+=_abs(i-x);
            b+=_abs(i-y);
            x+=2,y+=2;
        }
    }
    printf("%lld\n",min(a,b));
}
signed main() {
    int _ = 1; //cin >> _;
    while (_--) solve();
    return 0;
}

