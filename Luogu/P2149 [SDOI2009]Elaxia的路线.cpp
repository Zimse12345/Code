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

const int N=1600,M=2e6+7,Mod=998244353,INF=1e9+7;
int n,m,s1,t1,s2,t2,ans;
int vis[N],dis[N][2];
int to[M],c[M],nxt[M],hd[N],ec;
int k[N][N][2],f[N];
struct node{
	int id,d;
	node(int id=0,int d=0):id(id),d(d){}
	bool operator < (const node& A)const{return d>A.d;}
};
priority_queue<node> Q;

void add(int u,int v,int w){
	to[++ec]=v,c[ec]=w;
	nxt[ec]=hd[u],hd[u]=ec;
	return;
}

void Dijkstra(int s,int p){
	for(int i=1;i<=n;i++)vis[i]=0,dis[i][p]=INF;
	while(!Q.empty())Q.pop();
	dis[s][p]=0,Q.push(node(s,0));
	while(!Q.empty()){
		int u=Q.top().id;Q.pop();
		if(vis[u]++)continue;
		for(int i=hd[u];i;i=nxt[i]){
			int v=to[i],w=c[i];
			if(dis[u][p]+w<dis[v][p]){
				dis[v][p]=dis[u][p]+w;
				Q.push(node(v,dis[v][p]));
			}
		}
	}
	return;
}

void cln(){
	for(int i=1;i<=n;i++)f[i]=0;
	for(int i=1;i<=n;i++)for(int j=1;j<=n;j++)k[i][j][0]=k[i][j][1]=0;
	return;
}

void clsv(){
	for(int i=1;i<=n;i++)vis[i]=0;
	return;
}

void dfs(int u,int p,int o){
	if(vis[u]++)return;
	for(int i=hd[u];i;i=nxt[i]){
		int v=to[i],w=c[i];
		if(dis[v][p]+w==dis[u][p]){
			if(o==0)k[v][u][p]=1;
			else k[u][v][p]=1;
			dfs(v,p,o);
		}
	}
	return;
}

void dfs2(int u){
	if(vis[u]++)return;
	for(int i=hd[u];i;i=nxt[i]){
		int v=to[i],w=c[i];
		if((!k[u][v][0])||(!k[u][v][1]))continue;
		dfs2(v);
		f[u]=max(f[u],f[v]+w);
	}
	return;
}

int main(){
	n=read(),m=read();
	s1=read(),t1=read(),s2=read(),t2=read();
	for(int i=1,u,v,w;i<=m;i++){
		u=read(),v=read(),w=read();
		add(u,v,w),add(v,u,w);
	}
	Dijkstra(s1,0),Dijkstra(s2,1);
	
	cln();
	clsv();
	dfs(t1,0,0);
	clsv();
	dfs(t2,1,0);
	clsv();
	for(int i=1;i<=n;i++){if(!vis[i])dfs2(i);ans=max(ans,f[i]);}
	cln();
	clsv();
	dfs(t1,0,1);
	clsv();
	dfs(t2,1,0);
	clsv();
	for(int i=1;i<=n;i++){if(!vis[i])dfs2(i);ans=max(ans,f[i]);}
	cln();
	clsv();
	dfs(t1,0,0);
	clsv();
	dfs(t2,1,1);
	clsv();
	for(int i=1;i<=n;i++){if(!vis[i])dfs2(i);ans=max(ans,f[i]);}
	cln();
	clsv();
	dfs(t1,0,1);
	clsv();
	dfs(t2,1,1);
	clsv();
	for(int i=1;i<=n;i++){if(!vis[i])dfs2(i);ans=max(ans,f[i]);}
	printf("%d\n",ans);
	return 0;
}
