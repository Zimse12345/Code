// Author: Zimse
// Data: 2023-05-

#include <bits/stdc++.h>
#define gc getchar
#define pc putchar
#define pb push_back
#define inv fpow
//#define int long long
//#define M ((L+R)/2)
namespace Zimse{const int INF=1.01e9,Mod=998244353;
int read(){int x=0,y=1;char c=gc();while(c<48||57<c){if(c==45)
y=-1;c=gc();}while(47<c&&c<58)x=x*10+c-48,c=gc();return x*y;}
void WRI(int x){if(x<0)pc(45),x=-x;if(x>=10)WRI(x/10);pc(48+x%10);}
void write_(int x){WRI(x),pc(32);}void _write(int x){WRI(x),pc(10);}
void ifile(const char *x){freopen(x,"r",stdin);}
void ofile(const char *x){freopen(x,"w",stdout);}
inline int fpow(long long x,int y=Mod-2){int z=1;
while(y){if(y&1)z=x*z%Mod;x=x*x%Mod,y/=2;}return z;}
inline void _max(int &x,int y){if(x<y)x=y;}
inline void _min(int &x,int y){if(y<x)x=y;}
inline void addmod(int &x,int y){(x+=y)%=Mod;}
}using namespace Zimse;using namespace std;

const int N=1.01e6;
int T,n,U,ans,fa[N],sz[N],cnt;
int *ptr[N],val[N],cur;
vector<int> g1[N],g2[N];

inline int F(int x){
    return x==fa[x]?x:F(fa[x]);
}

inline void rem(int &x){
    ptr[++cur]=&x,val[cur]=x;
    return;
}

inline void link(int u,int v){
    u=F(u),v=F(v);
    if(!u||!v)return;
    if(sz[u]<sz[v])swap(u,v);
    rem(fa[v]),rem(sz[u]);
    fa[v]=u,sz[u]+=sz[v],--cnt;
    return;
}

void dfs(int u,int from){
    int _cur=cur;
    rem(cnt);
    fa[u]=u,sz[u]=1,++cnt;
    for(unsigned i=0;i<g1[u].size();i++)link(u,g1[u][i]);
    if(cnt==1&&u>=U)++ans;
    for(unsigned i=0;i<g2[u].size();i++)if(g2[u][i]!=from)dfs(g2[u][i],u);
    while(cur>_cur)*ptr[cur]=val[cur],--cur;
    fa[u]=sz[u]=0;
    return;
}

signed main(){
    // ifile("forest.in");
    // ofile("forest.out");

    T=read();
    while(T--){
        n=read(),ans=0;
        for(int i=1,u,v;i<n;i++){
            u=read(),v=read();
            g1[u].pb(v),g1[v].pb(u);
        }
        for(int i=1,u,v;i<n;i++){
            u=read(),v=read();
            g2[u].pb(v),g2[v].pb(u);
        }
        for(int i=1;i<=n;i++)U=i,dfs(i,0);
        _write(ans);
        for(int i=1;i<=n;i++)g1[i].resize(0),g2[i].resize(0);
    }
    return 0;
}

