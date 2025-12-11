#include <bits/stdc++.h>
#define int long long
using namespace std;

const int N=1.01e6,inf=1e10;
int T,n,k,a[N],f[N],t[N];
int tag;
vector<int> g[N];
vector<int> s[N],s2[N];

void dfs(int u,int from){
    for(unsigned i=0;i<g[u].size();i++){
        int v=g[u][i];
        if(v==from)continue;
        dfs(v,u);
        if(t[v]==1)s[u].push_back(f[v]);
        if(t[v]==2)s2[u].push_back(f[v]);
    }
    sort(s2[u].begin(),s2[u].end());
    int sz2=s2[u].size();
    int v1=inf,v2=inf;
    if(sz2>0)v1=s2[u][0];
    if(sz2>1)v2=s2[u][1];
    
    if(!s[u].size()){
        t[u]=1;
        f[u]=min(a[u],a[u]+v1);
        if(f[u]<=k||f[u]+v2<=k)t[u]*=2;
        return;
    }
    sort(s[u].begin(),s[u].end());
    int sz=s[u].size();
    int l=0,r=sz-1;
    while(l<=r&&s[u][l]<=k)++l;
    if(r-l+1==0){
        t[u]=1;
        f[u]=min(a[u],a[u]+min(s[u][0],v1));
        int _f=min(min(f[u],a[u]+v1),min(a[u]+v1+v2,a[u]+s[u][0]+v1));
        if(sz>1)_f=min(_f,a[u]+s[u][0]+s[u][1]);
        if(_f<=k)t[u]*=2;
    }
    else if(r-l+1==1){
        t[u]=1;
        f[u]=a[u]+s[u][l];
        int _f=min(f[u],f[u]+v1);
        if(l>0)_f=min(_f,f[u]+s[u][0]);
        if(_f<=k)t[u]*=2;
    }
    else if(r-l+1==2){
        if(a[u]+s[u][l]+s[u][r]>k){
            tag=1;
        }
    }
    else if(r-l+1>2){
        tag=1;
    }
    return;
}

signed main(){
    scanf("%lld",&T);
    while(T--){
        scanf("%lld%lld",&n,&k);
        for(int i=1;i<=n;i++)scanf("%lld",&a[i]);
        for(int i=1,u,v;i<n;i++){
            scanf("%lld%lld",&u,&v);
            g[u].push_back(v);
            g[v].push_back(u);
        }
        dfs(1,0);
        if(!tag&&(t[1]!=1||f[1]<=k))printf("YES\n");
        else printf("NO\n");
        for(int i=1;i<=n;i++){
            g[i].resize(0);
            s[i].resize(0);
            s2[i].resize(0); 
            f[i]=t[i]=0;
        }
        tag=0;
    }
    return 0;
}


