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

const int N=1.01e4;
int n,dep[N],ans[N];
vector<int> g[N];

void dfs(int u,int from){
    dep[u]=dep[from]+1;
    for(unsigned i=0;i<g[u].size();i++)if(g[u][i]!=from)dfs(g[u][i],u);
    return;
}

signed main(){
    n=read();
    for(int i=1,u,v;i<n;i++){
        u=read(),v=read();
        g[u].pb(v),g[v].pb(u);
    }
    dep[0]=-1;
    for(int i=1;i<=n;i++){
        dfs(i,0);
        sort(dep+1,dep+n+1);
        for(int j=1,s=0;j<=n;j++){
            s+=dep[j];
            _max(ans[j],j*(j-1)-s*2);
        }
    }
    for(int i=0;i<=n;i++){
        ans[i]+=i*(n-i);
        wri(ans[i]);
    }
    pc(10);
    return 0;
}



