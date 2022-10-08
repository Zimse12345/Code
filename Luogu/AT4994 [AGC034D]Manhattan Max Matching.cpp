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

const int N=1e5+7,Mod=998244353,INF=1e16;
int n,s,t,hd[N],nxt[N],ec=1,sum;
struct edge{int u,v,flow,cost;edge(int u=0,int v=0,int flow=0,int cost=0):u(u),v(v),flow(flow),cost(cost){}}E[N];
inline void add(int u,int v,int flow,int cost){nxt[++ec]=hd[u],hd[u]=ec,E[ec]=edge(u,v,flow,cost);return;}
inline void Add(int u,int v,int flow,int cost){add(u,v,flow,cost),add(v,u,0,-cost);return;}

int inq[N],dis[N],le[N];
queue<int> Q;
bool spfa(){
	for(int i=1;i<=n;i++)dis[i]=-INF,le[i]=0;
	dis[s]=0,Q.push(s);
	while(!Q.empty()){
		int u=Q.front();
		Q.pop(),inq[u]=0;
		for(int i=hd[u];i;i=nxt[i])if(E[i].flow&&dis[u]+E[i].cost>dis[E[i].v]){
			dis[E[i].v]=dis[u]+E[i].cost,le[E[i].v]=i;
			if(!inq[E[i].v])Q.push(E[i].v),inq[E[i].v]=1;
		}
	}
	return le[t];
}

void ek(){
	while(spfa()){
		int flow=INF,cost=0;
		for(int i=le[t];i;i=le[E[i].u])flow=min(flow,E[i].flow),cost+=E[i].cost;
		for(int i=le[t];i;i=le[E[i].u])E[i].flow-=flow,E[i^1].flow+=flow; 
		sum+=flow*cost;
	}
	return;
}

signed main(){
	n=read();
	s=n*2+1,t=s+1;
	for(int i=1,x,y,z;i<=n;i++){
		x=read(),y=read(),z=read();
		Add(s,i,z,0);
		Add(i,t+1,INF,x+y);
		Add(i,t+2,INF,x-y);
		Add(i,t+3,INF,-x+y);
		Add(i,t+4,INF,-x-y);
	}
	for(int i=1,x,y,z;i<=n;i++){
		x=read(),y=read(),z=read();
		Add(i+n,t,z,0);
		Add(t+4,i+n,INF,x+y);
		Add(t+3,i+n,INF,x-y);
		Add(t+2,i+n,INF,-x+y);
		Add(t+1,i+n,INF,-x-y);
	}
	n=t+4;
	ek();
	printf("%lld\n",sum);
	return 0;
}

