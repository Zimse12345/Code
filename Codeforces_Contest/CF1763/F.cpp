/********************************
*FileName:
*Author: Zimse
*Data: 2022-12-
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
// #define int long long
// #define M ((L+R)/2)
// #define Lid (id<<1)
// #define Rid (Lid|1)
// #define Lid ch[id][0]
// #define Rid ch[id][1]

using namespace std;

namespace Zimse{
const int Mod=998244353;
// const int Mod=1000000007;

inline int read(){int x=0,y=1;char c=gc();while(c<48||57<c)
{if(c==45)y=-1;c=gc();}while(47<c&&c<58)x=x*10+c-48,c=gc();return x*y;}
inline void write(int x){if(x<0)pc(45),x=-x;if(x>=10)write(x/10);pc(48+x%10);return;}
inline void _Yes(){pc(89),pc(101),pc(115),pc(10);return;}
inline void _No(){pc(78),pc(111),pc(10);return;}
inline void _ck(bool x){x?yes:no;return;}
inline void write_(int x){write(x),pc(32);return;}
inline void _write(int x){write(x),pc(10);return;}
inline void ifile(const char str[]){freopen(str,"r",stdin);return;}
inline void ofile(const char str[]){freopen(str,"w",stdout);return;}
inline void cfile(){fclose(stdin),fclose(stdout);return;}
inline ll fpow(ll x,ll y){ll res=1;while(y){if(y&1)res=res*x%Mod;x=x*x%Mod,y/=2;}return res;}
inline ll inv(ll x){return fpow(x,Mod-2);}
inline int _gcd(int x,int y){return y?_gcd(y,x%y):x;}
inline int _abs(int x){return x<0?-x:x;}
inline void _max(int& x,int y){if(x<y)x=y;return;}
inline void _min(int& x,int y){if(y<x)x=y;return;}
inline void addmod(int& x,int y){(x+=y)%=Mod;return;}
const int INF=1000114514;
}using namespace Zimse;

const int N=1000007;

int n,m,q,hd[N],nxt[N],to[N],ec;
int dfn[N],low[N],Time,vis[N],stk[N],top,col[N],sz[N],cc;
int Hd[N],Nxt[N],To[N],frompos[N],topos[N],Ec;
int fa[200010][20],fb[200010][20],fsum[200010][20],uu[N],dep[N];

inline void add(int u,int v){
    nxt[++ec]=hd[u],hd[u]=ec,to[ec]=v;
    return;
}

inline void Add(int u,int v,int _u,int _v){
    Nxt[++Ec]=Hd[u],Hd[u]=Ec,To[Ec]=v,frompos[Ec]=_u,topos[Ec]=_v;
    return;
}

void tarjan(int u,int from){
    dfn[u]=low[u]=++Time,stk[++top]=u;
    for(int i=hd[u],v;i;i=nxt[i]){
        v=to[i];
        if(v==from)continue;
        if(!dfn[v]){
            tarjan(v,u);
            if(low[v]>dfn[u]){
                ++cc;
                while(stk[top]!=u)col[stk[top]]=cc,--top;
            }
        }
        low[u]=min(low[u],low[v]);
    }
    return;
}

void dfs(int u,int from){
    dep[u]=dep[from]+1;
    for(int i=Hd[u],v;i;i=Nxt[i]){
        v=To[i];
        if(v==from)continue;
        dfs(v,u);
        fa[v][0]=u,fb[v][0]=frompos[i],uu[v]=topos[i];
    }
    return;
}

void up(int& y,int& yy,int i,int& ans){
    if(yy!=uu[y])ans+=sz[y];
    ans+=fsum[y][i];
    yy=fb[y][i],y=fa[y][i];
    return;
}

signed main(){
    n=read(),m=read();
    for(int i=1,u,v;i<=m;i++){
        u=read(),v=read();
        add(u,v),add(v,u);
    }
    tarjan(1,0);
    ++cc;
    while(top>0)col[stk[top]]=cc,--top;
    for(int u=1;u<=n;u++){
        for(int i=hd[u],v;i;i=nxt[i]){
            v=to[i];
            if(u>v)continue;
            if(col[u]!=col[v]){
                Add(col[u],col[v],u,v);
                Add(col[v],col[u],v,u);
            }
            else ++sz[col[u]];
        }
    }
    dfs(1,0);
    for(int i=1;i<20;i++){
        for(int j=1;j<=n;j++){
            int x=fa[j][i-1],y=fb[j][i-1];
            fa[j][i]=fa[x][i-1];
            fb[j][i]=fb[x][i-1];
            fsum[j][i]=fsum[j][i-1]+fsum[x][i-1];
            if(uu[x]!=y)fsum[j][i]+=sz[x];
        }
    }
    q=read();
    while(q--){
        int xx=read(),yy=read();
        int x=col[xx],y=col[yy],ans=0;
        if(dep[y]<dep[x])swap(x,y),swap(xx,yy);
        for(int i=19;i>=0;i--)if(dep[fa[y][i]]>=dep[x])up(y,yy,i,ans);
        for(int i=19;i>=0;i--)if(fa[x][i]!=fa[y][i])up(x,xx,i,ans),up(y,yy,i,ans);
        if(x!=y)up(x,xx,0,ans),up(y,yy,0,ans);
        if(xx!=yy)ans+=sz[x];
        _write(ans);
    }
    return 0;
}
