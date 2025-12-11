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
int n,f[N][6];
char s[N];
inline void solve() {
    cin>>n;
    scanf("%s",s+1);
    f[0][1]=1;
    for(int i=1;i<=n;i++){
        int pre=0;
        for(int s=0;s<6;s++)f[i][s]=0,pre|=f[i-1][s];
        if(s[i]=='1'){
            f[i][0]=(f[i-1][0]|f[i-1][1]);
            f[i][3]=(f[i-1][2]);
        }
        else{
            f[i][1]=(f[i-1][1]|f[i-1][2]|f[i-1][3]|f[i-1][4]|f[i-1][5]);
            f[i][2]=(f[i-1][0]|f[i-1][1]|f[i-1][2]);
        }
    }
    if(f[n][0]|f[n][1]|f[n][2])printf("Yes\n");
    else printf("No\n");
}
int main() {
    int _ = 1; cin >> _;
    while (_--) solve();
    return 0;
}

