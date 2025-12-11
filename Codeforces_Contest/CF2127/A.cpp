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
    int p=0;
    for(int i=1;i<=n;i++)cin>>a[i];
    for(int i=1;i<=n;i++){
        if(a[i]==0){
            printf("NO\n");
            return;
        }
        if(a[i]!=-1){
            if(p==0)p=a[i];
            else if(p!=a[i])p=-1;
        }
    }
    if(p==-1)printf("NO\n");
    else printf("YES\n");
}
int main() {
    int _ = 1; cin >> _;
    while (_--) solve();
    return 0;
}
