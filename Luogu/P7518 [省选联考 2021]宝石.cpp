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

const int N=2e5+7,Mod=998244353,INF=1e9+7;
int n,m,q,c,p[N],Id[N],w[N],hd[N],nxt[N*2],to[N*2],ec,pre[N];
int dep[N],fa[N][20],p0[N][20],p1[N][20],pre0[N];
int ans[N];
struct query{
    int lca,x,id;
    query(int lca=0,int x=0,int id=0):lca(lca),x(x),id(id){}
};
vector<query> Q[N];
inline void add(int u,int v){nxt[++ec]=hd[u],hd[u]=ec,to[ec]=v;return;}

void dfs0(int u,int from){
    int _re=pre[w[u]];
    pre[w[u]]=u,dep[u]=dep[from]+1;
    fa[u][0]=from,p0[u][0]=pre[w[u]+1],pre0[u]=pre[1];
    for(int i=1;i<20;i++)fa[u][i]=fa[fa[u][i-1]][i-1],p0[u][i]=p0[p0[u][i-1]][i-1];
    for(int i=hd[u];i;i=nxt[i])if(to[i]^from)dfs0(to[i],u);
    pre[w[u]]=_re;
    return;
}

bool check(int from,int to,int x,int y){
    from=pre[x];
    if(dep[from]<dep[to])return false;
    for(int i=19;i>=0;i--)if(dep[p1[from][i]]>=dep[to])from=p1[from][i];
    return w[from]<=y;
}

void dfs1(int u,int from){
    int _re=pre[w[u]];
    pre[w[u]]=u;
    if(w[u]){
        p1[u][0]=pre[w[u]-1];
        for(int i=1;i<20;i++)p1[u][i]=p1[p1[u][i-1]][i-1];
    }
    for(int i=0,lca,x;i<signed(Q[u].size());i++){
        lca=Q[u][i].lca,x=Q[u][i].x;
        int L=x+1,R=c,s=x;
        while(L<=R){
            int M=(L+R)>>1;
            if(check(u,lca,M,x+1))s=M,L=M+1;
            else R=M-1;
        }
        ans[Q[u][i].id]=s;
    }
    for(int i=hd[u];i;i=nxt[i])if(to[i]^from)dfs1(to[i],u);
    pre[w[u]]=_re;
    return;
}

int get_lca(int u,int v){
    if(dep[u]<dep[v])swap(u,v);
    for(int i=19;i>=0;i--)if(dep[fa[u][i]]>=dep[v])u=fa[u][i];
    if(u==v)return u;
    for(int i=19;i>=0;i--)if(fa[u][i]^fa[v][i])u=fa[u][i],v=fa[v][i];
    return fa[u][0];
}

signed main(){
	n=read(),m=read(),c=read();
    for(int i=1;i<=c;i++)p[i]=read(),Id[p[i]]=i;
    for(int i=1;i<=n;i++)w[i]=Id[read()];
    for(int i=1,u,v;i<n;i++)u=read(),v=read(),add(u,v),add(v,u);
    dfs0(1,0);
    q=read();
    for(int i=1,u,v,lca,x;i<=q;i++){
        u=read(),v=read();
        lca=get_lca(u,v),u=pre0[u];
        for(int i=19;i>=0;i--)if(dep[p0[u][i]]>=dep[lca])u=p0[u][i];
        x=dep[u]>=dep[lca]?w[u]:0;
        Q[v].push_back(query(lca,x,i));
    }
    dfs1(1,0);
    for(int i=1;i<=q;i++)printf("%d\n",ans[i]);
	return 0;
}
