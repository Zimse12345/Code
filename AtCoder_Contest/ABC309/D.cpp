#include <bits/stdc++.h>
using namespace std;

const int N=1.01e6;
int n1,n2,m,d[N];
vector<int> g[N];
queue<int> q;

int bfs(int s){
    int mx=0;
    d[s]=1,q.push(s);
    while(!q.empty()){
        int u=q.front();
        q.pop();
        mx=max(mx,d[u]);
        for(unsigned i=0;i<g[u].size();i++){
            int v=g[u][i];
            if(!d[v])d[v]=d[u]+1,q.push(v);
        }
    }
    return mx-1;
}

signed main(){
    cin>>n1>>n2>>m;
    while(m--){
        int u,v;
        cin>>u>>v;
        g[u].push_back(v),g[v].push_back(u);
    }
    printf("%d\n",bfs(1)+bfs(n1+n2)+1);
    return 0;
}


