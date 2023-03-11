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

const int N=256;

int n,K,a[N][N],sum;
bool bf[11][1100][110];

int _n,_s,_t,ans,hd[N],h[N],nxt[N*N],ec=1,d[N],Id[N][N];
struct edge{
    int v,f;
    edge(int v=0,int f=0):v(v),f(f){}
}E[N*N];
vector<edge> g[N];
inline void add(int u,int v,int f){nxt[++ec]=hd[u],hd[u]=ec,E[ec]=edge(v,f);return;}
inline void Add(int u,int v,int f){add(u,v,f),add(v,u,0);return;}

queue<int> Q;
bool bfs(){
    for(int i=1;i<=_n;i++)d[i]=0;
    d[_s]=1,Q.push(_s);
    while(!Q.empty()){
        int u=Q.front();
        Q.pop();
        for(int i=hd[u];i;i=nxt[i])if(E[i].f&&!d[E[i].v])d[E[i].v]=d[u]+1,Q.push(E[i].v);
    }
    return d[_t];
}

int dfs(int u,int maxf){
    if(u==_t||!maxf)return maxf;
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
        for(int i=1;i<=_n;i++)h[i]=hd[i];
        ans+=dfs(_s,INF);
    }
    return;
}

void BF(){
    bf[0][0][0]=true;
    for(int i=1;i<=n;i++){
        for(int j=0;j<(1<<n);j++){
            for(int k=0;k<K;k++)if(bf[i-1][j][k]){
                for(int t=0;t<n;t++)if(a[i][t+1]!=-1&&(!(j&(1<<t)))){
                    bf[i][j|(1<<t)][(k+a[i][t+1])%K]=1;
                }
            }
        }
    }
    _ck(bf[n][(1<<n)-1][0]);
    return;
}

int dis[N],vis[N],ring[N],F[N][N],ins[N];
void dfs2(int u,int d){
    vis[u]=1,ins[u]=1,dis[u]=d;
    for(unsigned i=0;i<g[u].size();i++){
        int v=g[u][i].v;
        if(ins[v]){
            ring[(dis[u]-dis[v]+g[u][i].f+K)%K]=1;
        }
        else if(!vis[v])dfs2(v,(d+g[u][i].f)%K);
    }
    ins[u]=0;
    return;
}

signed main(){
//	ifile("t.in");
//	ofile("t.out");
	
    n=read(),K=read();
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++)a[i][j]=read();
    }
    if(n<=10){
        BF();
        return 0;
    }
    _n=n*2,_s=++_n,_t=++_n;
    for(int i=1;i<=n;i++)Add(_s,i,1),Add(n+i,_t,1);
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++)if(a[i][j]!=-1)Add(i,j+n,1),Id[i][j]=ec-1;
    }
    dinic();
    if(ans!=n){
        no;
        return 0;
    }
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++)if(Id[i][j]){
            if(E[Id[i][j]].f==0){
                (sum+=a[i][j])%=K;
                g[i].pb(edge(j+n,(K-a[i][j])%K));
            }
            else g[j+n].pb(edge(i,a[i][j]));
        }
    }
    sum=(K-sum)%K;
    if(!sum){
        yes;
        return 0;
    }
    for(int i=1;i<=n*2;i++){
    	for(int j=1;j<=n*2;j++)vis[j]=dis[j]=ins[j]=0;
    	dfs2(i,0);
	}
    int t=0;
    F[0][0]=1;
    for(int i=0;i<K;i++)if(ring[i]){
        ++t;
        for(int j=0;j<K;j++)if(F[t-1][j])F[t][j]=F[t][(j+i)%K]=1;
    }
    _ck(F[t][sum]);
    return 0;
}
