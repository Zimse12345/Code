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
    scanf("%s",s+1);
    n=strlen(s+1);
    double ans=0;
    for(int i=1;i<=n;i++)if(s[i]=='t'){
        for(int j=i+2;j<=n;j++)if(s[j]=='t'){
            int c=0;
            for(int k=i+1;k<j;k++)if(s[k]=='t')++c;
            ans=max(ans,double(c)/double(j-i-1));
        }
    }
    printf("%.9lf\n",ans);
}
int main() {
    int _ = 1; 
    while (_--) solve();
    return 0;
}
