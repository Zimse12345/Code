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
char s[N];
int n; 
inline void solve() {
    cin>>n;
    scanf("%s",s+1);
    if(n>=3&&s[n-2]=='t'&&s[n-1]=='e'&&s[n]=='a')printf("Yes\n");
    else printf("No\n");
}
int main() {
    int _ = 1; 
    while (_--) solve();
    return 0;
}
