// Author:Zimse  Data:2023-07-
#include <bits/stdc++.h>
#define pc putchar
#define pb push_back
#define inv fpow
#define int long long
namespace OI{const int INF=1.01e18,Mod=998244353;int read(){int x=0
,y=1;char c=getchar();while(c<48||57<c){if(c==45)y=-1;c=getchar();}
while(47<c&&c<58)x=x*10+c-48,c=getchar();return x*y;}void wr(int x)
{if(x<0)pc(45),x=-x;if(x>=10)wr(x/10);pc(48+x%10);}void wri(int x){
wr(x),pc(32);}void _wri(int x){wr(x),pc(10);}void iF(const char*x){
freopen(x,"r",stdin);}void oF(const char*x){freopen(x,"w",stdout);}
inline int fpow(long long x,int y=Mod-2){int z=1;while(y){if(y&1)z=
x*z%Mod;x=x*x%Mod,y/=2;}return z;}inline void _max(int&x,int y){if(
x<y)x=y;}inline void _min(int&x,int y){if(y<x)x=y;}inline void _mod
(int&x,int y){(x+=y)%=Mod;}}using namespace OI;using namespace std;

const int N=1.01e6,_INF=1e9;
int n,m,g,s[N],V[N],ans;

struct Dinic{
    int sz,Source,Sink,hd[N],h[N],nxt[N],ec,d[N];
    struct Arc{
        int v,f;
        Arc(int v=0,int f=0):v(v),f(f){}
    }E[N];
    inline void init(){for(int i=1;i<=sz;i++)hd[i]=0;ec=1,sz=0;return;}
    inline void link(int u,int v,int f){nxt[++ec]=hd[u],hd[u]=ec,E[ec]=Arc(v,f);return;}
    inline void Link(int u,int v,int f){link(u,v,f),link(v,u,0);return;}

    queue<int> Q;
    bool bfs(){
        for(int i=1;i<=sz;i++)d[i]=0;
        d[Source]=1,Q.push(Source);
        while(!Q.empty()){
            int u=Q.front();
            Q.pop();
            for(int i=hd[u];i;i=nxt[i])if(E[i].f&&!d[E[i].v])d[E[i].v]=d[u]+1,Q.push(E[i].v);
        }
        return d[Sink];
    }

    int dfs(int u,int maxf){
        if(u==Sink||!maxf)return maxf;
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

    int dinic(int source,int sink){
        Source=source,Sink=sink;
        int res=0;
        while(bfs()){
            for(int i=1;i<=sz;i++)h[i]=hd[i];
            res+=dfs(Source,INF);
        }
        return res;
    }
}f;

signed main(){
    n=read(),m=read(),g=read();
    f.init(),f.sz=n+2;
    int S=n+1,T=n+2;
    for(int i=1;i<=n;i++)s[i]=read();
    for(int i=1;i<=n;i++){
        V[i]=read();
        if(!s[i])f.Link(S,i,_INF+V[i]),f.Link(i,T,_INF);
        else f.Link(S,i,_INF),f.Link(i,T,_INF+V[i]);
    }
    for(int i=1;i<=m;i++){
        int t=read(),w=read(),k=read();
        int id=++f.sz;
        ans+=w;
        for(int i=1,x;i<=k;i++){
            x=read();
            if(!t)f.Link(id,x,INF);
            else f.Link(x,id,INF);
        }
        int z=read();
        if(!t)f.Link(S,id,w+g*z);
        else f.Link(id,T,w+g*z);
    }
    ans-=f.dinic(S,T)-_INF*n;
    _wri(ans);
    return 0;
}

