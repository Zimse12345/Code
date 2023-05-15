// Author: Zimse
// Data: 2023-05-

#include <bits/stdc++.h>
#define gc getchar
#define pc putchar
#define pb push_back
#define inv fpow
//#define int long long
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
}using namespace Zimse;using namespace std;

const int N=1.01e4;
int n,m,ec,hd[N],nxt[N],h[N],d[N],s,t,ans[N],Flow;
struct edge{int u,v,val;edge(int u=0,int v=0,int val=0):u(u),v(v),val(val){}}E[N];
inline void add(int u,int v,int val){nxt[++ec]=hd[u],hd[u]=ec,E[ec]=edge(u,v,val);return;}
inline void Add(int u,int v,int val){add(u,v,val),add(v,u,0);return;}

queue<int> Q;
bool BFS(){
    for(int i=1;i<=n;i++)d[i]=0;
    d[s]=1,Q.push(s);
    while(!Q.empty()){
        int u=Q.front();Q.pop();
        for(int i=hd[u];i;i=nxt[i]){
            if(!d[E[i].v]&&E[i].val>0)d[E[i].v]=d[u]+1,Q.push(E[i].v);
        }
    }
    return d[t]>0;
}

int DFS(int u,int maxf){
    if(u==t||!maxf)return maxf;
    int flow=0;
    for(int i=h[u];i;i=nxt[i]){
        if(d[E[i].v]==d[u]+1&&E[i].val){
            int f=DFS(E[i].v,min(maxf,E[i].val));
            E[i].val-=f,E[i^1].val+=f,maxf-=f,flow+=f;
            if(!maxf)break;
        }
        h[u]=nxt[h[u]];
    }
    if(!flow)d[u]=0;
    return flow;
}

void Dinic(){
    while(BFS()){
        for(int i=1;i<=n;i++)h[i]=hd[i];
        Flow+=DFS(s,INF);
    }
    return;
}

void Init(){
    for(int i=1;i<=ec;i++)E[i]=E[0],nxt[i]=0;
    for(int i=1;i<=n;i++)hd[i]=0;
    ec=1,Flow=0;
    return;
}

int _n,k,U[N],V[N];

signed main(){
    // ifile("c.in");
    // ofile("c.out");

    _n=read(),m=read(),k=read();
    n=2*_n-k,s=++n,t=++n;
    for(int i=1;i<=m;i++)U[i]=read(),V[i]=read();
    for(int l=k+1;l<=_n;l++){
        Init();
        for(int i=1;i<=k;i++)Add(s,i,1);
        for(int i=k+1;i<=_n;i++)Add(i,i+_n-k,1);
        for(int i=1;i<=m;i++){
            if(U[i]<=k)Add(U[i],V[i],1);
            else Add(U[i]+_n-k,V[i],1);
        }
        for(int r=l;r<=_n;r++){
            Add(r+_n-k,t,1);
            Dinic();
            ++ans[Flow];
        }
    }
    for(int i=0;i<=k;i++)_write(ans[i]);
    return 0;
}

