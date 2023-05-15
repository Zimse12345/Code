// Author: Zimse
// Data: 2023-05-

#include <bits/stdc++.h>
#define gc getchar
#define pc putchar
#define pb push_back
#define inv fpow
#define int long long
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
inline int _abs(int x){return x<0?-x:x;}
}using namespace Zimse;using namespace std;

const int N=1.01e6;
int T,n,f[N][2],l[N],r[N];
vector<int> g[N];

void dfs(int u,int from){
    f[u][0]=f[u][1]=0;
    for(unsigned i=0;i<g[u].size();i++){
        int v=g[u][i];
        if(v==from)continue;
        dfs(v,u);
        f[u][0]+=max(f[v][0]+_abs(l[u]-l[v]),f[v][1]+_abs(l[u]-r[v]));
        f[u][1]+=max(f[v][0]+_abs(r[u]-l[v]),f[v][1]+_abs(r[u]-r[v]));
    }
    return;
}

signed main(){
    T=read();
    while(T--){
        n=read();
        for(int i=1;i<=n;i++)l[i]=read(),r[i]=read();
        for(int i=1,u,v;i<n;i++){
            u=read(),v=read();
            g[u].pb(v),g[v].pb(u);
        }
        dfs(1,0);
        _write(max(f[1][0],f[1][1]));
        for(int i=1;i<=n;i++)g[i].resize(0);
    }
    return 0;
}

