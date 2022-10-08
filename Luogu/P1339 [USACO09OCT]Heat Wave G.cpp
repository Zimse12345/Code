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
int n,m;
struct edge{
	int to,w;
	edge(int to=0,int w=0):to(to),w(w){}
};
vector<edge> g[N];
struct node{
	int id,d;
	node(int id=0,int d=0):id(id),d(d){}
	bool operator < (const node& A)const{return d>A.d;}
};
priority_queue<node> Q;
int vis[N],dis[N];

void Dijkstra(int s){
	for(int i=1;i<=n;i++)vis[i]=0,dis[i]=INF;
	dis[s]=0,Q.push(node(s,0));
	while(!Q.empty()){
		int u=Q.top().id;
		Q.pop();
		if(vis[u]++)continue;
		for(int i=0;i<int(g[u].size());i++){
			int v=g[u][i].to,w=g[u][i].w;
			if(dis[u]+w<dis[v]){
				dis[v]=dis[u]+w;
				Q.push(node(v,dis[v]));
			}
		}
	}
	return;
}

int main(){
	n=read(),m=read();
	int s=read(),t=read();
	for(int i=1,u,v,w;i<=m;i++){
		u=read(),v=read(),w=read();
		g[u].push_back(edge(v,w));
		g[v].push_back(edge(u,w));
	}
	Dijkstra(s);
	printf("%d\n",dis[t]);
	return 0;
}
