/********************************
*FileName:
*Author: Zimse
*Data: 2022-09-
*Description:
*Other:
********************************/

#include <cstdio>
#include <algorithm>
#include <cstring>
#include <vector>
#include <cmath>
#include <set>
#include <map>
#include <queue>
#include <stack>
#include <iostream>
#include <cstdlib>
#include <ctime>
#include <cctype>

#define gc getchar
#define pc putchar
#define yes _Yes()
#define no _No()
#define pb push_back
#define ll long long
//#define int long long
//#define M ((L+R)/2)
//#define Lid (id<<1)
//#define Rid (Lid|1)
//#define Lid ch[id][0]
//#define Rid ch[id][1]

using namespace std;

namespace Zimse{
const int Mod=998244353;
//const int Mod=1000000007;
inline int read(){int x=0,y=1;char c=gc();while(c<48||57<c){if(c==45)y=-1;c=gc();}while(47<c&&c<58)x=x*10+c-48,c=gc();return x*y;}
inline void write(int x){if(x<0)pc(45),x=-x;if(x>=10)write(x/10);pc(48+x%10);return;}
inline void _Yes(){pc(89),pc(101),pc(115),pc(10);return;}
inline void _No(){pc(78),pc(111),pc(10);return;}
inline void _ck(bool x){x?yes:no;return;}
inline void write_(int x){write(x),pc(32);return;}
inline void _write(int x){write(x),pc(10);return;}
inline void ifile(const char str[]){freopen(str,"r",stdin);return;}
inline void ofile(const char str[]){freopen(str,"w",stdout);return;}
inline void cfile(){fclose(stdin),fclose(stdout);return;}
inline ll fpow(ll x,ll y){ll res=1ll;while(y){if(y&1ll)res=res*x%Mod;x=x*x%Mod,y/=2ll;}return res;}
inline ll inv(ll x){return fpow(x,Mod-2);}
inline int _gcd(int x,int y){return y?_gcd(y,x%y):x;}
inline int _abs(int x){return x<0?-x:x;}
inline void _max(int& x,int y){if(x<y)x=y;return;}
inline void _min(int& x,int y){if(y<x)x=y;return;}
inline void addmod(int& x,int y){(x+=y)%=Mod;return;}
const int INF=1000114514;
}using namespace Zimse;

const int N=1e6+7;

int n,a[N],hd[N],nxt[N],to[N],ec,f[N][2],g[N][2];

inline void add(int u,int v){
    nxt[++ec]=hd[u],hd[u]=ec,to[ec]=v;
    return;
}

void dfs(int u,int from){
    int lc=0,rc=0;
    for(int i=hd[u],v;i;i=nxt[i]){
        v=to[i];
        if(v==from)continue;
        dfs(v,u);
        if(!lc)lc=v;
        else rc=v;
    }
    if(!lc){
        f[u][a[u]^1]=1;
        g[u][a[u]^1]=1;
        g[u][a[u]]=2;
    }
    else if(!rc){
        if(a[u]){
            f[u][0]=min(f[lc][1],g[lc][1])+1;
            f[u][1]=min(f[lc][1],g[lc][1]);
            g[u][0]=min(f[lc][0]+1,g[lc][0]);
            g[u][1]=min(g[u][0],f[u][0])+1;
        }
        else{
            f[u][1]=min(f[lc][0],g[lc][0])+1;
            f[u][0]=min(f[lc][0],g[lc][0]);
            g[u][1]=min(f[lc][1]+1,g[lc][1]);
            g[u][0]=min(g[u][1],f[u][1])+1;
        }
    }
    else{
        for(int c=0;c<2;c++){
            if(a[u]^c){
                f[u][c]=min(f[lc][c^1],g[lc][c^1])+min(f[rc][c^1],g[rc][c^1])+1;
                _min(f[u][c],g[lc][c]+g[rc][c]-1);
                g[u][c]=min(f[lc][c],g[lc][c])+min(f[rc][c],g[rc][c])+1;
                _min(g[u][c],g[lc][c]+min(f[rc][c],g[rc][c]));
                _min(g[u][c],g[rc][c]+min(f[lc][c],g[lc][c]));
            }
            else{
                f[u][c]=min(f[lc][c],g[lc][c])+min(f[rc][c],g[rc][c]);
                _min(f[u][c],g[lc][c^1]+g[rc][c^1]);
                g[u][c]=min(f[lc][c^1],g[lc][c^1])+min(f[rc][c^1],g[rc][c^1])+2;
                _min(g[u][c],g[lc][c^1]+min(f[rc][c^1],g[rc][c^1])+1);
                _min(g[u][c],g[rc][c^1]+min(f[lc][c^1],g[lc][c^1])+1);
            }
        }
    }
    // printf("id=%d f0=%d f1=%d g0=%d g1=%d\n",u,f[u][0],f[u][1],g[u][0],g[u][1]);
    // g[u][0]=g[u][1]=INF;
    return;
}

signed main(){
    n=read();
    for(int i=1;i<=n;i++)a[i]=read();
    for(int i=1,u,v;i<n;i++)u=read(),v=read(),add(u,v),add(v,u);
    dfs(1,0);
    _write(min(min(f[1][0],f[1][1]),min(g[1][0],g[1][1])));
    return 0;
}
