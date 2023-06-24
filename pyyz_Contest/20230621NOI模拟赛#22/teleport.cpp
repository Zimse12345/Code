// Author:Zimse  Data:2023-06-
#include <bits/stdc++.h>
#define pc putchar
#define pb push_back
#define inv fpow
#define int long long
//#define M ((L+R)/2)
namespace OI{const int INF=1.01e15,Mod=998244353;int read(){int x=0
,y=1;char c=getchar();while(c<48||57<c){if(c==45)y=-1;c=getchar();}
while(47<c&&c<58)x=x*10+c-48,c=getchar();return x*y;}void wr(int x)
{if(x<0)pc(45),x=-x;if(x>=10)wr(x/10);pc(48+x%10);}void wri(int x){
wr(x),pc(32);}void _wri(int x){wr(x),pc(10);}void iF(const char*x){
freopen(x,"r",stdin);}void oF(const char*x){freopen(x,"w",stdout);}
inline int fpow(long long x,int y=Mod-2){int z=1;while(y){if(y&1)z=
x*z%Mod;x=x*x%Mod,y/=2;}return z;}inline void _max(int&x,int y){if(
x<y)x=y;}inline void _min(int&x,int y){if(y<x)x=y;}inline void _mod
(int&x,int y){(x+=y)%=Mod;}}using namespace OI;using namespace std;

const int N=1.01e3;
int n,p,f[N][N][22],s[N],tot,dep[N];
struct edge{
    int to,len;
    edge(int to=0,int len=0):to(to),len(len){}
};
vector<edge> g[N];

void dp(int u){
    s[++tot]=u;
    for(unsigned i=0;i<g[u].size();i++){
        int v=g[u][i].to;
        dep[v]=dep[u]+g[u][i].len;
        dp(v);
        for(int pre=0;pre<tot;pre++){
            for(int x=0;x<=p;x++){
                f[u][pre][x]+=min(f[v][pre][x]+dep[u]-dep[s[pre]],x?f[v][tot][x-1]:INF)+g[u][i].len;
            }
        }
    }
    for(int pre=0;pre<tot;pre++){
        for(int x=0;x<=p;x++){
            if(x)_min(f[u][pre][x],f[u][pre][x-1]);
            int mx=0;
            for(unsigned i=0;i<g[u].size();i++){
                int v=g[u][i].to;
                _max(mx,min(f[v][pre][x]+dep[u]-dep[s[pre]],x?f[v][tot][x-1]:INF)
                        -min(f[v][pre][x],x?f[v][tot][x-1]:INF));
            }
            f[u][pre][x]-=mx;
        }
    }
    --tot;
    return;
}

signed main(){
    iF("teleport.in");
    oF("teleport.out");

    n=read(),p=read();
    int _p=p;
    p=min(p,20ll);
    for(int i=2,fa,len;i<=n;i++){
        fa=read(),len=read();
        g[fa].pb(edge(i,len));
    }
    dep[0]=-INF;
    dp(1);
    for(int i=1;i<=p;i++)_wri(f[1][0][i]);
    for(int i=p+1;i<=_p;i++)_wri(f[1][0][p]);
    return 0;
}

