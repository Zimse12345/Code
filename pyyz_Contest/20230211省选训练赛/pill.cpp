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
// #define int long long
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

const int N=4e5+7;
int n,m,s,t,hd[N],h[N],nxt[N],ec=1,d[N],Tag;
struct edge{
    int v,f;
    edge(int v=0,int f=0):v(v),f(f){}
}E[N];
inline void add(int u,int v,int f){nxt[++ec]=hd[u],hd[u]=ec,E[ec]=edge(v,f);return;}
inline void Add(int u,int v,int f){add(u,v,f),add(v,u,0);return;}

queue<int> Q;
bool bfs(){
    for(int i=1;i<=n;i++)d[i]=0;
    d[s]=1,Q.push(s);
    while(!Q.empty()){
        int u=Q.front();
        Q.pop();
        for(int i=hd[u];i;i=nxt[i])if(E[i].f&&!d[E[i].v])d[E[i].v]=d[u]+1,Q.push(E[i].v);
    }
    return d[t];
}

int dfs(int u,int maxf){
    if(u==t||!maxf)return maxf;
    int flow=0;
    for(int i=h[u];i;i=nxt[i]){
        if(d[u]+1==d[E[i].v]){
            int f=dfs(E[i].v,min(maxf,E[i].f));
            flow+=f,maxf-=f,E[i].f-=f,E[i^1].f+=f;
            if(!maxf)break;
        }
        h[u]=nxt[h[u]];
    }
    if(!flow)d[u]=0;
    return flow;
}

void dinic(){
    while(bfs()){
        dfs(s,INF);
        for(int i=1;i<=n;i++)h[i]=hd[i];
    }
    return;
}

int p[400][400],cnt[400],id[400][400],to[400],from[400],Id[400];
int Hd[N],Nxt[N],To[N],Ec,cl[N],cc,sum[N],val[N],Link[400][400];
int F[N],G[N],ans,tag[N];
vector<int> g[N];

inline void link(int u,int v){
    Nxt[++Ec]=Hd[u],Hd[u]=Ec,To[Ec]=v;
    return;
}

int dfn[N],low[N],st[N],ins[N],top,ct;
void tarjan(int u){
    dfn[u]=low[u]=++ct,st[++top]=u,ins[u]=1;
    for(int i=Hd[u],v;i;i=Nxt[i]){
        v=To[i];
        if(!dfn[v])tarjan(v),_min(low[u],low[v]);
        else if(ins[v])_min(low[u],dfn[v]);
    }
    if(dfn[u]==low[u]){
        ++cc;
        while(st[top+1]!=u)ins[st[top]]=0,cl[st[top]]=cc,sum[cc]+=val[st[top]],--top;
    }
    return;
}

void Dfs(int u){
    if(tag[u]++)return;
    ans+=sum[u];
    for(unsigned i=0;i<g[u].size();i++)Dfs(g[u][i]);
    return;
}

signed main(){
    //  ifile("pill.in");
    //  ofile("pill.out");
	
    m=read();
    n=m*2,s=++n,t=++n;
    for(int i=1;i<=m;i++){
        cnt[i]=read();
        for(int j=1;j<=cnt[i];j++)p[i][j]=read(),Add(i,m+p[i][j],1),id[i][j]=ec-1;
        Add(s,i,1),Add(m+i,t,1);
    }
    for(int i=1;i<=m;i++)val[i]=read();
    dinic();
    for(int i=1;i<=m;i++){
        for(int j=1;j<=cnt[i];j++)if(E[id[i][j]].f==0)to[i]=p[i][j];
        from[to[i]]=i;
    }
    for(int i=1;i<=m;i++){
        for(int j=1;j<=cnt[i];j++)if(p[i][j]!=to[i])link(i,from[p[i][j]]);
    }
    for(int i=1;i<=m;i++)link(0,i);
    tarjan(0);
    for(int i=0;i<=n;i++)hd[i]=0;
    ec=1,n=cc,Tag=1;
    for(int u=0;u<=m;u++){
        for(int i=Hd[u],v;i;i=Nxt[i]){
            v=To[i];
            if(cl[u]!=cl[v]&&!Link[cl[u]][cl[v]]){
                Link[cl[u]][cl[v]]=1;
                Add(cl[u],cl[v],INF);
                g[cl[u]].pb(cl[v]);
            }
        }
    }
    s=++n,t=++n;
    for(int i=1;i<=cc;i++){
        if(sum[i]<0)Add(s,i,-sum[i]);
        else Add(i,t,sum[i]);
        Id[i]=ec-1;
    }
    dinic();
    for(int i=1;i<=cc;i++){
        if(E[Id[i]].f&&sum[i]<0)Dfs(i);
    }
    _write(ans);
	return 0;
}
