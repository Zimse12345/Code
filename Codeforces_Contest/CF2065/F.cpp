#include <bits/stdc++.h>
using namespace std;

const int N=1.01e6;
int T,n,a[N],ans[N];
int vis[N];
vector<int> g[N];

signed main(){
    cin>>T;
    while(T--){
        cin>>n;
        for(int i=1;i<=n;i++){
            cin>>a[i],ans[i]=0;
            g[i].resize(0);
            vis[i]=0;
        }
        for(int i=1,u,v;i<n;i++){
            cin>>u>>v;
            g[u].push_back(v);
            g[v].push_back(u);
            if(a[u]==a[v])ans[a[u]]=1;
        }
        for(int i=1;i<=n;i++){
            for(unsigned j=0;j<g[i].size();j++){
                int x=a[g[i][j]];
                if(vis[x]==i)ans[x]=1;
                vis[x]=i;
            }
        }
        for(int i=1;i<=n;i++)printf("%d",ans[i]);
        printf("\n");
    }
    return 0;
}


