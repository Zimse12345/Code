#include <cstdio>
#include <algorithm>
#include <cstring>
#include <vector>
#include <cmath>
#include <set>
#include <map>
#include <queue>
#include <stack>
#include <iostream>
#include <cstdlib>
#include <ctime>

#define ll long long
#define ull unsigned long long

using namespace std;

inline int read(){int qrx=0,qry=1;char qrc=getchar();
while(qrc<'0'||qrc>'9'){if(qrc=='-'){qry=-1,qrc=getchar();}else qrc=getchar();}
while(qrc>='0'&&qrc<='9')qrx=qrx*10+qrc-48,qrc=getchar();return qrx*qry;}
inline void write(int x){if(x>=10)write(x/10);putchar(x%10+'0');return;}

const int N=3e5+7,Mod=998244353,INF=1e9+7;
int n,m,q,k,hd0[N],hd1[N],hd2[N],hd3[N],hd4[N],nxt[N*32],to[N*32],len[N*32],ec;
int dfn[N],low[N],Time0,stk[N],top,cc,col[N],sz[N],indeg[N],root[N],ans;
int fa[N],dep[N],cnt[N],son[N],Dfn[N],Top[N],pre[N],Time1,vis0[N],vis1[N];
int *re[N];
int _p[N],_t,tot;
queue<int> Q;
inline void add0(int u,int v){nxt[++ec]=hd0[u],hd0[u]=ec,to[ec]=v;return;}
inline void add1(int u,int v){nxt[++ec]=hd1[u],hd1[u]=ec,to[ec]=v;return;}
inline void add2(int u,int v){nxt[++ec]=hd2[u],hd2[u]=ec,to[ec]=v;return;}
inline void link(int u,int v,int w){
    if(u==v)return;
    re[++tot]=&hd3[u],re[++tot]=&hd4[v];
    vis0[u]=vis0[v]=vis1[u]=vis1[v]=0;
    w*=pre[v]-pre[u]-sz[v];
    nxt[++ec]=hd3[u],hd3[u]=ec,to[ec]=v,len[ec]=w;
    nxt[++ec]=hd4[v],hd4[v]=ec,to[ec]=u,len[ec]=w;
    return;
}
struct node{int x,y;node(int x=0,int y=0):x(x),y(y){}
bool operator < (const node& A)const{return y<A.y;}};
inline node nd(int x){return node(x,Dfn[x]);}

void tarjan(int u){
    dfn[u]=low[u]=++Time0,stk[++top]=u;
    for(int i=hd0[u],v;i;i=nxt[i]){
        v=to[i];
         if(!dfn[v])tarjan(v),low[u]=min(low[u],low[v]);
        else if(!col[v])low[u]=min(low[u],dfn[v]);
    }
    if(dfn[u]==low[u]){
        ++cc;
        while(stk[top+1]^u)col[stk[top--]]=cc,++sz[cc];
    }
    return;
}

void dfs1(int u,int from,int d,int sum){
    fa[u]=from,dep[u]=d,cnt[u]=1,sum+=sz[u],pre[u]=sum;
    for(int i=hd2[u],v;i;i=nxt[i]){
        v=to[i];
        if(v^from){
            dfs1(v,u,d+1,sum),cnt[u]+=cnt[v];
            if(cnt[son[u]]<cnt[v])son[u]=v;
        }
    }
    return;
}

void dfs2(int u,int from,int d){
    Dfn[u]=++Time1,Top[u]=d;
    if(son[u])dfs2(son[u],u,d);
    for(int i=hd2[u],v;i;i=nxt[i]){
        v=to[i];
        if((v^from)&&(v^son[u]))dfs2(v,u,v);
    }
    return;
}

inline int LCA(int u,int v){
    while(Top[u]^Top[v]){
        if(dep[Top[u]]<dep[Top[v]])swap(u,v);
        u=fa[Top[u]];
    }
    return dep[u]<dep[v]?u:v;
}

void dfs3(int u){
    if(vis0[u]++)return;
    _p[++_t]=u;
    for(int i=hd3[u];i;i=nxt[i])dfs3(to[i]);
    return;
}

void dfs4(int u){
    if(vis1[u]++)return;
    for(int i=hd4[u];i;i=nxt[i])dfs4(to[i]);
    return;
}

signed main(){
	n=read(),m=read(),q=read(),k=read();
	for(int i=1,u,v;i<=m;i++)u=read(),v=read(),add0(u,v);
    for(int i=1;i<=n;i++)if(!dfn[i])tarjan(i);
    for(int u=1,v;u<=n;u++){
        for(int i=hd0[u];i;i=nxt[i]){
            v=to[i];
            if(col[u]^col[v])add1(col[u],col[v]),++indeg[col[v]];
        }
    }
    for(int i=1;i<=cc;i++)if(!indeg[i])root[i]=i,Q.push(i);
    while(!Q.empty()){
        int u=Q.front();Q.pop();
        for(int i=hd1[u],v;i;i=nxt[i]){
            v=to[i],--indeg[v];
            if(!indeg[v])add2(u,v),Q.push(v),root[v]=root[u];
        }
    }
    for(int i=1;i<=cc;i++)if(root[i]==i)dfs1(i,0,1,0),dfs2(i,0,i);
    while(q--){
        vector<node> p;
        int s=col[read()],t=col[read()],a[2]={0,0},b[2]={0,0};p.push_back(nd(s)),p.push_back(nd(t));
        for(int i=0;i<k;i++){
            a[i]=col[read()],b[i]=col[read()];
            p.push_back(nd(a[i])),p.push_back(nd(b[i]));
        }
        sort(p.begin(),p.end());
        for(unsigned i=0;i<p.size();i++)vis0[p[i].x]=vis1[p[i].x]=0;
        for(int i=0,j;i<signed(p.size());){
            j=i;
            while(j+1<signed(p.size())&&root[p[j+1].x]==root[p[i].x])++j;
            if(i==j){++i;continue;}
            top=0;
            int lca=LCA(p[i].x,p[i+1].x);
            stk[++top]=lca;
            if(lca==p[i+1].x)stk[++top]=p[i].x;
            else link(lca,p[i].x,1),stk[++top]=p[i+1].x;
            for(int k=i+2;k<=j;k++){
                int u=LCA(p[k].x,p[k-1].x);
                while(top>1&&dep[u]<dep[stk[top-1]])link(stk[top-1],stk[top],1),--top;
                link(u,stk[top],1),stk[top]=u,stk[++top]=p[k].x;
            }
            for(int i=1;i<top;i++)link(stk[i],stk[i+1],1);
            i=j+1;
        }
        for(int i=0;i<k;i++)link(a[i],b[i],0);
        _t=0;
        dfs3(s),dfs4(t),ans=0;
        for(int i=1,u;i<=_t;i++){
            u=_p[i];
            if(vis0[u]&&vis1[u])ans+=sz[u];
            for(int j=hd3[u],v;j;j=nxt[j]){
                v=to[j];
                if(vis0[u]&&vis1[v])ans+=len[j];
            }
        }
        write(ans),putchar('\n');
        for(unsigned i=1;i<=tot;i++)*re[i]=0;
        tot=0;
    }
	return 0;
}

