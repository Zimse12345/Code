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

int n,m,U[N],V[N],W[N],dis[30][30];
int s,t,hd[N],h[N],nxt[N],d[N],ec,popc[N];
int f[N][20];
struct edge{
    int v,f;
    edge(int v=0,int f=0):v(v),f(f){}
}E[N];
inline void add(int u,int v,int f){nxt[++ec]=hd[u],hd[u]=ec,E[ec]=edge(v,f);return;}
inline void Add(int u,int v,int f){add(u,v,f),add(v,u,f);return;}

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

int dinic(int S,int T){
    for(int i=1;i<=n;i++)hd[i]=0;
    ec=1;
    for(int i=1;i<=m;i++){
        Add(U[i],V[i],W[i]);
    }
    s=S,t=T;
    int flow=0;
    while(bfs()){
        for(int i=1;i<=n;i++)h[i]=hd[i];
        flow+=dfs(s,INF);
    }
    return flow;
}

inline int lowbit(int x){
    return x&(-x);
}

signed main(){
    n=read(),m=read();
    for(int i=1;i<=m;i++){
        U[i]=read(),V[i]=read(),W[i]=read();
    }
    if(n>18){
        int ans=0;
        for(int i=1;i<n;i++)ans+=dinic(i,i+1);
        _write(ans);
        for(int i=1;i<=n;i++)write_(i);
        pc(10);
        return 0;
    }
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++)if(i!=j){
            dis[i][j]=dinic(i,j);
        }
    }
    for(int i=0;i<(1<<n);i++){
        for(int j=0;j<n;j++)if(i&(1<<j)){
            for(int k=0;k<n;k++)if(!(i&(1<<k))){
                _max(f[i|(1<<k)][k],f[i][j]+dis[j+1][k+1]);
            }
        }
    }
    int ans=0,ed=0,S=(1<<n)-1;
    for(int i=0;i<n;i++){
        if(f[S][i]>=ans)ans=f[S][i],ed=i;
    }
    _write(ans);
    for(int i=1;i<(1<<n);i++)popc[i]=popc[i^lowbit(i)]+1;
    while(S){
        write_(ed+1);
        int pred=0,i=S^(1<<ed);
        for(int j=0;j<n;j++)if(i&(1<<j)){
            if(f[i][j]+dis[j+1][ed+1]==f[S][ed]){
                pred=j;
                break;
            }
        }
        ed=pred,S=i;
    }
    pc(10);
    return 0;
}
