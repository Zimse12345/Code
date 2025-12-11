#include <bits/stdc++.h>
#define LOG(FMT...) fprintf(stderr, FMT)
using namespace std;
typedef long long LL;
const int N = 1e2 + 10;
int read(){
    int x = 0,f = 1; char ch = getchar();
    while (ch < '0' || ch > '9') {if (ch == '-') f = -1; ch = getchar();}
    while (ch >= '0' && ch <= '9') {x = x * 10 + ch - '0'; ch = getchar();}
    return x * f;
}
int n,m,a[N];
char s[N][N];
inline void solve() {
    cin>>n>>m;
    for(int i=1;i<=n;i++)scanf("%s",s[i]+1);
    for(int i=1;i<=m;i++){
        int x=0,y=0;
        for(int j=1;j<=n;j++){
            if(s[j][i]=='1')++y;
            else ++x;
        }
        if(x==0||y==0)continue;
        for(int j=1;j<=n;j++){
            if(s[j][i]=='1'&&y<x)++a[j];
            if(s[j][i]=='0'&&x<y)++a[j];
        }
    }
    int mx=0;
    for(int i=1;i<=n;i++)mx=max(mx,a[i]);
    for(int i=1;i<=n;i++)if(mx==a[i])printf("%d ",i);
}
int main() {
    int _ = 1; //cin >> _;
    while (_--) solve();
    return 0;
}
