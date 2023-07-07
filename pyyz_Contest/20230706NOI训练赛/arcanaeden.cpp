// Author:Zimse  Data:2023-06-
#include <bits/stdc++.h>
#define pc putchar
#define pb push_back
#define inv fpow
#define int long long
namespace OI{const int INF=1.001e11,Mod=998244353;int read(){int x=0
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
int n,val[N];
int hd[N],nxt[N],to[N],ec;
int f[N],ch[N];

struct node{
    int x,y;
    node(int x=0,int y=0):x(x),y(y){}
};
vector<node> g[N];

inline void add(int u,int v){
    nxt[++ec]=hd[u],hd[u]=ec,to[ec]=v;
    return;
}

void dfs2(int u,int from,int sum,int x,int U){
    x^=val[u];
    for(int i=hd[u],v;i;i=nxt[i]){
        v=to[i];
        if(v==from)continue;
        sum+=f[v];
    }
    g[U].pb(node(x,sum));
    for(int i=hd[u],v;i;i=nxt[i]){
        v=to[i];
        if(v==from)continue;
        dfs2(v,u,sum-f[v],x,U);
    }
    return;
}

void dfs(int u,int from){
    bool is_leaf=true;
    for(int i=hd[u],v;i;i=nxt[i]){
        v=to[i];
        if(v==from)continue;
        dfs(v,u);
        is_leaf=false;
    }
    dfs2(u,from,0,0,u);
    f[u]=INF;
    int sum=0,tot=0;
    for(int i=hd[u],v;i;i=nxt[i]){
        v=to[i];
        if(v==from)continue;
        ch[++tot]=v,sum+=f[v];
    }
    for(int i=1,v;i<=tot;i++){
        v=ch[i];
        for(unsigned j=0;j<g[v].size();j++){
            _min(f[u],sum-f[v]+g[v][j].y+(g[v][j].x^val[u]));
        }
        for(int j=i+1,w;j<=tot;j++){
            w=ch[j];
            for(unsigned x=0;x<g[v].size();x++){
                for(unsigned y=0;y<g[w].size();y++){
                    _min(f[u],sum-f[v]-f[w]+g[v][x].y+g[w][y].y+(g[v][x].x^g[w][y].x^val[u]));
                }
            }
        }
    }
    _min(f[u],sum+val[u]);
    return;
}

signed main(){
    iF("arcanaeden.in");
    oF("arcanaeden.out");
    
    n=read();
    for(int i=1;i<=n;i++)val[i]=read();
    for(int i=1,u,v;i<n;i++){
        u=read(),v=read();
        add(u,v),add(v,u);
    }
    dfs(1,0);
    _wri(f[1]);
    return 0;
}

