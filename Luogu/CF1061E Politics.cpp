// Author:Zimse  Data:2023-07-
#include <bits/stdc++.h>
#define pc putchar
#define pb push_back
#define inv fpow
// #define int long long
namespace OI{const int INF=1.001e9,Mod=998244353;int read(){int x=0
,y=1;char c=getchar();while(c<48||57<c){if(c==45)y=-1;c=getchar();}
while(47<c&&c<58)x=x*10+c-48,c=getchar();return x*y;}void wr(int x)
{if(x<0)pc(45),x=-x;if(x>=10)wr(x/10);pc(48+x%10);}void wri(int x){
wr(x),pc(32);}void _wri(int x){wr(x),pc(10);}void iF(const char*x){
freopen(x,"r",stdin);}void oF(const char*x){freopen(x,"w",stdout);}
inline int fpow(long long x,int y=Mod-2){int z=1;while(y){if(y&1)z=
x*z%Mod;x=x*x%Mod,y/=2;}return z;}inline void _max(int&x,int y){if(
x<y)x=y;}inline void _min(int&x,int y){if(y<x)x=y;}inline void _mod
(int&x,int y){(x+=y)%=Mod;}}using namespace OI;using namespace std;

const int N=1.01e6;
struct EK{
    int n,m,s,t,hd[N],nxt[N],ec,Flow,Cost;
    struct edge{
        int u,v,val,cost;
        edge(int u=0,int v=0,int val=0,int cost=0):u(u),v(v),val(val),cost(cost){}
    }E[N];
    inline void init(){for(int i=1;i<=n;i++)hd[i]=0;ec=1,n=Flow=Cost=0;return;}
    inline void link(int u,int v,int f,int w){nxt[++ec]=hd[u],hd[u]=ec,E[ec]=edge(u,v,f,w);return;}
    inline void Link(int u,int v,int f,int w){link(u,v,f,w),link(v,u,0,-w);return;}

    int dis[N],inq[N],le[N];
    queue<int> Q;
    bool spfa(){
        for(int i=1;i<=n;i++)dis[i]=INF,le[i]=0;
        dis[s]=0,Q.push(s);
        while(!Q.empty()){
            int u=Q.front();
            inq[u]=0,Q.pop();
            for(int i=hd[u];i;i=nxt[i])if(E[i].val&&dis[u]+E[i].cost<dis[E[i].v]){
                dis[E[i].v]=dis[u]+E[i].cost,le[E[i].v]=i;
                if(!inq[E[i].v])inq[E[i].v]=1,Q.push(E[i].v);
            }
        }
        return le[t];
    }

    void ek(){
        while(spfa()){
            int flow=INF,cost=0;
            for(int i=le[t];i;i=le[E[i].u])flow=min(flow,E[i].val),cost+=E[i].cost;
            Flow+=flow,Cost+=flow*cost;
            for(int i=le[t];i;i=le[E[i].u])E[i].val-=flow,E[i^1].val+=flow;
        }
        return;
    }
}G;
int n,r[2],v[N],m[2],tag[2][N],cnt[2],col[2][N],lim[2][N],sum[2];
vector<int> g[2][N];
vector<int> a;

void dfs2(int u,int from,int id){
    a.pb(u);
    for(unsigned i=0;i<g[id][u].size();i++){
        int v=g[id][u][i];
        if(v==from||tag[id][v])continue;
        dfs2(v,u,id);
    }
    return;
}

int dfs(int u,int from,int id){
    int s=0;
    for(unsigned i=0;i<g[id][u].size();i++){
        int v=g[id][u][i];
        if(v==from)continue;
        s+=dfs(v,u,id);
    }
    if(tag[id][u]){
        a.resize(0);
        dfs2(u,from,id);
        lim[id][++cnt[id]]=tag[id][u]-s;
        for(unsigned i=0;i<a.size();i++)col[id][a[i]]=cnt[id];
        s=tag[id][u];
    }
    return s;
}

signed main(){
    G.init();
    n=read(),r[0]=read(),r[1]=read();
    for(int i=1;i<=n;i++)v[i]=read();
    for(int i=0;i<2;i++){
        for(int j=1,u,v;j<n;j++){
            u=read(),v=read();
            g[i][u].pb(v),g[i][v].pb(u);
        }
    }
    for(int i=0;i<2;i++){
        m[i]=read();
        for(int j=1,x;j<=m[i];j++)x=read(),tag[i][x]=read();
        dfs(r[i],0,i);
    }
    G.n=cnt[0]+cnt[1];
    G.s=++G.n,G.t=++G.n;
    int Tag=0;
    for(int i=1;i<=cnt[0];i++){
        G.Link(G.s,i,lim[0][i],0),sum[0]+=lim[0][i];
        if(lim[0][i]<0)Tag=1;
    }
    for(int i=1;i<=cnt[1];i++){
        G.Link(cnt[0]+i,G.t,lim[1][i],0),sum[1]+=lim[1][i];
        if(lim[1][i]<0)Tag=1;
    }
    if(sum[0]!=sum[1])Tag=1;
    for(int i=1;i<=n;i++)G.Link(col[0][i],cnt[0]+col[1][i],1,-v[i]);
    G.ek();
    if(G.Flow!=sum[0])Tag=1;
    if(Tag)_wri(-1);
    else _wri(-G.Cost);
    return 0;
}

