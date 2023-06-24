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

const int N=5010;
int n,hd[N],nxt[N*2],to[N*2],ec;
int f[N][N],cnt[N][2],lim[N],col[N],C[N][N],fac[N];
char str[N];

inline void add(int u,int v){
    nxt[++ec]=hd[u],hd[u]=ec,to[ec]=v;
    return;
}

void dfs(int u,int from){
    cnt[u][col[u]]=1;
    f[u][0]=1;
    for(int i=hd[u],v;i;i=nxt[i]){
        v=to[i];
        if(v==from)continue;
        dfs(v,u);
        for(int x=lim[u],_f;x>=0;x--){
            _f=f[u][x],f[u][x]=0;
            for(int y=lim[v];y>=0;y--)_mod(f[u][x+y],_f*f[v][y]);
        }
        cnt[u][0]+=cnt[v][0];
        cnt[u][1]+=cnt[v][1];
        lim[u]+=lim[v];
    }
    for(int x=lim[u];x>=0;x--)_mod(f[u][x+1],f[u][x]*max(0ll,cnt[u][col[u]^1]-x));
    if(f[u][lim[u]+1])++lim[u];
    return;
}

signed main(){
    n=read();
    scanf("%s",str+1);
    for(int i=1;i<=n;i++)col[i]=(str[i]&1);
    for(int i=1,u,v;i<n;i++){
        u=read(),v=read();
        add(u,v),add(v,u);
    }
    dfs(1,0);
    C[0][0]=fac[0]=1;
    for(int i=1;i<=n;i++){
        C[i][0]=1,fac[i]=fac[i-1]*i%Mod;
        for(int j=1;j<=n;j++)C[i][j]=(C[i-1][j]+C[i-1][j-1])%Mod;
    }
    for(int i=n/2;i>=0;i--){
        (f[1][i]*=fac[n/2-i])%=Mod;
        for(int j=i+1;j<=n/2;j++)_mod(f[1][i],-f[1][j]*C[j][i]);
        _mod(f[1][i],Mod);
    }
    for(int i=0;i<=n/2;i++)_wri(f[1][i]);
    return 0;
}

