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

#define int long long
#define ull unsigned long long

using namespace std;

int read(){int qrx=0,qry=1;char qrc=getchar();
while(qrc<'0'||qrc>'9'){if(qrc=='-'){qry=-1,qrc=getchar();}else qrc=getchar();}
while(qrc>='0'&&qrc<='9')qrx=qrx*10+qrc-48,qrc=getchar();return qrx*qry;}

const int N=2e5+7,Mod=998244353,INF=1e15+7;
int n,m,k,q,hd[N],nxt[N*4],to[N*4],c[N*4],ec;
int dis[N],vis[N],fr[N],sz[N],cnt,p[N];
int Hd[N*2],Nxt[N*4],To[N*4],Ec,rt,dep[N*2];
int fa[20][N*2],fw[20][N*2];

struct node{int x,y;node(int x=0,int y=0):x(x),y(y){}
bool operator < (const node& A)const{return x>A.x;}};
struct edge{int u,v,w;edge(int u=0,int v=0,int w=0):u(u),v(v),w(w){}
bool operator < (const edge& A)const{return w<A.w;}}e[N*2];

inline void add(int u,int v,int w){nxt[++ec]=hd[u],hd[u]=ec,to[ec]=v,c[ec]=w;return;}
inline void Add(int u,int v){Nxt[++Ec]=Hd[u],Hd[u]=Ec,To[Ec]=v;return;}
inline int F(int x){if(fr[x]!=x)fr[x]=F(fr[x]);return fr[x];}

priority_queue<node> Q;
void Dijkstra(){
	for(int i=0;i<=n;i++)dis[i]=INF;
	dis[0]=0,Q.push(node(0,0));
	while(!Q.empty()){
		int u=Q.top().y;
		Q.pop();
		if(vis[u]++)continue;
		for(int i=hd[u],v;i;i=nxt[i]){
			v=to[i];
			if(dis[u]+c[i]<dis[v]){
				dis[v]=dis[u]+c[i];
				Q.push(node(dis[v],v));
			}
		}
	}
	return;
}

void Kruskal(){
	sort(e+1,e+m+1),cnt=n;
	for(int i=1;i<=n;i++)fr[i]=p[i]=i,sz[i]=1;
	for(int i=1,u,v,A,B;i<=m;i++){
		u=e[i].u,v=e[i].v,A=F(u),B=F(v);
		if(A!=B){
			if(sz[A]<sz[B])swap(A,B);
			fr[B]=A,sz[A]+=sz[B],++cnt;
			Add(cnt,p[A]),Add(cnt,p[B]);
			fa[0][p[A]]=fa[0][p[B]]=cnt,fw[0][p[A]]=fw[0][p[B]]=e[i].w;
			p[A]=cnt;
		}
	}
	return;
}

void dfs(int u,int from){
	dep[u]=dep[from]+1;
	for(int i=Hd[u],v;i;i=Nxt[i]){
		v=To[i];
		if(v==from)continue;
		dfs(v,u);
	}
	return;
}

signed main(){
	n=read(),m=read(),k=read(),q=read();
	for(int i=1,u,v,w;i<=m;i++)u=read(),v=read(),w=read(),add(u,v,w),add(v,u,w),e[i]=edge(u,v,w);
	for(int i=1;i<=k;i++)add(0,i,0);
	Dijkstra();
	for(int i=1;i<=m;i++)e[i].w=dis[e[i].u]+dis[e[i].v]+e[i].w;
	Kruskal();
	rt=p[F(1)];
	dfs(rt,0);
	for(int i=1;i<=19;i++)for(int j=1;j<=cnt;j++){
		fa[i][j]=fa[i-1][fa[i-1][j]];
		fw[i][j]=max(fw[i-1][j],fw[i-1][fa[i-1][j]]);
	}
	for(int i=1,a,b,ans;i<=q;i++){
		a=read(),b=read(),ans=0;
		if(dep[a]<dep[b])swap(a,b);
		for(int j=19;j>=0;j--)if(dep[fa[j][a]]>=dep[b])ans=max(ans,fw[j][a]),a=fa[j][a];
		for(int j=19;j>=0;j--)if(fa[j][a]!=fa[j][b]){
			ans=max(ans,max(fw[j][a],fw[j][b]));
			a=fa[j][a],b=fa[j][b];
		}
		if(a!=b)ans=max(ans,max(fw[0][a],fw[0][b]));
		printf("%lld\n",ans);
	}
	return 0;
}

