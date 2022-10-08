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

const int N=1e4+7,Mod=998244353,INF=1e12;
int n,m,ec=1,hd[N],nxt[N],h[N],d[N],s,t,ans;
struct edge{int u,v,val;edge(int u=0,int v=0,int val=0):u(u),v(v),val(val){}}E[N];
inline void add(int u,int v,int val){nxt[++ec]=hd[u],hd[u]=ec,E[ec]=edge(u,v,val);return;}

queue<int> Q;
bool BFS(){
	for(int i=1;i<=n;i++)d[i]=0;
	d[s]=1,Q.push(s);
	while(!Q.empty()){
		int u=Q.front();Q.pop();
		for(int i=hd[u];i;i=nxt[i]){
			if(!d[E[i].v]&&E[i].val>0)d[E[i].v]=d[u]+1,Q.push(E[i].v);
		}
	}
	return d[t]>0;
}

int DFS(int u,int maxf){
	if(u==t||!maxf)return maxf;
	int flow=0;
	for(int i=h[u];i;i=nxt[i]){
		if(d[E[i].v]==d[u]+1&&E[i].val){
			int f=DFS(E[i].v,min(maxf,E[i].val));
			E[i].val-=f,E[i^1].val+=f,maxf-=f,flow+=f;
			if(!maxf)break;
		}
		h[u]=nxt[h[u]];
	}
	if(!flow)d[u]=0;
	return flow;
}

void Dinic(){
	while(BFS()){
		for(int i=1;i<=n;i++)h[i]=hd[i];
		ans+=DFS(s,INF);
	}
	return;
}

signed main(){
	n=read(),m=read(),s=read(),t=read();
	for(int i=1,u,v,w;i<=m;i++){
		u=read(),v=read(),w=read();
		add(u,v,w),add(v,u,0);
	}
	Dinic();
	printf("%lld\n",ans);
	return 0;
}

