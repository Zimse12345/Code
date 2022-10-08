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

const int N=1e5+7,Mod=998244353,INF=1e9+7;
int n,m,cnt=1,hd[N],nxt[N],ans,h[N],d[N];
struct edge{int u,v,val;edge(int u=0,int v=0,int val=0):u(u),v(v),val(val){}}E[N];
inline void add(int u,int v,int val){nxt[++cnt]=hd[u],hd[u]=cnt,E[cnt]=edge(u,v,val);return;}

queue<int> Q;
bool BFS(){
	for(int i=1;i<=n;i++)d[i]=0;
	d[n-1]=1,Q.push(n-1);
	while(!Q.empty()){
		int u=Q.front();Q.pop();
		for(int i=hd[u];i;i=nxt[i]){
			if(!d[E[i].v]&&E[i].val>0)d[E[i].v]=d[u]+1,Q.push(E[i].v);
		}
	}
	return d[n];
}

int DFS(int u,int maxf){
	if(u==n||!maxf)return maxf;
	int flow=0;
	for(int i=h[u];i;i=nxt[i]){
		h[u]=nxt[h[u]];
		if(d[E[i].v]==d[u]+1&&E[i].val){
			int f=DFS(E[i].v,min(maxf,E[i].val));
			E[i].val-=f,E[i^1].val+=f,maxf-=f,flow+=f;
			if(maxf==0)break;
		}
	}
	return flow;
}

void Dinic(){
	while(BFS()){
		for(int i=1;i<=n;i++)h[i]=hd[i];
		ans+=DFS(n-1,INF);
	}
	return;
}

signed main(){
	m=read(),n=read();
	int u,v;
	while(1){
		u=read(),v=read();
		if(u==-1||v==-1)break;
		add(u,v,1),add(v,u,0);
	}
	for(int i=1;i<=m;i++)add(n+1,i,1),add(i,n+1,0);
	for(int i=m+1;i<=n;i++)add(i,n+2,1),add(n+2,i,0);
	n+=2,Dinic(); 
	printf("%d\n",ans);
	n-=2;
	for(int i=2;i<=cnt;i+=2){
		if(E[i].u<=m&&E[i].v>m&&E[i].v<=n&&E[i].val==0)printf("%d %d\n",E[i].u,E[i].v);
	}
	return 0;
}

