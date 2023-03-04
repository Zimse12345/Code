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

const int N=2048;

int T,n,val[N],hd[N],nxt[N],to[N],ec,dep[N],idep[N],f[N][N];

inline void add(int u,int v){
    nxt[++ec]=hd[u],hd[u]=ec,to[ec]=v;
}

void dfs0(int u,int from){
    idep[u]=1,dep[u]=dep[from]+1;
    for(int i=hd[u],v;i;i=nxt[i]){
        v=to[i];
        if(v==from)continue;
        dfs0(v,u);
        _max(idep[u],idep[v]+1);
    }
    for(int i=0;i<(1<<idep[u]);i++){
        f[u][i]=INF;
        for(int j=i;;j=(j-1)&i){
            if((i^j)&1){
                if(!j)break;
                continue;
            }
            int sum=0;
            for(int k=0;k<n;k++)if(j&(1<<k))sum+=val[k];
            for(int k=hd[u],v;k;k=nxt[k]){
                v=to[k];
                if(v==from)continue;
                sum+=f[v][((1<<idep[v])-1) & ((i^j)/2)];
            }
            
            _min(f[u][i],sum);
            if(!j)break;
        }
    }
    return;
}

signed main(){
    T=read();
    while(T--){
        n=read();
        for(int i=0;i<n;i++)val[i]=read();
        for(int i=1,u,v;i<n;i++)u=read(),v=read(),add(u,v),add(v,u);
        dfs0(1,0);
        _write(f[1][(1<<idep[1])-1]);
        for(int i=1;i<=n;i++)hd[i]=0;
        ec=0;
    }
    return 0;
}
