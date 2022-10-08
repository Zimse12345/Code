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

const int N=2e5+7,Mod=998244353,INF=1e9+7;
int n,m,s,t,hd[N],nxt[N],ec=1,ans,sum;
struct edge{int u,v,val,cost;edge(int u=0,int v=0,int val=0,int cost=0):u(u),v(v),val(val),cost(cost){}}E[N];
inline void add(int u,int v,int val,int cost){nxt[++ec]=hd[u],hd[u]=ec,E[ec]=edge(u,v,val,cost);return;}
inline void Add(int u,int v,int val,int cost){add(u,v,val,cost),add(v,u,0,-cost);return;}

int dis[N],inq[N],le[N];
queue<int> Q;
bool spfa(){
	for(int i=1;i<=n;i++)dis[i]=INF,le[i]=0;
	dis[s]=0,Q.push(s);
	while(!Q.empty()){
		int u=Q.front();
		inq[u]=0,Q.pop();
		for(int i=hd[u];i;i=nxt[i])if(E[i].val&&dis[u]+E[i].cost<dis[E[i].v]){
			dis[E[i].v]=dis[u]+E[i].cost,le[E[i].v]=i;
			if(!inq[E[i].v])inq[E[i].v]=1,Q.push(E[i].v);
		}
	}
	return le[t];
}

void ek(){
	while(spfa()){
		int flow=INF,cost=0;
		for(int i=le[t];i;i=le[E[i].u])flow=min(flow,E[i].val),cost+=E[i].cost;
		ans+=flow,sum+=flow*cost;
		for(int i=le[t];i;i=le[E[i].u])E[i].val-=flow,E[i^1].val+=flow;
	}
	return;
}

signed main(){
	n=read(),m=read(),s=read(),t=read();
	for(int i=1,u,v,f,c;i<=m;i++)u=read(),v=read(),f=read(),c=read(),Add(u,v,f,c);
	ek();
	printf("%d %d\n",ans,sum);
	return 0;
}

