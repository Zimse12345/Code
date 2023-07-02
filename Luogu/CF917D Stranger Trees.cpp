// Author:Zimse  Data:2023-06-
#include <bits/stdc++.h>
#define pc putchar
#define pb push_back
#define inv fpow
#define int long long
namespace OI{const int INF=1.01e9,Mod=1000000007;int read(){int x=0
,y=1;char c=getchar();while(c<48||57<c){if(c==45)y=-1;c=getchar();}
while(47<c&&c<58)x=x*10+c-48,c=getchar();return x*y;}void wr(int x)
{if(x<0)pc(45),x=-x;if(x>=10)wr(x/10);pc(48+x%10);}void wri(int x){
wr(x),pc(32);}void _wri(int x){wr(x),pc(10);}void iF(const char*x){
freopen(x,"r",stdin);}void oF(const char*x){freopen(x,"w",stdout);}
inline int fpow(long long x,int y=Mod-2){int z=1;while(y){if(y&1)z=
x*z%Mod;x=x*x%Mod,y/=2;}return z;}inline void _max(int&x,int y){if(
x<y)x=y;}inline void _min(int&x,int y){if(y<x)x=y;}inline void _mod
(int&x,int y){(x+=y)%=Mod;}}using namespace OI;using namespace std;

const int N=205;
int n,f[N][N][N],tmp[N][N],sz[N],F[N],C[N][N];
vector<int> g[N];

void dfs(int u,int from){
    f[u][1][1]=1,sz[u]=1;
    for(unsigned i=0;i<g[u].size();i++){
        int v=g[u][i];
        if(v==from)continue;
        dfs(v,u);
        for(int x=1;x<=sz[u];x++){
            for(int a=1;a<=sz[u];a++)if(f[u][x][a]){
                for(int y=1;y<=sz[v];y++){
                    for(int b=1;b<=sz[v];b++)if(f[v][y][b]){
                        _mod(tmp[x+y-1][a+b],f[u][x][a]*f[v][y][b]);
                        _mod(tmp[x+y][a],f[u][x][a]*f[v][y][b]%Mod*b);
                    }
                }
            }
        }
        sz[u]+=sz[v];
        for(int x=1;x<=sz[u];x++){
            for(int y=1;y<=sz[u];y++)f[u][x][y]=tmp[x][y],tmp[x][y]=0;
        }
    }
    return;
}

signed main(){
    C[0][0]=1;
    for(int i=1;i<N;i++){
        C[i][0]=1;
        for(int j=1;j<N;j++)C[i][j]=(C[i-1][j]+C[i-1][j-1])%Mod;
    }
    n=read();
    for(int i=1,u,v;i<n;i++){
        u=read(),v=read();
        g[u].pb(v),g[v].pb(u);
    }
    dfs(1,0);
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++)_mod(F[n-i],f[1][i][j]*j);
    }
    F[n-1]=1;
    for(int i=0;i<n-1;i++)F[i]=F[i]*fpow(n,n-i-2)%Mod;
    for(int i=n-1;i>=0;i--){
        for(int j=i+1;j<n;j++)_mod(F[i],-F[j]*C[j][i]);
    }
    for(int i=0;i<n;i++)_mod(F[i],Mod),wri(F[i]);
    pc(10);
    return 0;
}

