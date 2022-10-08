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

const int N=2e5+7,Mod=998244353,INF=1e9;
int n,_n,m,T[300][300],s,t,hd[N],nxt[N],ec=1,ans,sum;
struct edge{int u,v,f,c;edge(int u=0,int v=0,int f=0,int c=0):u(u),v(v),f(f),c(c){}}E[N];
inline void add(int u,int v,int f,int c){nxt[++ec]=hd[u],hd[u]=ec,E[ec]=edge(u,v,f,c);return;}
inline void Add(int u,int v,int f,int c){add(u,v,f,c),add(v,u,0,-c);return;}

queue<int> Q;
int dis[N],inq[N],le[N];
bool spfa(){
	for(int i=1;i<=n;i++)dis[i]=INF,le[i]=0;
	dis[s]=0,Q.push(s);
	while(!Q.empty()){
		int u=Q.front();
		Q.pop(),inq[u]=0;
		for(int i=hd[u];i;i=nxt[i])if(E[i].f&&dis[u]+E[i].c<dis[E[i].v]){
			dis[E[i].v]=dis[u]+E[i].c,le[E[i].v]=i;
			if(!inq[E[i].v])Q.push(E[i].v),inq[E[i].v]=1;
		}
	}
	return le[t];
}

void ek(){
	while(spfa()){
		int flow=INF,c=0;
		for(int i=le[t];i;i=le[E[i].u])flow=min(flow,E[i].f),c+=E[i].c;
		ans+=flow,sum+=flow*c;
		for(int i=le[t];i;i=le[E[i].u])E[i].f-=flow,E[i^1].f+=flow;
	}
	return;
}

signed main(){
	m=read(),_n=n=read();
	for(int i=1;i<=n;i++)for(int j=1;j<=m;j++)T[i][j]=read();
	s=n+n*m+1,t=s+1;
	for(int i=1;i<=n;i++)Add(s,i,1,0);
	for(int i=n+1;i<=n+n*m;i++)Add(i,t,1,0);
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++){
			for(int k=0;k<n;k++){
				Add(i,n+k*m+j,1,(k+1)*T[i][j]);
			}
		}
	}
	n=t,ek();
	printf("%.2lf\n",double(sum)/double(_n));
	return 0;
}
