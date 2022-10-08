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

const int N=256,Mod=998244353,INF=1e9+7;
int n,a[N][N],b[N][N];
int s,t,hd[N*N],nxt[N*N],ec=1;
int tot,inq[N*N],from[N*N];
double Cost,dis[N*N];
struct edge{
	int u,v,f;double c;
	edge(int u=0,int v=0,int f=0,double c=0):u(u),v(v),f(f),c(c){}
}E[N*N];

inline void add(int u,int v,int f,double c){nxt[++ec]=hd[u],hd[u]=ec,E[ec]=edge(u,v,f,c);return;}
inline void link(int u,int v,int f,double c){add(u,v,f,c),add(v,u,0,-c);return;}

queue<int> q;
bool spfa(){
	for(int i=1;i<=tot;i++)dis[i]=INF,inq[i]=from[i]=0;
	dis[s]=0,q.push(s);
	while(!q.empty()){
		int u=q.front();
		q.pop(),inq[u]=0;
		for(int i=hd[u];i;i=nxt[i])if(E[i].f&&dis[u]+E[i].c<dis[E[i].v]){
			dis[E[i].v]=dis[u]+E[i].c,from[E[i].v]=i;
			if(!inq[E[i].v])q.push(E[i].v),inq[E[i].v]=1;
		}
	}
	return from[t];
}

void ek(){
	while(spfa()){
		int flow=INF;
		double cost=0;
		for(int i=from[t];i;i=from[E[i].u])flow=min(flow,E[i].f),cost+=E[i].c;
		for(int i=from[t];i;i=from[E[i].u])E[i].f-=flow,E[i^1].f+=flow;
		Cost+=cost*flow;
	}
	return;
}

bool check(double x){
	for(int i=1;i<=tot;i++)hd[i]=0;
	ec=1;
	for(int i=1;i<=n;i++)link(s,i,1,0),link(i+n,t,1,0);
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++){
			link(i,j+n,1,b[i][j]*x-a[i][j]);
		}
	}
	Cost=0,ek();
	return Cost<=0;
}

signed main(){
	n=read();
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++)a[i][j]=read();
	}
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++)b[i][j]=read();
	}
	tot=n*2+2,s=tot-1,t=tot;
	double L=0,R=1e4,ans=0;
	while(R-L>1e-8){
		double M=(L+R)/2;
		if(check(M))ans=L=M;
		else R=M;
	}
	printf("%.6lf\n",ans);
	return 0;
}

