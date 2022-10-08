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
int n,m,k,vis[N],dis[N],ans=INF;
struct edge{
	int to,w;
	edge(int to=0,int w=0):to(to),w(w){}
};
struct node{
	int id,d;
	node(int id=0,int d=0):id(id),d(d){}
	bool operator < (const node& A)const{return d>A.d;}
};
vector<edge> g[N];
priority_queue<node> Q;
inline void add(int u,int v,int w){g[u].push_back(edge(v,w));return;}

int main(){
	n=read(),m=read(),k=read();
	for(int i=1,u,v,w;i<=m;i++){
		u=read(),v=read(),w=read();
		for(int j=0;j<=k;j++){
			add(u+j*n,v+j*n,w),add(v+j*n,u+j*n,w);
			if(j!=k)add(u+j*n,v+(j+1)*n,w/2),add(v+j*n,u+(j+1)*n,w/2);
		}
	}
	n*=(k+1);
	for(int i=2;i<=n;i++)dis[i]=INF;
	Q.push(node(1,0));
	while(!Q.empty()){
		int u=Q.top().id;
		Q.pop();
		if(vis[u]++)continue;
		for(int i=0,v,w;i<int(g[u].size());i++){
			v=g[u][i].to,w=g[u][i].w;
			if(dis[u]+w<dis[v]){
				dis[v]=dis[u]+w;
				Q.push(node(v,dis[v]));
			}
		}
	}
	n/=(k+1);
	for(int i=0;i<=k;i++)ans=min(ans,dis[n+i*n]);
	printf("%d\n",ans);
	return 0;
}
