// Author:Zimse  Data:2023-06-
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

const int N=4.01e3;
int n,len[N][N],fa[N],tp[N],cnt,totp[N],tote[N];
int lc[N],rc[N],tg[N],f[N][N/2],sz[N];

struct edge{
    int u,v,w;
    edge(int u=0,int v=0,int w=0):u(u),v(v),w(w){}
    bool operator < (const edge &_){return w<_.w;}
}e[N*N/2];
int ec;

inline int F(int x){
    if(fa[x]!=x)fa[x]=F(fa[x]);
    return fa[x];
}

void dp(int u){
    if(u<=n){
        f[u][1]=1,sz[u]=1;
        return;
    }
    dp(lc[u]),dp(rc[u]);
    sz[u]=sz[lc[u]]+sz[rc[u]];
    for(int x=1;x<=sz[lc[u]];x++){
        for(int y=1;y<=sz[rc[u]];y++)_mod(f[u][x+y],1ll*f[lc[u]][x]*f[rc[u]][y]%Mod);
    }
    if(tg[u])++f[u][1];
    return;
}

signed main(){
    n=read();
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            len[i][j]=read();
            if(i<j)e[++ec]=edge(i,j,len[i][j]);
        }
    }
    sort(e+1,e+ec+1);
    for(int i=1;i<=n;i++)fa[i]=i,tp[i]=i,totp[i]=1;
    cnt=n;
    for(int i=1,u,v;i<=ec;i++){
        u=F(e[i].u),v=F(e[i].v);
        if(u!=v){
            fa[v]=u,totp[u]+=totp[v],tote[u]+=tote[v];
            ++cnt,lc[cnt]=tp[u],rc[cnt]=tp[v],tp[u]=cnt;
        }
        ++tote[u];
        if(tote[u]==totp[u]*(totp[u]-1)/2)tg[tp[u]]=1;
    }
    dp(cnt);
    for(int i=1;i<=n;i++)wri(f[cnt][i]);
    pc(10);
    return 0;
}

