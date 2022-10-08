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

inline int read(){int qrx=0,qry=1;char qrc=getchar();
while(qrc<'0'||qrc>'9'){if(qrc=='-')qry=-1;qrc=getchar();}
while(qrc>='0'&&qrc<='9')qrx=qrx*10+qrc-48,qrc=getchar();return qrx*qry;}

const int N=1e5+7,Mod=998244353,INF=1e15+7;
int n,a[N],b[N],c[N],sigmaa[N];
int prime[N],tot,pr[N],d[N],sigma[N];
int hd[N],nxt[N],ec=1,S,T,Flow,Cost;
int from[N],inq[N],dis[N];

struct edge{
	int u,v,f,c;
	edge(int u=0,int v=0,int f=0,int c=0):u(u),v(v),f(f),c(c){}
}E[N];
int ooo;
inline void add(int u,int v,int f,int c){nxt[++ec]=hd[u],hd[u]=ec,E[ec]=edge(u,v,f,c);return;}
inline void link(int u,int v,int f,int c){add(u,v,f,c),add(v,u,0,-c);++ooo;return;}

queue<int> q;
bool spfa(){
	for(int i=1;i<=n;i++)dis[i]=-INF,inq[i]=from[i]=0;
	dis[S]=0,q.push(S);
	while(!q.empty()){
		int u=q.front();
		q.pop(),inq[u]=0;
		for(int i=hd[u];i;i=nxt[i])if(E[i].f&&dis[u]+E[i].c>dis[E[i].v]){
			dis[E[i].v]=dis[u]+E[i].c,from[E[i].v]=i;
			if(!inq[E[i].v])q.push(E[i].v),inq[E[i].v]=1;
		}
	}
	return from[T];
}

void ek(){
	while(spfa()){
		int flow=INF,cost=0;
		for(int i=from[T];i;i=from[E[i].u])flow=min(flow,E[i].f),cost+=E[i].c;
		for(int i=from[T];i;i=from[E[i].u])E[i].f-=flow,E[i^1].f+=flow;
		if(Cost+flow*cost>=0)Flow+=flow,Cost+=flow*cost;
		else{
			int k=Cost/(-cost);
			Flow+=k;
			return;
		}
	}
	return;
}

int Sigma(int x){
	int cnt=0;
	for(int i=2;i*i<=x;i++){
		while(x%i==0)x/=i,++cnt;
	}
	if(x>1)++cnt;
	return cnt;
}

signed main(){
	n=read();
	for(int i=1;i<=n;i++)a[i]=read();
	for(int i=1;i<=n;i++)b[i]=read();
	for(int i=1;i<=n;i++)c[i]=read();
	sigma[1]=1;
	for(int i=2;i<N;i++){
		if(!pr[i])prime[++tot]=i,pr[i]=i,sigma[i]=2,d[i]=1;
		for(int j=1;j<=tot&&prime[j]*i<N;j++){
			pr[prime[j]*i]=prime[j],sigma[prime[j]*i]=2*sigma[i],d[prime[j]*i]=1;
			if(pr[i]==prime[j])d[prime[j]*i]=d[i]+1,sigma[prime[j]*i]=sigma[i]/(d[i]+1)*(d[i]+2);
		}
	}
	for(int i=1;i<=n;i++)sigmaa[i]=Sigma(a[i]);
	S=n+1,T=n+2;
	for(int i=1;i<=n;i++){
		if(sigmaa[i]&1)link(S,i,b[i],0);
		else link(i,T,b[i],0);
		for(int j=1;j<=n;j++){
			int x=1;
			if(a[i]%a[j]==0)x=a[i]/a[j];
			if(Sigma(x)==1){
				if(sigmaa[i]&1)link(i,j,INF,c[i]*c[j]);
				else link(j,i,INF,c[i]*c[j]);
			}
		}
	}
	n+=2;
	ek();
	printf("%lld\n",Flow);
	return 0;
}

