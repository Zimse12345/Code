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
while(qrc<'0'||qrc>'9'){if(qrc=='-')qry=-1;qrc=getchar();}
while(qrc>='0'&&qrc<='9')qrx=qrx*10+qrc-48,qrc=getchar();return qrx*qry;}

const int N=4e5+7,Mod=998244353,INF=1e9+7;
int n,m,a[N],ans;
int hd[N],nxt[N],ec=1,tot,S,T,d[N],h[N];

struct edge{
	int to,f;
	edge(int to=0,int f=0):to(to),f(f){}
}E[N];
inline void add(int u,int v,int f){nxt[++ec]=hd[u],hd[u]=ec,E[ec]=edge(v,f);return;}
inline void link(int u,int v,int f){add(u,v,f),add(v,u,0);return;}

queue<int> Q; 
bool bfs(){
	for(int i=1;i<=tot;i++)d[i]=0;
	d[S]=1,Q.push(S);
	while(!Q.empty()){
		int u=Q.front();
		Q.pop();
		for(int i=hd[u];i;i=nxt[i])if(E[i].f&&!d[E[i].to]){
			d[E[i].to]=d[u]+1;
			Q.push(E[i].to);
		}
	}
	return d[T];
}

int dfs(int u,int maxf){
	if(u==T||!maxf)return maxf;
	int flow=0;
	for(int i=h[u];i;i=nxt[i]){
		if(d[E[i].to]==d[u]+1){
			int f=dfs(E[i].to,min(maxf,E[i].f));
			E[i].f-=f,E[i^1].f+=f,maxf-=f,flow+=f;
			if(!maxf)break;
		}
		h[u]=nxt[i];
	}
	return flow;
}

void dinic(){
	while(bfs()){
		for(int i=1;i<=tot;i++)h[i]=hd[i];
		ans+=dfs(S,INF);
	}
	return;
}

signed main(){
	n=read(),m=read();
	tot=n+2,S=n+1,T=n+2;
	for(int i=1;i<=n;i++){
		a[i]=read();
		if(a[i])link(S,i,1);
		else link(i,T,1);
	}
	while(m--){
		int u=read(),v=read();
		link(u,v,1),link(v,u,1);
	}
	dinic();
	printf("%d\n",ans);
	return 0;
}

