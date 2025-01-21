#include <bits/stdc++.h>
using namespace std;

const int N=1.01e6;
int T,n,cnt[N],rt,mx,ans[N],ff,tt;
vector<int> g[N];
vector<int> id[N];

void dfs(int u,int from){
    cnt[u]=1;
    int mc=0;
    for(unsigned i=0;i<g[u].size();i++){
        int v=g[u][i];
        if(v!=from){
            dfs(v,u);
            cnt[u]+=cnt[v];
            mc=max(mc,cnt[v]);
        }
    }
    mc=max(mc,n-cnt[u]);
    if(mc<mx)mx=mc,rt=u;
    return;
}

void dfs2(int u,int from){
    cnt[u]=1;
    for(unsigned i=0;i<g[u].size();i++){
        int v=g[u][i];
        if(v!=from){
            dfs(v,u);
            cnt[u]+=cnt[v];
        }
    }
    return;
}

struct node{
    int x,y;
    node(int x=0,int y=0):x(x),y(y){}
    bool operator < (const node& _)const{return y<_.y;}
};
priority_queue<node> Q;

void dfs3(int u,int from){
    ans[u]=id[ff][tt],++tt;
    int u1=0;
    for(unsigned i=0;i<g[u].size();i++){
        int v=g[u][i];
        if(v!=from){
            if(cnt[v]==1&&!u1)ans[v]=ans[u]-1,u1=1;
            else dfs3(v,u);
        }
    }
    return;
}

signed main(){
    cin>>T;
    while(T--){
        cin>>n;
        for(int i=1;i<=n;i++){
            g[i].resize(0);
            id[i].resize(0);
        }
        for(int i=1,u,v;i<n;i++){
            cin>>u>>v;
            g[u].push_back(v);
            g[v].push_back(u);
        }
        mx=n+1;
        dfs(1,0);
        dfs2(rt,0);
        ans[rt]=2;
        int u1=0,t=6;
        for(unsigned i=0;i<g[rt].size();i++){
            int v=g[rt][i];
            if(cnt[v]==1&&!u1)u1=1,ans[v]=1;
            else Q.push(node(v,cnt[v]));
        }
        int pre=0;
        while(!Q.empty()){
            int p=Q.top().x;
            Q.pop();
            id[p].push_back(t),t+=2;
            --cnt[p];
            if(cnt[pre])Q.push(node(pre,cnt[pre]));
            pre=p; 
        }
        for(unsigned i=0;i<g[rt].size();i++){
            int v=g[rt][i];
            if(id[v].size())ff=v,tt=0,dfs3(v,rt);
        }
        for(int i=1;i<=n;i++){
            printf("%d ",ans[i]);
        }
        printf("\n");
    }
    return 0;
}


