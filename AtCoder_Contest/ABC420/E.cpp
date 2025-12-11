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
int n,q,fa[N],cnt[N],c[N];
int F(int x){
    if(fa[x]!=x)fa[x]=F(fa[x]);
    return fa[x];
}
inline void solve() {
    cin>>n>>q;
    for(int i=1;i<=n;i++)fa[i]=i;
    while(q--){
        int ty=0,u=0,v=0;
        cin>>ty>>u;
        if(ty==1){
            cin>>v;
            u=F(u),v=F(v);
            if(u^v)fa[v]=u,cnt[u]+=cnt[v];
        }
        if(ty==2){
            c[u]^=1;
            v=F(u);
            if(c[u]==1)++cnt[v];
            else --cnt[v];
        }
        if(ty==3){
            if(cnt[F(u)])printf("Yes\n");
            else printf("No\n");
        }
    }
}
int main() {
    int _ = 1; //cin >> _;
    while (_--) solve();
    return 0;
}

