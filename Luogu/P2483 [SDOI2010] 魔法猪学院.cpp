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

#define ll long long
#define ull unsigned long long

using namespace std;

inline int read(){int qrx=0,qry=1;char qrc=getchar();
while(qrc<'0'||qrc>'9'){if(qrc=='-'){qry=-1,qrc=getchar();}else qrc=getchar();}
while(qrc>='0'&&qrc<='9')qrx=qrx*10+qrc-48,qrc=getchar();return qrx*qry;}

const int N=2e5+7,Mod=998244353;
const double INF=1e12;
int n,m,vis[N],nextT[N],U[N],V[N],ans,tot,rt[N];
double dis[N],W[N];
struct treenode{
	int ls,rs,dep,y;double t;
	treenode(int ls=0,int rs=0,int dep=0,int y=0,double t=0):ls(ls),rs(rs),dep(dep),y(y),t(t){}
}tr[N*15];
struct edge{
	int to,id;double w;
	edge(int to=0,int id=0,double w=0):to(to),id(id),w(w){}
};
struct node{
	int x;double y;
	node(int x=0,double y=0):x(x),y(y){}
	bool operator < (const node& A)const{return y<A.y;}
};
struct sta{
	int t;double d;
	sta(int t=0,double d=0):t(t),d(d){}
	bool operator < (const sta& A)const{return d>A.d;}
};
vector<edge> G[N];
vector<int> T[N];
priority_queue<node> Q;
priority_queue<sta> S;
double E;

int merge(int x,int y){
	if(!x||!y)return x^y;
	if(tr[x].t>tr[y].t)swap(x,y);
	int p=++tot;tr[p]=tr[x];
	tr[p].rs=merge(tr[p].rs,y);
	if(tr[tr[p].rs].dep>tr[tr[p].ls].dep)swap(tr[p].ls,tr[p].rs);
	tr[p].dep=tr[tr[p].rs].dep+1;
	return p;
}

void Dijkstar(){
	for(int i=1;i<=n;i++)dis[i]=INF;
	dis[n]=0,Q.push(node(n,0));
	while(!Q.empty()){
		int u=Q.top().x;Q.pop();
		if(vis[u]++)continue;
		for(int i=0,v;i<signed(G[u].size());i++){
			v=G[u][i].to;
			if(dis[u]+G[u][i].w<dis[v]){
				dis[v]=dis[u]+G[u][i].w,nextT[v]=G[u][i].id;
				Q.push(node(v,-dis[v]));
			}
		}
	}
	return;
}

void dfs(int u,int from){
	for(int i=0;i<signed(G[u].size());i++)if(nextT[u]!=G[u][i].id){
		tr[++tot]=treenode(0,0,1,G[u][i].to,G[u][i].w);
		rt[u]=merge(rt[u],tot);
	}
	rt[u]=merge(rt[u],rt[from]);
	for(int i=0;i<signed(T[u].size());i++){
//		rt[T[u][i]]=++tot;
//		tr[tot]=tr[rt[u]];
//		rt[T[u][i]]=rt[u];
		dfs(T[u][i],u);
	}
	return;
}

signed main(){
//	freopen("d.in","r",stdin);
//	freopen("m.out","w",stdout);
	n=read(),m=read();
	scanf("%lf",&E);
	for(int i=1,u,v;i<=m;i++){
		u=read(),v=read(),scanf("%lf",&W[i]);
		U[i]=u,V[i]=v;
		if(U[i]==n)W[i]=INF;
		G[v].push_back(edge(u,i,W[i]));
	}
	Dijkstar();
	for(int i=1;i<n;i++)T[V[nextT[i]]].push_back(i);//printf("(%d %d)\n",i,V[nextT[i]]);
	for(int i=1;i<=n;i++)G[i].clear();
	for(int i=1,u,v;i<=m;i++){
		u=U[i],v=V[i];
//		if(nextT[u]==v)continue;
		G[u].push_back(edge(v,i,W[i]+dis[v]-dis[u]));
	}
	dfs(n,0);
	if(dis[1]>E){
		printf("0\n");
		return 0;
	}
	E-=dis[1],++ans;
	S.push(sta(rt[1],dis[1]+tr[rt[1]].t));
	while(!S.empty()){
		sta s=S.top();S.pop();
		if(s.d>E)break;
		E-=s.d,++ans;
		if(s.t){
			if(tr[s.t].ls)S.push(sta(tr[s.t].ls,s.d-tr[s.t].t+tr[tr[s.t].ls].t));
			if(tr[s.t].rs)S.push(sta(tr[s.t].rs,s.d-tr[s.t].t+tr[tr[s.t].rs].t));
		}
		if(rt[tr[s.t].y])S.push(sta(rt[tr[s.t].y],s.d+tr[rt[tr[s.t].y]].t));
	}
	printf("%d\n",ans);
	return 0;
}

