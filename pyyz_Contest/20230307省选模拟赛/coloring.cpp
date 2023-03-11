/************************
*FileName:
*Author: Zimse
*Data: 2023-02-
*Description:
************************/

#include <algorithm>
#include <cctype>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <ctime>
#include <iostream>
#include <map>
#include <queue>
#include <set>
#include <stack>
#include <vector>

#define gc getchar
#define pc putchar
#define yes printf("Yes\n")
#define no printf("No\n")
#define pb push_back
#define ll long long
// #define int long long
// #define M ((L+R)/2)
// #define Lid (id<<1)
// #define Rid (Lid|1)

namespace Zimse{
const int INF=1000114514;
const int Mod=998244353;
// const int Mod=1000000007;
inline int read(){int x=0,y=1;char c=gc();while(c<48||57<c)
{if(c==45)y=-1;c=gc();}while(47<c&&c<58)x=x*10+c-48,c=gc();return x*y;}
inline void write(int x){if(x<0)pc(45),x=-x;if(x>=10)write(x/10);pc(48+x%10);return;}
inline void _ck(bool x){x?yes:no;return;}
inline void write_(int x){write(x),pc(32);return;}
inline void _write(int x){write(x),pc(10);return;}
inline void ifile(const char str[]){freopen(str,"r",stdin);return;}
inline void ofile(const char str[]){freopen(str,"w",stdout);return;}
inline ll fpow(ll x,ll y){ll res=1;while(y){if(y&1)res=res*x%Mod;x=x*x%Mod,y/=2;}return res;}
inline ll inv(ll x){return fpow(x,Mod-2);}
inline int _gcd(int x,int y){return y?_gcd(y,x%y):x;}
inline int _lcm(int x,int y){return x/_gcd(x,y)*y;}
inline int _abs(int x){return x<0?-x:x;}
inline void _max(int& x,int y){if(x<y)x=y;return;}
inline void _min(int& x,int y){if(y<x)x=y;return;}
inline void addmod(int& x,int y){(x+=y)%=Mod;return;}
}using namespace Zimse;using namespace std;

const int N=1000007;

int T,n,v[N],sum[N],Tag,f[N];
bool g[1024][5120];
vector<int> ch[N];

signed main(){
    T=read();
    while(T--){
        n=read(),Tag=1;
        for(int i=2;i<=n;i++)ch[read()].pb(i);
        for(int i=1;i<=n;i++)v[i]=read();
        for(int u=n;u>=1;u--){
            sum[u]=v[u],f[u]=0;
            g[u][0]=true;
            for(int i=1;i<=v[u];i++)g[u][i]=false;
            for(unsigned i=0;i<ch[u].size();i++){
                int to=ch[u][i];
                sum[u]+=sum[to];
                f[u]+=v[to]+f[to];
                for(int j=v[u];j>=0;j--){
                    bool gg=false;
                    if(j>=v[to])gg|=g[u][j-v[to]];
                    if(j>=f[to])gg|=g[u][j-f[to]];
                    g[u][j]=gg;
                }
            }
            int pos=-1;
            for(int i=v[u];i>=0;i--)if(g[u][i]){
                pos=i;
                break;
            }
            if(pos<0){
                Tag=0;
                break;
            }
            f[u]-=pos;
        }
        if(Tag)printf("POSSIBLE\n");
        else printf("IMPOSSIBLE\n");
        for(int i=1;i<=n;i++)ch[i].resize(0);
    }
    return 0;
}
