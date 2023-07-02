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

const int N=64;
int n,m[N],f[N][N],ans;
struct edge{
    int u,v;
    edge(int u=0,int v=0):u(u),v(v){}
};
vector<edge> e[N];

inline int GetDet(){
    int det=1;
    for(int i=1;i<n;i++){
        int t=0;
        for(int j=i;j<n;j++)if(f[j][i]){t=j;break;}
        for(int j=1;j<n;j++)swap(f[i][j],f[t][j]);
        if(t^i)det=-det;
        for(int j=i+1;j<n;j++){
            int v=f[j][i]*inv(f[i][i])%Mod;
            for(int k=i+1;k<n;k++)_mod(f[j][k],-v*f[i][k]);
        }
    }
    for(int i=1;i<n;i++)det=det*f[i][i]%Mod;
    for(int i=1;i<n;i++)for(int j=1;j<n;j++)f[i][j]=0;
    _mod(det,Mod);
    return det;
}

signed main(){
    n=read();
    for(int i=0;i<n-1;i++){
        m[i]=read();
        for(int j=0,u,v;j<m[i];j++){
            u=read(),v=read();
            e[i].pb(edge(u,v));
        }
    }
    for(int i=0;i<(1<<(n-1));i++){
        int popc=0;
        for(int j=0;j<n-1;j++)if(i&(1<<j)){
            ++popc;
            for(int k=0;k<m[j];k++){
                int x=e[j][k].u,y=e[j][k].v;
                ++f[x][x],++f[y][y];
                --f[x][y],--f[y][x];
            }
        }
        _mod(ans,GetDet()*(((n-1-popc)&1)?-1:1));
    }
    _mod(ans,Mod);
    _wri(ans);
    return 0;
}

