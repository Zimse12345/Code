/************************
*FileName:
*Author: Zimse
*Data: 2023-02-
*Description:
************************/

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
#define int long long
// #define M ((L+R)/2)
// #define Lid (id<<1)
// #define Rid (Lid|1)
// #define Lid ch[id][0]
// #define Rid ch[id][1]

namespace Zimse{
const int INF=1000114514;
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
inline ll fpow(ll x,ll y){ll res=1;while(y){if(y&1)res=res*x%Mod;x=x*x%Mod,y/=2;}return res;}
inline ll inv(ll x){return fpow(x,Mod-2);}
inline int _gcd(int x,int y){return y?_gcd(y,x%y):x;}
inline int _lcm(int x,int y){return x/_gcd(x,y)*y;}
inline int _abs(int x){return x<0?-x:x;}
inline void _max(int& x,int y){if(x<y)x=y;return;}
inline void _min(int& x,int y){if(y<x)x=y;return;}
inline void addmod(int& x,int y){(x+=y)%=Mod;return;}
}using namespace Zimse;using namespace std;

const int N=1000007,M=500000;

int n,q,A,T,hd[N],nxt[N],to[N],len[N],val[N],ec;
int cnt[N],mn,_n,rt,vis[N],ans[N],pa[N],fa[N][24],fd[N][24],dep[N];

struct node{
    int v,dis,pre;
    node(int v=0,int dis=0,int pre=0):v(v),dis(dis),pre(pre){}
    bool operator < (const node& _)const{return v<_.v;}
};
vector<node> f[N],g[N];

inline void add(int u,int v,int  w){
    nxt[++ec]=hd[u],hd[u]=ec,to[ec]=v,len[ec]=w;
}

void findrt(int u,int from){
    if(!T)fa[u][0]=from,dep[u]=dep[from]+1;
    cnt[u]=1;
    int mx=0;
    for(int i=hd[u],v;i;i=nxt[i]){
        v=to[i];
        if(v==from||vis[v])continue;
        if(!T)fd[v][0]=len[i];
        findrt(v,u),cnt[u]+=cnt[v];
        _max(mx,cnt[u]);
    }
    _max(mx,_n-cnt[u]);
    if(mx<mn)mn=mx,rt=u;
    return;
}

void dfs(int u,int from,int d,int U){
    if(U>0)f[U].pb(node(val[u],d,d));
    else g[-U].pb(node(val[u],d,d));
    for(int i=hd[u],v;i;i=nxt[i]){
        v=to[i];
        if(v==from||vis[v])continue;
        dfs(v,u,d+len[i],U);
    }
    return;
}

void divide(int u){
    vis[u]=1;
    dfs(u,0,0,u);
    sort(f[u].begin(),f[u].end());
    for(unsigned i=1;i<f[u].size();i++)f[u][i].pre+=f[u][i-1].pre;
    for(int i=hd[u],v;i;i=nxt[i]){
        v=to[i];
        if(vis[v])continue;
        mn=INF,_n=cnt[v],findrt(v,0);
        dfs(v,u,len[i],-rt);
        sort(g[rt].begin(),g[rt].end());
        for(unsigned j=1;j<g[rt].size();j++)g[rt][j].pre+=g[rt][j-1].pre;
        pa[rt]=u;
        divide(rt);
    }
    return;
}

node F(const vector<node>& a,int p){
    int L=0,R=a.size()-1,res=-1;
    while(L<=R){
        int M=(L+R)/2;
        if(a[M].v<=p)res=M,L=M+1;
        else R=M-1;
    }
    node x;
    if(res>=0)x.v=res+1,x.dis=a[res].pre;
    return x;
}

node C(node x,node y){
    x.v-=y.v,x.dis-=y.dis;
    return x;
}

int Dis(int u,int v){
    int dis=0;
    if(dep[u]<dep[v])swap(u,v);
    for(int i=23;i>=0;i--)if(dep[fa[u][i]]>=dep[v])dis+=fd[u][i],u=fa[u][i];
    for(int i=23;i>=0;i--)if(fa[u][i]!=fa[v][i])dis+=fd[u][i]+fd[v][i],u=fa[u][i],v=fa[v][i];
    if(u!=v)dis+=fd[u][0]+fd[v][0];
    return dis;
}

signed main(){
    n=read(),q=read(),A=read();
    for(int i=1;i<=n;i++)val[i]=read();
    for(int i=1,u,v,w;i<n;i++)u=read(),v=read(),w=read(),add(u,v,w),add(v,u,w);
    mn=INF,_n=n,findrt(1,0),T=1;
    divide(rt);
    for(int i=1;i<24;i++){
        for(int j=1;j<=n;j++)fa[j][i]=fa[fa[j][i-1]][i-1],fd[j][i]=fd[j][i-1]+fd[fa[j][i-1]][i-1];
    }
    for(int i=1,ans=0,L,R,u;i<=q;i++){
        u=read(),L=(read()+ans)%A,R=(read()+ans)%A,ans=0;
        if(R<L)swap(L,R);
        int pre=0,U=u;
        while(u){
            node x,y;
            x=C(F(f[u],R),F(f[u],L-1));
            if(pre)y=C(F(g[pre],R),F(g[pre],L-1));
            ans+=(x.dis-y.dis)+(x.v-y.v)*Dis(U,u);
            pre=u,u=pa[u];
        }
        _write(ans);
    }
    return 0;
}
