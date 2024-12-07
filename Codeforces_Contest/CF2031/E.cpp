#include <bits/stdc++.h>
using namespace std;

const int N=1.01e6;
int T,n,fa[N],f[N];
vector<int> g[N];

void dfs(int u,int from){
    vector<int> s;
    for(unsigned i=0;i<g[u].size();i++){
        int v=g[u][i];
        if(v==from)continue;
        dfs(v,u);
        s.push_back(f[v]);
    }
    sort(s.begin(),s.end());
    int sz=s.size();
    int d=0;
    if(sz)d=s[sz-1]+1;
    while(1){
        int tag=1;
        int p=d-1;
        long long c=2;
        for(int i=sz-1;i>=0;i--){
            if(p<s[i]||c==0){
                tag=0;
                break;
            }
            if(c<n)c*=1ll<<min(p-s[i],20),p=s[i];
            --c;
        }
        if(tag)break;
        ++d;
    }
    f[u]=d;
    return;
}

signed main(){
    scanf("%d",&T);
    while(T--){
        scanf("%d",&n);
        for(int i=1;i<=n;i++)g[i].resize(0);
        for(int i=2;i<=n;i++){
            scanf("%d",&fa[i]);
            g[fa[i]].push_back(i);
        }
        dfs(1,0);
        printf("%d\n",f[1]);
    }
    return 0;
}


