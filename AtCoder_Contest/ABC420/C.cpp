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
int n,q,a[N],b[N];
inline void solve() {
    cin>>n>>q;
    for(int i=1;i<=n;i++)cin>>a[i];
    for(int i=1;i<=n;i++)cin>>b[i];
    long long s=0;
    for(int i=1;i<=n;i++)s+=min(a[i],b[i]);
    while(q--){
        char c=getchar();
        int x=0,y=0;
        while(c!='A'&&c!='B')c=getchar();
        cin>>x>>y;
        s-=min(a[x],b[x]);
        if(c=='A')a[x]=y;
        else b[x]=y;
        s+=min(a[x],b[x]);
        printf("%lld\n",s);
    }
}
int main() {
    int _ = 1; //cin >> _;
    while (_--) solve();
    return 0;
}

