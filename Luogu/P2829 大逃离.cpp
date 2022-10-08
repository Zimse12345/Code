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

const int N=2e5+7,Mod=998244353,INF=1e15+7;
int n,m,k,t[N],vis[N],dis[N][2];
bool lk[5001][5001];
int nxt[N],to[N],d[N],hd[N],ec;

void add(int u,int v,int w){
	to[++ec]=v,d[ec]=w;
	nxt[ec]=hd[u],hd[u]=ec;
	return;
}

queue<int> Q;
void spfa(int s){
	for(int i=1;i<=n;i++)vis[i]=0,dis[i][0]=dis[i][1]=INF;
	dis[s][0]=0,Q.push(s);
	while(!Q.empty()){
		int u=Q.front();
		Q.pop(),vis[u]=0;
		for(int i=hd[u];i;i=nxt[i]){
			int v=to[i],w=d[i],tag=0;
			if(t[v]<k)continue;
			if(dis[u][0]+w<dis[v][0])dis[v][1]=dis[v][0],dis[v][0]=dis[u][0]+w,tag=1;
			else if(dis[u][0]+w!=dis[v][0]&&dis[u][0]+w<dis[v][1])dis[v][1]=dis[u][0]+w,tag=1;
			if(dis[u][1]+w<dis[v][1])dis[v][1]=dis[u][1]+w,tag=1;
			if((!vis[v])&&tag)Q.push(v),vis[v]=1;
		}
	}
	return;
}

signed main(){
	n=read(),m=read(),k=read();
	for(int i=1,u,v,w;i<=m;i++){
		u=read(),v=read(),w=read();
		add(u,v,w),add(v,u,w);
		if(!lk[u][v])++t[u],++t[v];
		lk[u][v]=lk[v][u]=1;
	}
	t[1]=t[n]=INF;
	spfa(1);
	if(dis[n][1]>=INF-1000)dis[n][1]=-1;
	printf("%lld\n",dis[n][1]);
	return 0;
}
