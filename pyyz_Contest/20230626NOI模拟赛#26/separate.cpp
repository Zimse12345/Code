// Author:Zimse  Data:2023-06-
#include <bits/stdc++.h>
#define pc putchar
#define pb push_back
#define inv fpow
//#define int long long
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

const int N=1.01e6;
int n,w[N],fa[N],mex,ans[N],mx[N];
vector<int> g[N];

void dfs(int u){
    int x=0,y=0;
    for(unsigned i=0;i<g[u].size();i++){
        int v=g[u][i];
        dfs(v);
        if(mx[v]>x)y=x,x=mx[v];
        else if(mx[v]>y)y=mx[v];
    }
    mx[u]=0;
    if(w[u]==mex)return;
    mx[u]=x+1;
    _max(ans[u],x+y+1-mex);
    return;
}

void dfs2(int u){
    for(unsigned i=0;i<g[u].size();i++)dfs2(g[u][i]),_max(ans[u],ans[g[u][i]]);
    return;
}

signed main(){
    iF("separate.in");
    oF("separate.out");
    
    n=read();
    for(int i=1;i<=n;i++)w[i]=read();
    for(int i=2;i<=n;i++)fa[i]=read(),g[fa[i]].pb(i);
    int lim=n;
    if(n>7000)lim=101;
    for(mex=0;mex<=lim;mex++)dfs(1);
    dfs2(1);
    for(int i=1;i<=n;i++)wri(ans[i]);
    return 0;
}



