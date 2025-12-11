#include <bits/stdc++.h>
#define pc putchar
#define pb push_back
#define inv fpow
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
int T,n,m,nw,deg[N];
long long ans;
int fa[N],tim,cnt[N];

struct edge{
    int u,v,w,id;
    edge(int u=0,int v=0,int w=0,int id=0):u(u),v(v),w(w),id(id){}
    bool operator < (const edge& _)const{
        return w<_.w;
    }
}e[N];
struct Edge{
    int v,id;
    Edge(int v=0,int id=0):v(v),id(id){}
    bool operator < (const Edge& _)const{
        return id>_.id;
    }
};
priority_queue<Edge> g[N];

int F(int x){
    if(fa[x]!=x)fa[x]=F(fa[x]);
    return fa[x];
}

void link(Edge eg){
    while(1){
        int u=F(eg.v),v=F(eg.id);
        if(u!=v){
            if(cnt[u]&&cnt[v])--cnt[u],--cnt[v],ans+=nw;
            if(g[u].size()<g[v].size())swap(u,v);
            while(!g[v].empty())g[u].push(g[v].top()),g[v].pop();
            fa[v]=u,cnt[u]+=cnt[v];
        }
        if(!g[u].empty()){
            Edge Eg=g[u].top();
            if(Eg.id>tim)break;
            g[u].pop();
            eg=Edge(u,Eg.v);
        }
        else break;
    }
    return;
}

signed main(){
    T=read();
    while(T--){
        n=read(),m=read();
        ans=0;
        for(int i=1;i<=n;i++){
            deg[i]=0;
            fa[i]=i;
            while(!g[i].empty())g[i].pop();
            cnt[i]=0;
        }
        
        for(int i=1,u,v,w;i<=m;i++){
            u=read(),v=read(),w=read();
            ans+=w;
            ++deg[u],++deg[v];
            e[i]=edge(u,v,w,i);
            g[u].push(Edge(v,i));
            g[v].push(Edge(u,i));
        }
        
        for(int i=1;i<=n;i++)if(deg[i]&1){
            ++cnt[i];
        }
        sort(e+1,e+m+1);
        tim=0;
        for(int i=1;i<=m;i++){
            nw=e[i].w;
            tim=e[i].id;
            link(Edge(e[i].u,e[i].v));
        }
        printf("%lld\n",ans);
    }
    return 0;
}


