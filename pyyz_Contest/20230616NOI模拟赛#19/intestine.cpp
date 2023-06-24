// Author:Zimse  Data:2023-06-
#include <bits/stdc++.h>
#define pc putchar
#define pb push_back
#define inv fpow
#define int long long
//#define M ((L+R)/2)
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

const int N=1024;
int n,fa[N],f[N],sz[N],fac[N],ans[N][N],t[N][N],sump[N];
int pos[N],cur,g[N];
vector<int> ch[N];

void dfs(int u){
    f[u]=1,sz[u]=1;
    for(unsigned i=0;i<ch[u].size();i++){
        int v=ch[u][i];
        dfs(v),(f[u]*=f[v])%=Mod,sz[u]+=sz[v];
    }
    (f[u]*=fac[ch[u].size()])%=Mod;
    return;
}

void dfs2(int u){
    int lim=n-sz[u]+1,cnt=ch[u].size();
    pos[u]=++cur;
    t[pos[u]][1]=1;
    int tot=0,s=1;
    for(int i=0;i<cnt;i++){
        for(int x=tot;x>=0;x--){
            for(int y=1;y<=s;y++)if(t[pos[u]+x][y])_mod(t[pos[u]+x+1][y+sz[ch[u][i]]],t[pos[u]+x][y]);
        }
        ++tot,s+=sz[ch[u][i]],++cur;
    }
    int iv=inv(ch[u].size());
    for(int i=0;i<cnt;i++){
        int v=ch[u][i];
        for(int x=0;x<=tot;x++){
            for(int y=1;y<=s;y++)if(t[pos[u]+x][y])_mod(t[pos[u]+x+1][y+sz[v]],Mod-t[pos[u]+x][y]);
        }
        for(int x=0;x<=cnt;x++){
            sump[x]=0;
            for(int y=1;y<=sz[u];y++)_mod(sump[x],t[pos[u]+x][y]);
            sump[x]=inv(sump[x])*iv%Mod;
        }
        for(int j=1;j<=sz[u];j++)g[j]=0;
        for(int x=0;x<=cnt;x++){
            for(int y=1;y<=sz[u];y++)if(t[pos[u]+x][y])_mod(g[y],t[pos[u]+x][y]*sump[x]);
        }
        for(int y=1;y<=sz[u];y++)if(g[y]){
            for(int j=1;j<=lim;j++)_mod(ans[v][j+y],ans[u][j]*g[y]);
        }
        dfs2(v);
        for(int x=tot;x>=0;x--){
            for(int y=1;y<=s;y++)if(t[pos[u]+x][y])_mod(t[pos[u]+x+1][y+sz[v]],t[pos[u]+x][y]);
        }
    }
    return;
}

signed main(){
    iF("intestine.in");
    oF("intestine.out");
    
    fac[0]=1;
    for(int i=1;i<N;i++)fac[i]=fac[i-1]*i%Mod;
    n=read();
    for(int i=2;i<=n;i++){
        fa[i]=read();
        ch[fa[i]].pb(i);
    }
    dfs(1);
    ans[1][1]=1,dfs2(1);
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            wr(ans[i][j]*f[1]%Mod);
            if(j<n)pc(32);
        }
        pc(10);
    }
    return 0;
}

