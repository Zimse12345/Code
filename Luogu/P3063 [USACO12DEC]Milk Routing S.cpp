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

const int N=1e3+7,Mod=998244353,INF=1e9+7;
int n,m,ban[N],X,vis[N],dis[N],ans=INF;
struct edge{
	int to,t,c,id;
	edge(int to=0,int t=0,int c=0,int id=0):to(to),t(t),c(c),id(id){}
};
struct eg{
	int c,id;
	eg(int c=0,int id=0):c(c),id(id){};
	bool operator < (const eg& A)const{return c<A.c;}
}e[N];
struct node{
	int id,d;
	node(int id=0,int d=0):id(id),d(d){}
	bool operator < (const node& A)const{return d>A.d;}
};
vector<edge> g[N];
priority_queue<node> Q;

void Dijkstra(int s){
	for(int i=1;i<=n;i++)vis[i]=0,dis[i]=INF;
	dis[s]=0,Q.push(node(s,0));
	while(!Q.empty()){
		int u=Q.top().id;
		Q.pop();
		if(vis[u]++)continue;
		for(int i=0;i<int(g[u].size());i++){
			if(ban[g[u][i].id])continue;
			int v=g[u][i].to,w=g[u][i].t;
			if(dis[u]+w<dis[v]){
				dis[v]=dis[u]+w;
				Q.push(node(v,dis[v]));
			}
		}
	}
	return;
}

int main(){
	n=read(),m=read(),X=read();
	for(int i=1,u,v,w,c;i<=m;i++){
		u=read(),v=read(),w=read(),c=read();
		g[u].push_back(edge(v,w,c,i));
		g[v].push_back(edge(u,w,c,i));
		e[i]=eg(c,i);
	}
	sort(e+1,e+m+1);
	e[m+1].c=INF;
	for(int i=0;i<=m;i++){
		ban[e[i].id]=1;
		Dijkstra(1);
		ans=min(ans,dis[n]+X/e[i+1].c);
	}
	printf("%d\n",ans);
	return 0;
}
