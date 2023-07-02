// Author:Zimse  Data:2023-06-
#include <bits/stdc++.h>
#define pc putchar
#define pb push_back
#define inv fpow
#define int long long
//#define M ((L+R)/2)
namespace OI{const int INF=1.01e18,Mod=998244353;int read(){int x=0
,y=1;char c=getchar();while(c<48||57<c){if(c==45)y=-1;c=getchar();}
while(47<c&&c<58)x=x*10+c-48,c=getchar();return x*y;}void wr(int x)
{if(x<0)pc(45),x=-x;if(x>=10)wr(x/10);pc(48+x%10);}void wri(int x){
wr(x),pc(32);}void _wri(int x){wr(x),pc(10);}void iF(const char*x){
freopen(x,"r",stdin);}void oF(const char*x){freopen(x,"w",stdout);}
inline int fpow(long long x,int y=Mod-2){int z=1;while(y){if(y&1)z=
x*z%Mod;x=x*x%Mod,y/=2;}return z;}inline void _max(int&x,int y){if(
x<y)x=y;}inline void _min(int&x,int y){if(y<x)x=y;}inline void _mod
(int&x,int y){(x+=y)%=Mod;}}using namespace OI;using namespace std;

const int N=2.01e5;
int n,m,dis[N][2],vis[N],x[N],y[N],z[N],ans[200][200],tim[200],len;
struct edge{
	int to,w;
	edge(int to=0,int w=0):to(to),w(w){}
};
struct node{
	int x,d;
	node(int x=0,int d=0):x(x),d(d){}
	bool operator <(const node& A)const{return d>A.d;}
};
vector<edge> g[N];
priority_queue<node> Q;

void Dijkstra(int s,int id){
	for(int i=1;i<=n;i++)dis[i][id]=INF,vis[i]=0;
	while(!Q.empty())Q.pop();
	dis[s][id]=0,Q.push(node(s,0));
	while(!Q.empty()){
		int u=Q.top().x;Q.pop();
		if(vis[u]++)continue;
		for(unsigned i=0;i<g[u].size();i++){
			int v=g[u][i].to,w=g[u][i].w;
			if(dis[v][id]>dis[u][id]+w){
				dis[v][id]=dis[u][id]+w;
				Q.push(node(v,dis[v][id]));
			}
		}
	}
	return;
}

signed main(){
	n=read(),m=read();
    int S=n; 
	for(int i=1,u,v,w;i<=m;i++){
		u=read(),v=read(),w=read();
		g[u].push_back(edge(v,w));
		g[v].push_back(edge(u,w));
		x[i]=u,y[i]=v,z[i]=w;
	}
	for(int i=2;i<=n;i++)g[1].push_back(edge(i,0));
	Dijkstra(S,0);
	if(dis[1][0]==INF){
	    printf("inf\n");
	    return 0;
    }
    while(1){
        int mx=0;
        for(int i=1;i<=n;i++){
            if(dis[i][0]<INF)mx=max(mx,dis[i][0]);
        }
        if(!mx)break;
        ++len;
        for(int i=1;i<=n;i++){
            if(dis[i][0]>=mx)ans[len][i]=1,dis[i][0]=INF;
        }
        tim[len]=mx;
    }
	printf("%lld %lld\n",tim[1],len);
	for(int i=1;i<=len;i++){
        for(int j=1;j<=n;j++)printf("%lld",ans[i][j]);
        printf(" %lld\n",tim[i]-tim[i+1]);
    }
	return 0;
}

