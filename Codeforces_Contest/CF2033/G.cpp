#include <bits/stdc++.h>
using namespace std;

const int N=1.01e6;
int T,n,q,mx[N],mxid[N],se[N];
vector<int> g[N];

struct query{
    int id,k;
    query(int id=0,int k=0):id(id),k(k){}
};
int ans[N];
vector<query> Q[N];

#define Lid (id<<1)
#define Rid (Lid|1)
#define M ((L+R)/2)

int t[N];

void upt(int id,int L,int R,int x,int y){
    if(L==R)t[id]=y;
    else{
        if(x<=M)upt(Lid,L,M,x,y);
        else upt(Rid,M+1,R,x,y);
        t[id]=max(t[Lid],t[Rid]);
    }
    return;
}

int qry(int id,int L,int R,int l,int r){
    if(r<L||R<l||r<l)return -1e9;
    if(l<=L&&r>=R)return t[id];
    return max(qry(Lid,L,M,l,r),qry(Rid,M+1,R,l,r));
}

void dfs(int u,int from){
    for(unsigned i=0;i<g[u].size();i++){
        int v=g[u][i];
        if(v==from)continue;
        dfs(v,u);
        if(mx[v]+1>mx[u])se[u]=mx[u],mx[u]=mx[v]+1,mxid[u]=v;
        else if(mx[v]+1>se[u])se[u]=mx[v]+1;
    }
    return;
}

void dfs2(int u,int from,int dep){
    for(unsigned i=0;i<Q[u].size();i++){
        int id=Q[u][i].id,k=Q[u][i].k;
        ans[id]=max(mx[u],qry(1,0,n,max(dep-k,0),dep-1)+dep);
    }
    for(unsigned i=0;i<g[u].size();i++){
        int v=g[u][i];
        if(v==from)continue;
        if(v==mxid[u])upt(1,0,n,dep,se[u]-dep);
        else upt(1,0,n,dep,mx[u]-dep);
        dfs2(v,u,dep+1);
    }
    upt(1,0,n,dep,-1e9);
    return;
}

signed main(){
    cin>>T;
    while(T--){
        cin>>n;
        for(int i=1;i<=n;i++){
            mx[i]=se[i]=mxid[i]=0;
            g[i].resize(0);
            Q[i].resize(0); 
        }
        for(int i=1,u,v;i<n;i++){
            cin>>u>>v;
            g[u].push_back(v);
            g[v].push_back(u);
        }
        dfs(1,0);
        cin>>q;
        for(int i=1,u,k;i<=q;i++){
            cin>>u>>k;
            Q[u].push_back(query(i,k));
            ans[i]=0;
        }
        dfs2(1,0,0);
        for(int i=1;i<=q;i++)printf("%d ",ans[i]);
        printf("\n");
    }
    return 0;
}


