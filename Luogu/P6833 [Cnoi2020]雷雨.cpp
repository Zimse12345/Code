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

const int N=1e6+7;
const ll INF=1e15+7;
int n,m,a,b,c,p,k,vis[N],tot;
int hd[N<<2],nxt[N<<2],to[N<<2],cnt;
ll d[N<<2],ans=INF,dis[N][3],v[1100][1100];

struct node{
	int id;
	ll d;
	node(int id=0,ll d=0):id(id),d(d){}
	bool operator <(const node& A)const{return d>A.d;}
	
};
priority_queue<node> Q;

void add(int u,int v,ll w){
	to[++cnt]=v,d[cnt]=w;
	nxt[cnt]=hd[u],hd[u]=cnt;
	return;
}

void Dijkstra(int s,int o){
	for(int i=0;i<=tot;i++)dis[i][o]=INF,vis[i]=0;
	dis[s][o]=0;
	Q.push(node(s,0));
	while(!Q.empty()){
		int u=Q.top().id;Q.pop();
		if(vis[u]++)continue;
		for(int i=hd[u];i;i=nxt[i]){
			int v=to[i];
			ll w=d[i];
			if(dis[u][o]+w<dis[v][o]){
				dis[v][o]=dis[u][o]+w;
				Q.push(node(v,dis[v][o]));
			}
		}
	}
	return;
}

int id(int x,int y){
	return (x-1)*m+y;
}

signed main(){
	n=read(),m=read(),a=read(),b=read(),c=read();
	for(int i=1;i<=n;i++)for(int j=1;j<=m;j++)v[i][j]=read();
	for(int i=1;i<=n;i++)for(int j=1;j<=m;j++){
		if(i!=1)add(id(i,j),id(i-1,j),v[i-1][j]);
		if(i!=n)add(id(i,j),id(i+1,j),v[i+1][j]);
		if(j!=1)add(id(i,j),id(i,j-1),v[i][j-1]);
		if(j!=n)add(id(i,j),id(i,j+1),v[i][j+1]);
	}
	tot=id(n,m);
	add(0,id(1,a),v[1][a]);
	Dijkstra(0,0);
	Dijkstra(id(n,b),1),Dijkstra(id(n,c),2);
	if(b==c){
		printf("%lld\n",dis[id(n,b)][0]);
		return 0;
	}
	for(int i=1;i<=n;i++)for(int j=1;j<=m;j++){
		ll res=dis[id(i,j)][0]+dis[id(i,j)][1]+dis[id(i,j)][2]-v[i][j]*2+v[n][b]+v[n][c];
		ans=min(ans,res);
	}
	printf("%lld\n",ans);
	return 0;
}
