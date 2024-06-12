// Author:Zimse  Data:2023-07-
#include <bits/stdc++.h>
#define pc putchar
#define pb push_back
#define inv fpow
// #define int long long
namespace OI{const int INF=1.001e9,Mod=998244353;int read(){int x=0
,y=1;char c=getchar();while(c<48||57<c){if(c==45)y=-1;c=getchar();}
while(47<c&&c<58)x=x*10+c-48,c=getchar();return x*y;}void wr(int x)
{if(x<0)pc(45),x=-x;if(x>=10)wr(x/10);pc(48+x%10);}void wri(int x){
wr(x),pc(32);}void _wri(int x){wr(x),pc(10);}void iF(const char*x){
freopen(x,"r",stdin);}void oF(const char*x){freopen(x,"w",stdout);}
inline int fpow(long long x,int y=Mod-2){int z=1;while(y){if(y&1)z=
x*z%Mod;x=x*x%Mod,y/=2;}return z;}inline void _max(int&x,int y){if(
x<y)x=y;}inline void _min(int&x,int y){if(y<x)x=y;}inline void _mod
(int&x,int y){(x+=y)%=Mod;}}using namespace OI;using namespace std;

const int N=1.01e6,M=512,dx[4]={1,-1,0,0},dy[4]={0,0,1,-1};
int n,ans,dis[N],vis[N];
char mp[M][M];

struct edge{
    int to,w;
    edge(int to=0,int w=0):to(to),w(w){}
};
vector<edge> g[N];
struct node{
    int x,y;
    node(int x=0,int y=0):x(x),y(y){}
    bool operator < (const node& _)const{return y>_.y;}
};
priority_queue<node> Q;

int id(int x,int y){
    return (x-1)*n+y;
}

int Dij(int S,int T){
    for(int i=1;i<=n*n;i++)vis[i]=0,dis[i]=INF;
    while(!Q.empty())Q.pop();
    dis[S]=0,Q.push(node(S,0));
    while(!Q.empty()){
        int u=Q.top().x;
        Q.pop();
        if(vis[u]++)continue;
        for(unsigned i=0;i<g[u].size();i++){
            int v=g[u][i].to,w=g[u][i].w;
            if(dis[u]+w<dis[v])dis[v]=dis[u]+w,Q.push(node(v,dis[v]));
        }
    }
    return dis[T];
}

signed main(){
    n=read();
    for(int i=1;i<=n;i++)scanf("%s",mp[i]+1);
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            for(int w=0;w<4;w++){
                int x=i+dx[w],y=j+dy[w];
                if(x<1||x>n||y<1||y>n)continue;
                g[id(i,j)].push_back(edge(id(x,y),mp[x][y]=='B'?1:0));
            }
        }
    }
    ans+=Dij(id(1,1),id(n,n));
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            g[id(i,j)].resize(0);
            for(int w=0;w<4;w++){
                int x=i+dx[w],y=j+dy[w];
                if(x<1||x>n||y<1||y>n)continue;
                g[id(i,j)].push_back(edge(id(x,y),mp[x][y]=='R'?1:0));
            }
        }
    }
    ans+=Dij(id(1,n),id(n,1));
    _wri(ans);
    return 0;
}



