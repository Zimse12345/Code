#include <bits/stdc++.h>
using namespace std;

const int N=1.01e6;
int T,n,Q,fa[N],p[N],cnt[N],q[N],c,tag[N];
vector<int> g[N];

int read(){int x=0,y=1;char c=getchar();
while(c<48||57<c){if(c==45)y=-1;c=getchar();}
while(47<c&&c<58)x=x*10+c-48,c=getchar();return x*y;}

void dfs(int u){
    cnt[u]=1;
    for(unsigned i=0;i<g[u].size();i++){
        int v=g[u][i];
        dfs(v),cnt[u]+=cnt[v];
    }
    return;
}

void ck(int i){
    if(i<1||i>n)return;
    if(fa[p[i]]==p[i-1]||(i!=1&&fa[p[i]]==p[i-cnt[p[i]]-1])){
        if(!tag[i])++c,tag[i]=1;
    }
    else if(tag[i])tag[i]=0,--c;
    return;
}

signed main(){
    T=read();
    while(T--){
        n=read(),Q=read();
        for(int i=1;i<=n;i++)g[i].resize(0),tag[i]=0;
        for(int i=2;i<=n;i++)fa[i]=read(),g[fa[i]].push_back(i);
        dfs(1);
        for(int i=1;i<=n;i++)if(!g[i].size())g[i].push_back(0),g[i].push_back(0);
        for(int i=1;i<=n;i++)p[i]=read(),q[p[i]]=i;
        c=0;
        for(int i=1;i<=n;i++)ck(i);
        for(int i=1;i<=Q;i++){
            int x=read(),y=read();
            swap(p[x],p[y]);
            swap(q[p[x]],q[p[y]]);
            ck(x),ck(y);
            ck(q[g[p[x]][0]]),ck(q[g[p[x]][1]]);
            ck(q[g[p[y]][0]]),ck(q[g[p[y]][1]]);
            if(c==n)printf("YES\n");
            else printf("NO\n");
//            for(int i=1;i<=n;i++)printf("%d ",tag[i]);
//            printf("<-tag %d\n",c);
        }
    }
    return 0;
}


