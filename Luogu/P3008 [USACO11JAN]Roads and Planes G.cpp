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

int read(){int qrx=0,qry=1;char qrc=getchar();
while(qrc<'0'||qrc>'9'){if(qrc=='-'){qry=-1,qrc=getchar();}else qrc=getchar();}
while(qrc>='0'&&qrc<='9')qrx=qrx*10+qrc-48,qrc=getchar();return qrx*qry;}

const int N=1e5+7,Mod=998244353,INF=1e9+7;
struct edge{
	int to,w;
	edge(int to=0,int w=0):to(to),w(w){}
};
struct node{
	int id,d;
	node(int id=0,int d=0):id(id),d(d){}
	bool operator < (const node& A)const{return d>A.d;}
};
int n,m1,m2,k,s,dis[N],vis[N],cl[N],pr[N];
vector<edge> g1[N],g2[N];
vector<int> col[N];
queue<int> Q1;
priority_queue<node> Q2;

void dfs(int u,int c){
	cl[u]=c,vis[u]=1,col[c].push_back(u);
	for(int i=0,v;i<int(g1[u].size());i++){
		v=g1[u][i].to;
		if(!vis[v])dfs(v,c);
	}
	return;
}

void Dijkstra(int st){
	while(!Q2.empty())Q2.pop();
	for(int i=0;i<int(col[st].size());i++)Q2.push(node(col[st][i],dis[col[st][i]]));
	while(!Q2.empty()){
		int u=Q2.top().id;
		Q2.pop();
		if(vis[u]++)continue;
		for(int i=0,v,w;i<int(g1[u].size());i++){
			v=g1[u][i].to,w=g1[u][i].w;
			if(dis[u]+w<dis[v]){
				dis[v]=dis[u]+w;
				Q2.push(node(v,dis[v]));
			}
		}
	}
}

int main(){
	n=read(),m1=read(),m2=read(),s=read();
	for(int i=1,u,v,w;i<=m1;i++){
		u=read(),v=read(),w=read();
		g1[u].push_back(edge(v,w)),g1[v].push_back(edge(u,w));
	}
	for(int i=1;i<=n;i++)if(!vis[i])dfs(i,++k);
	for(int i=1;i<=n;i++)vis[i]=0;
	for(int i=1,u,v,w;i<=m2;i++){
		u=read(),v=read(),w=read();
		++pr[cl[v]],g2[u].push_back(edge(v,w));
	}
	for(int i=1;i<=n;i++)dis[i]=INF;
	dis[s]=0;
	for(int i=1;i<=k;i++)if(!pr[i])Q1.push(i);
	while(!Q1.empty()){
		int u=Q1.front();
		Q1.pop();
		Dijkstra(u);
		for(int i=0,U;i<int(col[u].size());i++){
			U=col[u][i];
			for(int j=0,V;j<int(g2[U].size());j++){
				V=g2[U][j].to;
				dis[V]=min(dis[V],dis[U]+g2[U][j].w);
				--pr[cl[V]];
				if(pr[cl[V]]<=0)Q1.push(cl[V]);
			}
		}
	}
	for(int i=1;i<=n;i++){
		if(dis[i]>=INF/2)printf("NO PATH\n");
		else printf("%d\n",dis[i]);
	}
	return 0;
}
