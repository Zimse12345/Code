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

const int N=3e5+7,Mod=998244353,INF=1e16+7;
int n,m,k,vis[N],dis[N],ans[N],t;
struct edge{
	int to,w,id;
	edge(int to=0,int w=0,int id=0):to(to),w(w),id(id){}
};
struct node{
	int id,d;
	node(int id=0,int d=0):id(id),d(d){};
	bool operator < (const node& A)const{return d>A.d;}
};
vector<edge> g[N];
priority_queue<node> Q;
queue<int> q; 

signed main(){
	n=read(),m=read(),k=read();
	for(int i=1,u,v,w;i<=m;i++){
		u=read(),v=read(),w=read();
		g[u].push_back(edge(v,w,i));
		g[v].push_back(edge(u,w,i));
	}
	for(int i=1;i<=n;i++)dis[i]=INF;
	dis[1]=0,Q.push(node(1,0));
	while(!Q.empty()){
		int u=Q.top().id;
		Q.pop();
		if(vis[u]++)continue;
		for(int i=0;i<g[u].size();i++){
			int v=g[u][i].to,w=g[u][i].w;
			if(dis[u]+w<dis[v]){
				dis[v]=dis[u]+w;
				Q.push(node(v,dis[v]));
			}
		}
	}
	for(int i=1;i<=n;i++)vis[i]=0;
	q.push(1),vis[1]=1;
	while(!q.empty()){
		if(k<=0)break;
		int u=q.front();
		q.pop();
		for(int i=0;i<g[u].size();i++){
			int v=g[u][i].to,w=g[u][i].w;
			if(dis[u]+w==dis[v]&&k>0&&!vis[v]){
				ans[++t]=g[u][i].id,--k;
				q.push(v),vis[v]=1;
			}
		}
	}
	printf("%d\n",t);
	for(int i=1;i<=t;i++)printf("%d ",ans[i]);
	printf("\n");
	return 0;
}
