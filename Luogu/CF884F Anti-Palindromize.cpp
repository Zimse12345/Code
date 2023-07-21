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
char s[N];
int n,b[N],tag[N],ans;

signed main(){
    n=read();
    scanf("%s",s+1);
    for(int i=1;i<=n;i++)b[i]=read(),ans+=b[i];
    G.init(),G.n=n,G.s=++G.n,G.t=++G.n;
    for(int i=1;i<=n;i++)G.Link(i,G.t,1,0);
    for(int c='a';c<='z';c++){
        int cnt=0,id=++G.n;
        for(int i=1;i<=n;i++){
            if(s[i]==c)++cnt,tag[i]=1;
        }
        G.Link(G.s,id,cnt,0);
        for(int i=1;i<=n/2;i++){
            ++G.n;
            G.Link(id,G.n,1,0);
            G.Link(G.n,i,1,(1-tag[i])*b[i]);
            G.Link(G.n,n-i+1,1,(1-tag[n-i+1])*b[n-i+1]);
            tag[i]=tag[n-i+1]=0;
        }
    }
    G.ek();
    _wri(ans-G.Cost);
    return 0;
}

