#include <bits/stdc++.h>
#define int long long
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

const int N=1.01e6,M=5.01e3;
int fac[N],ifac[N];
int T,n,fa[N],a[N],dep[N],tag,pre[N],ans,vis[N],t[M][M],c[M][M];
vector<int> g[N],p[N],s[N];

inline int C(int x,int y){
    if(y<0||x<y)return 0;
    return fac[x]*ifac[y]%Mod*ifac[x-y]%Mod;
}

void dfs(int u,int from){
    dep[u]=dep[from]+1;
    if(a[u]>=dep[u]){
        tag=1;
        return;
    }
    p[u].resize(dep[u]+1);
    for(int i=1;i<=dep[from];i++){
        if(i<=a[u])p[u][i]=p[from][i];
        else p[u][i+1]=p[from][i];
    }
    p[u][a[u]+1]=u;
    pre[u]=p[u][a[u]];
    
    for(unsigned i=0;i<g[u].size();i++){
        int v=g[u][i];
        if(v==from)continue;
        dfs(v,u);
    }
    return;
}

void dfs2(int u){
    s[u].push_back(u);
    for(unsigned i=0;i<g[u].size();i++){
        int v=g[u][i];
        dfs2(v);
        for(unsigned j=0;j<s[v].size();j++){
            int z=s[u][j];
            while(a[z]&&(!vis[p[z][a[z]]]))a[z]--;
            pre[z]=p[z][a[z]];
            c[u][pre[z]]++;
            s[u].push_back(z);
        }
        for(int i=0;i<=n;i++){
            (ans*=C(t[u][i]+c[u][i],c[u][i]))%=Mod;
            (t[u][i]+=c[u][i])%=Mod,c[u][i]=0;
        }
    }
    vis[u]=0;
    return;
}

signed main(){
    fac[0]=1;
    for(int i=1;i<N;i++)fac[i]=fac[i-1]*i%Mod;
    for(int i=0;i<N;i++)ifac[i]=inv(fac[i]);
    cin>>T;
    while(T--){
        cin>>n;
        for(int i=1;i<=n;i++){
            g[i].resize(0);
            s[i].resize(0);
            pre[i]=0;
            vis[i]=1;
            for(int j=0;j<=n;j++)c[i][j]=t[i][j]=0;
        }
        ans=1;
        for(int i=2;i<=n;i++){
            cin>>fa[i];
            g[fa[i]].push_back(i);
        }
        for(int i=1;i<=n;i++)cin>>a[i];
        tag=0;
        dfs(1,0);
        if(tag){
            printf("0\n");
            continue;
        }
        dfs2(1);
        printf("%lld\n",ans);
    }
    return 0;
}


