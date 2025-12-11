#include <bits/stdc++.h>
#define LOG(FMT...) fprintf(stderr, FMT)
using namespace std;
typedef long long LL;
const int N = 1e6 + 10,Mod=1000000007;
int read(){
    int x = 0,f = 1; char ch = getchar();
    while (ch < '0' || ch > '9') {if (ch == '-') f = -1; ch = getchar();}
    while (ch >= '0' && ch <= '9') {x = x * 10 + ch - '0'; ch = getchar();}
    return x * f;
}
int n,k,w[N],c[N],fa[N],stk[N],t;
long long ans;
vector<int> g[N];
set<int> s[N];

void dfs(int u,int from){
    fa[u]=from;
    int C=0;
    for(unsigned i=0;i<g[u].size();i++){
        int v=g[u][i];
        if(v==from)continue;
        dfs(v,u);
        if(s[v].size()>s[u].size())swap(s[u],s[v]);
        for(set<int>::iterator it=s[v].begin();it!=s[v].end();it++){
            if(s[u].find(*it)!=s[u].end()){
                if(C==0||C==*it)C=*it;
                else C=-1;
            }
            else s[u].insert(*it);
        }
        s[v].clear();
    }
    
    if(C==-1)ans+=w[u];
    else if(C>0){
        if(c[u]&&c[u]!=C)ans+=w[u];
        else c[u]=C;
    }
    if(c[u]!=0)s[u].insert(c[u]);
    return;
}

inline void solve() {
    cin>>n>>k;
    ans=0;
    for(int i=1;i<=n;i++)cin>>w[i];
    for(int i=1;i<=n;i++)cin>>c[i];
    for(int i=1,u,v;i<n;i++){
        cin>>u>>v;
        g[u].push_back(v);
        g[v].push_back(u);
    }
    dfs(1,0);
    for(int i=1;i<=n;i++)if(!c[i]){
        t=1,stk[1]=i;
        int x=i;
        while(fa[x]&&!c[fa[x]])x=fa[x],stk[++t]=x;
        int C=c[fa[x]];
        if(!C)C=1;
        for(int j=1;j<=t;j++)c[stk[j]]=C;
    }
    printf("%lld\n",ans);
    for(int i=1;i<=n;i++)printf("%d ",c[i]);
    printf("\n");
    for(int i=1;i<=n;i++){
        g[i].resize(0);
        s[i].clear();
    }
    return;
}
signed main() {
    int _ = 1; cin >> _;
    while (_--) solve();
    return 0;
}
