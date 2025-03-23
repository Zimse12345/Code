#include <bits/stdc++.h>
#define int long long
using namespace std;

const int N=1.01e6;
int n,m,fa[N],sz[N],ans[N],sum;
vector<int> g[N];
char s[N];

int F(int x){
    if(fa[x]!=x)fa[x]=F(fa[x]);
    return fa[x];
}

int calc(int x){
    return x*(x-1)/2;
}

void link(int u,int v){
    u=F(u),v=F(v);
    if(u!=v){
        fa[v]=fa[u];
        sum+=calc(sz[u]+sz[v])-calc(sz[u])-calc(sz[v]);
        sz[u]+=sz[v];
    }
    return;
}

signed main(){
    cin>>n>>m;
    scanf("%s",s+1);
    for(int i=1;i<=n;i++)fa[i]=i;
    for(int i=1,u,v;i<=m;i++){
        cin>>u>>v;
        g[u].push_back(v);
        g[v].push_back(u);
        if(s[u]=='1'&&s[v]=='1')link(u,v);
    }
    for(int i=n,x=0;i>=1;i--){
        for(unsigned j=0;j<g[i].size();j++){
            if(g[i][j]>i||s[g[i][j]]=='1')link(i,g[i][j]);
        }
        x=F(i);
        sum+=calc(sz[x]+1)-calc(sz[x]);
        ++sz[x];
        ans[i]=sum;
    }
    for(int i=1;i<=n;i++)printf("%lld\n",ans[i]);
    return 0;
}


