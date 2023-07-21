#include <bits/stdc++.h>
using namespace std;

const int N=1.01e6,INF=1e9;
int n,m,fa[N],dep[N],ans;
vector<int> ch[N];
vector<int> p[N];
multiset<int> S;
multiset<int>::iterator it;

void dfs(int u){
    for(unsigned i=0;i<p[u].size();i++)S.insert(p[u][i]+dep[u]);
    it=S.lower_bound(dep[u]);
    if(*it<INF)++ans;
    for(unsigned i=0;i<ch[u].size();i++)dep[ch[u][i]]=dep[u]+1,dfs(ch[u][i]);
    for(unsigned i=0;i<p[u].size();i++)S.erase(S.find(p[u][i]+dep[u]));
    return;
}

signed main(){
    cin>>n>>m;
    for(int i=2;i<=n;i++){
        cin>>fa[i];
        ch[fa[i]].push_back(i);
    }
    while(m--){
        int x,y;
        cin>>x>>y;
        p[x].push_back(y);
    }
    S.insert(INF),S.insert(INF);
    dfs(1);
    printf("%d\n",ans);
    return 0;
}


