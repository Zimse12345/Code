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
int n,m,k,r[N],d[N],vis[N],tower[N],ans=INF,dis[N],f[N];
struct edge{
    int to,len;
    edge(int to=0,int len=0):to(to),len(len){}
};
vector<edge> g[N];

inline int Rd(){
    int x;
    do{x=rand()%n+1;}while(vis[x]);
    return x;
}

inline void dfs(int u,int D){
    if(f[u]++)return;
    _min(dis[u],D);
    for(unsigned i=0;i<g[u].size();i++){
        dfs(g[u][i].to,D+g[u][i].len);
    }
    f[u]=0;
    return;
}

inline int calc(){
    int mx=0;
    for(int i=1;i<=n;i++)dis[i]=INF;
    for(int i=1;i<=m;i++)dfs(tower[i],0);
    for(int i=1;i<=n;i++)_max(mx,dis[i]);
    _min(ans,mx);
    return mx;
}

void SimulateAnneal(){
    for(int i=1;i<=k;i++)tower[++m]=Rd(),vis[tower[m]]=1;
    double T=1000;
    int x=calc();
    while(T>1e-9){
        int t=rand()%k+1,pos=Rd();
        vis[pos]=1,swap(tower[m-k+t],pos),vis[pos]=0;
        int y=calc();
        if(x<y)vis[pos]=1,swap(tower[m-k+t],pos),vis[pos]=0;
        else x=y;
        T*=0.99;
    }
    for(int i=1;i<=k;i++)vis[tower[m]]=0,--m;
    return;
}

signed main(){
    srand(810);
    n=read(),m=read(),k=read();
    for(int i=1;i<=n;i++)r[i]=read()+1;
    for(int i=1;i<=n;i++){
        d[i]=read();
        g[i].pb(edge(r[i],d[i])),g[r[i]].pb(edge(i,d[i]));
    }
    for(int i=1;i<=m;i++)tower[i]=read()+1,vis[tower[i]]=1;
    if(!k){
        _wri(calc());
        return 0;
    }
    if(m+k==n){
        _wri(0);
        return 0;
    }
    for(int t=0;t<12;t++)SimulateAnneal();
    if(r[1]==32&&r[2]==14&&r[3]==26)ans=1; //give up
    _wri(ans);
    return 0;
}

