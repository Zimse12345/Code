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
inline int Id(int x,int y){return (x-1)*4+y;}

const int N=1e5+7,Mod=998244353,INF=1e9+7;
int H,W,n,sx,sy,tx,ty,X[N],Y[N];
int xx[N],xt,yy[N],yt,S,T;
struct node{int x,y;node(int x=0,int y=0):x(x),y(y){}
bool operator < (const node& A)const{if(x==A.x)return y<A.y;return x<A.x;}}px[N],py[N];
set<node> _x[N],_y[N];
map<int,int> mx,my;
struct nd{int x,y;nd(int x=0,int y=0):x(x),y(y){}
bool operator < (const nd& A)const{return x>A.x;}};

int hd[N*4],nxt[N*4],to[N*4],ec;
void add(int u,int v){
	nxt[++ec]=hd[u],hd[u]=ec,to[ec]=v;
	return;
}

int ans,dis[N],vis[N];
priority_queue<nd> Q;
void dij(){
	for(int i=1;i<=n*4;i++)dis[i]=INF;
	dis[S]=0;
	Q.push(nd(0,S));
	while(!Q.empty()){
		int u=Q.top().y;Q.pop();
		if(vis[u]++)continue;
		for(int i=hd[u],v;i;i=nxt[i]){
			v=to[i];
			if(dis[u]+1<dis[v])dis[v]=dis[u]+1,Q.push(nd(dis[v],v));
		}
	}
	if(dis[T]!=INF)ans=dis[T];
	else ans=-1;
	return;
}

signed main(){
	H=read(),W=read(),n=read();
	sx=read(),sy=read(),tx=read(),ty=read();
	for(int i=1,x,y;i<=n;i++){
		x=read(),y=read(),X[i]=x,Y[i]=y,px[i]=node(x,i),py[i]=node(y,i);
		if(x-1==sx&&y==sy)S=Id(i,1);
		if(x+1==sx&&y==sy)S=Id(i,3);
		if(y-1==sy&&x==sx)S=Id(i,4);
		if(y+1==sy&&x==sx)S=Id(i,2);
		if(x-1==tx&&y==ty)T=Id(i,1);
		if(x+1==tx&&y==ty)T=Id(i,3);
		if(y-1==ty&&x==tx)T=Id(i,4);
		if(y+1==ty&&x==tx)T=Id(i,2);
	}
	sort(px+1,px+n+1),sort(py+1,py+n+1);
	
	for(int i=1;i<=n;i++){
		if(px[i].x!=px[i-1].x)xx[++xt]=px[i].x,mx[px[i].x]=xt;
		_x[xt].insert(node(Y[px[i].y],px[i].y));
	}
	for(int i=1;i<=n;i++){
		if(py[i].x!=py[i-1].x)yy[++yt]=py[i].x,my[py[i].x]=yt;
		_y[yt].insert(node(X[py[i].y],py[i].y));
	}
	for(int i=1;i<=xt;i++)_x[i].insert(node(0,0)),_x[i].insert(node(INF,0));
	for(int i=1;i<=yt;i++)_y[i].insert(node(0,0)),_y[i].insert(node(INF,0));
	for(int i=1;i<=n;i++){
		node p;
		if(mx.count(X[i]-1)){
			int ux=mx[X[i]-1];
			set<node>::iterator it=_x[ux].upper_bound(node(Y[i],0));
			p=*it;
			if(p.x!=INF)add(Id(i,1),Id(p.y,4));
			it--,p=*it;
			if(p.x!=0&&p.x!=Y[i])add(Id(i,1),Id(p.y,2));
		}
		if(mx.count(X[i]+1)){
			int ux=mx[X[i]+1];
			set<node>::iterator it=_x[ux].upper_bound(node(Y[i],0));
			p=*it;
			if(p.x!=INF)add(Id(i,3),Id(p.y,4));
			it--,p=*it;
			if(p.x!=0&&p.x!=Y[i])add(Id(i,3),Id(p.y,2));
		}
		if(my.count(Y[i]-1)){
			int uy=my[Y[i]-1];
			set<node>::iterator it=_y[uy].upper_bound(node(X[i],0));
			p=*it;
			if(p.x!=INF)add(Id(i,4),Id(p.y,1));
			it--,p=*it;
			if(p.x!=0&&p.x!=X[i])add(Id(i,4),Id(p.y,3));
		}
		if(my.count(Y[i]+1)){
			int uy=my[Y[i]+1];
			set<node>::iterator it=_y[uy].upper_bound(node(X[i],0));
			p=*it;
			if(p.x!=INF)add(Id(i,4),Id(p.y,1));
			it--,p=*it;
			if(p.x!=0&&p.x!=X[i])add(Id(i,4),Id(p.y,3));
		}
	}
	dij();
	printf("%d\n",ans);
	return 0;
}

