// Author:Zimse  Data:2023-06-
#include <bits/stdc++.h>
#define pc putchar
#define pb push_back
#define inv fpow
#define int long long
#define M ((L+R)/2)
#define Lid ch[id][0]
#define Rid ch[id][1]
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

const int N=1.01e5;
int n,m,S,T;
int dis[N],vis[N],pr[N],ans[N],len,rt_inf;
int ch[N*64][2],hs[N*64],p2[N],tot,_x;

struct edge{
    int to,x;
    edge(int to=0,int x=0):to(to),x(x){}
};
vector<edge> g[N];

inline void add(int _id,int &id,int L,int R,int &x){
    id=++tot;
    if(L==R){
        if(hs[_id])++x;
        else hs[id]=1;
    }
    else{
        if(x<=M)add(ch[_id][0],Lid,L,M,x);
        if(x>M)add(ch[_id][1],Rid,M+1,R,x);
        if(!Lid)Lid=ch[_id][0];
        if(!Rid)Rid=ch[_id][1];
        hs[id]=(hs[Lid]+hs[Rid]*p2[M-L+1])%Mod;
    }
    return;
}

inline int Cmp(int id0,int id1){
    if(!hs[id0]&&hs[id1])return 1;
    if(hs[id0]&&!hs[id1])return 0;
    if(hs[id0]==hs[id1])return 2;
    int l=Cmp(ch[id0][1],ch[id1][1]);
    return l<2?l:Cmp(ch[id0][0],ch[id1][0]);
}

struct node{
    int u,i;
    node(int u=0,int i=0):u(u),i(i){}
    bool operator < (const node &_)const{return Cmp(i,_.i)==0;}
};
priority_queue<node> Q;

signed main(){
    p2[0]=1;
    for(int i=1;i<N;i++)p2[i]=p2[i-1]*2%Mod;
    n=read(),m=read();
    for(int i=1,u,v,x;i<=m;i++){
        u=read(),v=read(),x=read();
        g[u].pb(edge(v,x));
        g[v].pb(edge(u,x));
    }
    S=read(),T=read();
    _x=N-1,add(0,rt_inf,0,N-1,_x);
    for(int i=1;i<=n;i++)dis[i]=rt_inf;
    dis[S]=0;
    Q.push(node(S,0));
    while(!Q.empty()){
        int u=Q.top().u;
        Q.pop();
        if(u==T)break;
        if(vis[u]++)continue;
        for(unsigned i=0;i<g[u].size();i++){
            int v=g[u][i].to;
            int _d=0;
            _x=g[u][i].x,add(dis[u],_d,0,N-1,_x);
            if(Cmp(_d,dis[v])==1){
                dis[v]=_d;
                Q.push(node(v,_d)),pr[v]=u;
            }
        }
    }
    if(dis[T]==rt_inf){
        _wri(-1);
        return 0;
    }
    _wri(hs[dis[T]]);
    while(T!=S)ans[++len]=T,T=pr[T];
    ans[++len]=S;
    _wri(len);
    for(int i=len;i>=1;i--)wri(ans[i]);
    pc(10);
    return 0;
}

