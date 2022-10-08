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

const int N=7e5+7,Mod=998244353,INF=1e9+7;
int n,q,s,cnt,Lid[N<<2][2],Rid[N<<2][2];
int Id[N<<2][2],rt1,rt2;
int h[N>>2][2],t[2];
bool vis[N<<2];
int dis[N<<2];
struct edge{
	int to;
	int w;
	edge(int to=0,int w=0):to(to),w(w){}
};
vector<edge> g[N<<2];
struct p{
	int id,d;
	p(int id=0,int d=0):id(id),d(d){}
	bool operator <(const p& A)const{return d>A.d;}
};
priority_queue<p> Q;

void add(int u,int v,int w){
	g[u].push_back(edge(v,w));
	return;
}

void build(int L,int R,int id,int p){
	if(L==R)Id[L][p]=id;
	else{
		int M=(L+R)>>1;
		Lid[id][p]=++cnt,Rid[id][p]=++cnt;
		build(L,M,Lid[id][p],p);
		build(M+1,R,Rid[id][p],p);
		if(p==0)add(Lid[id][p],id,0),add(Rid[id][p],id,0);
		else add(id,Lid[id][p],0),add(id,Rid[id][p],0);
	}
	return;
}

void cn(int L,int R,int id,int l,int r,int p){
	if(l<=L&&r>=R)h[++t[p]][p]=id;
	else{
		int M=(L+R)>>1;
		if(l<=M)cn(L,M,Lid[id][p],l,r,p);
		if(r>M)cn(M+1,R,Rid[id][p],l,r,p);
	}
	return;
}

void Dijkstra(int s){
	for(int i=1;i<=cnt;i++)dis[i]=INF;
	dis[s]=0;
	Q.push(p(s,0));
	while(!Q.empty()){
		int u=Q.top().id;
		Q.pop();
		if(vis[u])continue;
		vis[u]=1;
		for(int i=0;i<g[u].size();i++){
			int v=g[u][i].to,w=g[u][i].w;
			if(dis[u]+w<dis[v]){
				dis[v]=dis[u]+w;
				Q.push(p(v,dis[v]));
			}
		}
	}
	return;
}

int main(){
	n=read(),q=read(),s=read();
	rt1=++cnt;
	build(1,n,rt1,0);
	rt2=++cnt;
	build(1,n,rt2,1);
	for(int i=1;i<=n;i++)add(Id[i][0],Id[i][1],0),add(Id[i][1],Id[i][0],0);
	for(int i=1,a,b,c,d,e;i<=q;i++){
		a=read(),b=read(),c=read(),d=read(),e=++cnt;
		t[0]=t[1]=0;
		cn(1,n,rt1,a,b,0),cn(1,n,rt2,c,d,1);
		for(int l=1;l<=t[0];l++)add(h[l][0],e,1);
		for(int r=1;r<=t[1];r++)add(e,h[r][1],0);
		
		int T=a;a=c,c=T,T=b,b=d,d=T,e=++cnt;
		t[0]=t[1]=0;
		cn(1,n,rt1,a,b,0),cn(1,n,rt2,c,d,1);
		for(int l=1;l<=t[0];l++)add(h[l][0],e,1);
		for(int r=1;r<=t[1];r++)add(e,h[r][1],0);
	}
	Dijkstra(Id[s][0]);
	for(int i=1;i<=n;i++){
		if(dis[Id[i][1]]>=INF)printf("-1\n");
		else printf("%d\n",dis[Id[i][1]]);
	}
	return 0;
}
