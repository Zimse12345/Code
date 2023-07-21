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
struct Dinic{
    int n,s,t,hd[N],h[N],nxt[N],ec,d[N],Flow;
    struct Arc{
        int v,f;
        Arc(int v=0,int f=0):v(v),f(f){}
    }E[N];
    inline void init(){for(int i=1;i<=n;i++)hd[i]=0;ec=1,n=Flow=0;return;}
    inline void link(int u,int v,int f){nxt[++ec]=hd[u],hd[u]=ec,E[ec]=Arc(v,f);return;}
    inline void Link(int u,int v,int f){link(u,v,f),link(v,u,0);return;}

    queue<int> Q;
    bool bfs(){
        for(int i=1;i<=n;i++)d[i]=0;
        d[s]=1,Q.push(s);
        while(!Q.empty()){
            int u=Q.front();
            Q.pop();
            for(int i=hd[u];i;i=nxt[i])if(E[i].f&&!d[E[i].v])d[E[i].v]=d[u]+1,Q.push(E[i].v);
        }
        return d[t];
    }

    int dfs(int u,int maxf){
        if(u==t||!maxf)return maxf;
        int flow=0;
        for(int i=h[u];i;i=nxt[i]){
            if(d[u]+1==d[E[i].v]){
                int f=dfs(E[i].v,min(maxf,E[i].f));
                flow+=f,maxf-=f,E[i].f-=f,E[i^1].f+=f;
                if(!maxf)break;
            }
            h[u]=nxt[h[u]];
        }
        if(!flow)d[u]=0;
        return flow;
    }

    void dinic(){
        while(bfs()){
            for(int i=1;i<=n;i++)h[i]=hd[i];
            Flow+=dfs(s,INF);
        }
        return;
    }
}G;
int n,m,p[N],c[N],q,k[N],vis[N];
int mex=-1,ans[N];

void addmex(){
    ++mex;
    G.Link(G.s,m+mex+1,1);
    return;
}

signed main(){
    n=read(),m=read();
    for(int i=1;i<=n;i++)p[i]=read();
    for(int i=1;i<=n;i++)c[i]=read();
    G.init();
    G.n=6000+m,G.s=++G.n,G.t=++G.n;
    for(int i=1;i<=m;i++)G.Link(i,G.t,1);
    addmex();
    q=read();
    for(int i=1;i<=q;i++)k[i]=read(),vis[k[i]]=1;
    for(int i=1;i<=n;i++)if(!vis[i])G.Link(m+p[i]+1,c[i],1);
    for(int i=q;i>=1;i--){
        while(mex<=n){
            G.dinic();
            if(G.Flow==mex+1)addmex();
            else break;
        }
        ans[i]=mex;
        G.Link(m+p[k[i]]+1,c[k[i]],1);
    }
    for(int i=1;i<=q;i++)_wri(ans[i]);
    return 0;
}

