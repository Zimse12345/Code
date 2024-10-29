#include <bits/stdc++.h>
#define int long long
using namespace std;

const int N=1.01e6;
int T,n,rt,a[N],D;
vector<int> g[N];

int dfs(int u,int from){
    int nd=0;
    for(unsigned i=0;i<g[u].size();i++){
        int v=g[u][i];
        if(v==from)continue;
        nd+=dfs(v,u);
    }
    if(nd+a[u]<D)return 0;
    return nd+a[u]-D;
}

bool ck(int d){
    D=d;
    return dfs(rt,0)==0;
}

int dfs2(int u,int from){
    int nd=0;
    for(unsigned i=0;i<g[u].size();i++){
        int v=g[u][i];
        if(v==from)continue;
        nd+=dfs2(v,u);
    }
    nd+=a[u];
    int d=D/n;
    if(u<=D%n)++d;
    if(nd>=d)return nd-d;
    if((d-nd)%2==0)return 0;
    return 1;
}

signed main(){
    cin>>T;
    while(T--){
        cin>>n>>rt;
        for(int i=1;i<=n;i++){
            cin>>a[i];
            g[i].resize(0);
        }
        for(int i=1,u,v;i<n;i++){
            cin>>u>>v;
            g[u].push_back(v);
            g[v].push_back(u);
        }
        int L=0,R=1e9,mn=1e9;
        while(L<=R){
            int M=(L+R)/2;
            if(ck(M))mn=M,R=M-1;
            else L=M+1;
        }
        int ans=-1;
        for(int i=max(0ll,(mn-1)*n),c=0;c<=n*8;c++){
            D=i;
            int cc=dfs2(rt,0);
            if(cc==0){
                ans=i;
                break;
            }
            i+=cc;
        }
        printf("%lld\n",ans);
    }
    return 0;
}


