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

const int N=8e5+7,Mod=998244353,INF=1e15+7;
int n,q,s,cnt,Lid[N][2],Rid[N][2];
int Id[N][2],rt1,rt2;
int h[N][2],t[2];
int vis[N],dis[N];
struct edge{
	int to,w;
	edge(int to=0,int w=0):to(to),w(w){}
};
vector<edge> g[N];
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
		if(vis[u]++)continue;
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

signed main(){
	n=read(),q=read(),s=read();
	rt1=++cnt;
	build(1,n,rt1,0);
	rt2=++cnt;
	build(1,n,rt2,1);
	for(int i=1;i<=n;i++)add(Id[i][0],Id[i][1],0),add(Id[i][1],Id[i][0],0);
	for(int i=1,ty,u,v,w,l,r;i<=q;i++){
		ty=read();
		if(ty==1){
			u=read(),v=read(),w=read();
			add(Id[u][0],Id[v][1],w);
			continue;
		}
		u=read(),l=read(),r=read(),w=read();
		t[0]=t[1]=0;
		if(ty==2)cn(1,n,rt1,u,u,0),cn(1,n,rt2,l,r,1);
		if(ty==3)cn(1,n,rt1,l,r,0),cn(1,n,rt2,u,u,1);
		for(int l=1;l<=t[0];l++)for(int r=1;r<=t[1];r++)add(h[l][0],h[r][1],w);
	}
	Dijkstra(Id[s][0]);
	for(int i=1;i<=n;i++){
		if(dis[Id[i][1]]>=INF)printf("-1 ");
		else printf("%lld ",dis[Id[i][1]]);
	}
	return 0;
}
