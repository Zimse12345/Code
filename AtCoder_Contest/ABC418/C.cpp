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
int a[N],s[N];
int n,m; 
inline void solve() {
    cin>>n>>m;
    for(int i=1;i<=n;i++)cin>>a[i];
    sort(a+1,a+n+1);
    for(int i=1;i<=n;i++)s[i]=s[i-1]+a[i];
    while(m--){
        int b=0;
        cin>>b;
        if(a[n]<b){
            printf("-1\n");
            continue;
        }
        int l=1,r=n,t=0;
        while(l<=r){
            int mid=(l+r)/2;
            if(a[mid]<b)t=mid,l=mid+1;
            else r=mid-1;
        }
        printf("%lld\n",s[t]+(n-t)*(b-1)+1);
    }
}
signed main() {
    int _ = 1; 
    while (_--) solve();
    return 0;
}
