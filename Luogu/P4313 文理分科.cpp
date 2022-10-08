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

const int N=4e5+7,M=120,Mod=998244353,INF=1e9;
int n,m,s,t,hd[N],h[N],nxt[N],d[N],ec=1,ans,tot,sum;
int art[M][M],sci[M][M],same_art[M][M],same_sci[M][M];
struct edge{int u,v,val;edge(int u=0,int v=0,int val=0):u(u),v(v),val(val){}}E[N];
inline void add(int u,int v,int val){nxt[++ec]=hd[u],hd[u]=ec,E[ec]=edge(u,v,val);return;}
inline void Add(int u,int v,int val){if(val<INF)sum+=val;add(u,v,val),add(v,u,0);return;}
inline int c(int x,int y){return (x-1)*m+y;}

queue<int> Q;
bool bfs(){
	for(int i=1;i<=tot;i++)d[i]=0;
	d[s]=1,Q.push(s);
	while(!Q.empty()){
		int u=Q.front();Q.pop();
		for(int i=hd[u];i;i=nxt[i])if(E[i].val&&!d[E[i].v])d[E[i].v]=d[u]+1,Q.push(E[i].v);
	}
	return d[t];
}

int dfs(int u,int maxf){
	if(u==t||!maxf)return maxf;
	int flow=0;
	for(int i=h[u];i;i=nxt[i]){
		if(E[i].val&&d[E[i].v]==d[u]+1){
			int f=dfs(E[i].v,min(maxf,E[i].val));
			flow+=f,maxf-=f,E[i].val-=f,E[i^1].val+=f;
			if(!maxf)break;
		}
		h[u]=nxt[h[u]];
	}
	return flow;
}

void dinic(){
	while(bfs()){
		for(int i=1;i<=tot;i++)h[i]=hd[i];
		ans+=dfs(s,INF);
	}
	return;
}

signed main(){
	n=read(),m=read();
	tot=c(n,m)+2,s=tot-1,t=tot;
	for(int i=1;i<=n;i++)for(int j=1;j<=m;j++)Add(s,c(i,j),read());
	for(int i=1;i<=n;i++)for(int j=1;j<=m;j++)Add(c(i,j),t,read());
	for(int i=1;i<=n;i++)for(int j=1;j<=m;j++){
		Add(s,++tot,read()),Add(tot,c(i,j),INF);
		if(i>1)Add(tot,c(i-1,j),INF);
		if(i<n)Add(tot,c(i+1,j),INF);
		if(j>1)Add(tot,c(i,j-1),INF);
		if(j<m)Add(tot,c(i,j+1),INF);
	}
	for(int i=1;i<=n;i++)for(int j=1;j<=m;j++){
		Add(++tot,t,read()),Add(c(i,j),tot,INF);
		if(i>1)Add(c(i-1,j),tot,INF);
		if(i<n)Add(c(i+1,j),tot,INF);
		if(j>1)Add(c(i,j-1),tot,INF);
		if(j<m)Add(c(i,j+1),tot,INF);
	}
	dinic();
	printf("%d\n",sum-ans);
	return 0;
}

