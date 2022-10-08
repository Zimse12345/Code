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
int T,n,m,hd[N],nxt[N*2],to[N*2],ec,ans[N];
int cnt[N],sz,rt,rs,vis[N],dis[N],dep;
struct node{int x,y;node(int x=0,int y=0):x(x),y(y){}};
vector<node> q[N],Q;
inline void add(int u,int v){nxt[++ec]=hd[u],hd[u]=ec,to[ec]=v;return;}

void findrt(int u,int from){
	cnt[u]=1;
	int ms=0;
	for(int i=hd[u],v;i;i=nxt[i]){
		v=to[i];
		if(v==from||vis[v])continue;
		findrt(v,u),cnt[u]+=cnt[v],ms=max(ms,cnt[v]);
	}
	ms=max(ms,sz-cnt[u]);
	if(ms<rs)rs=ms,rt=u;
	return;
}

void dfs(int u,int from,int d){
	++dis[d],dep=max(dep,d);
	for(unsigned i=0;i<q[u].size();i++)Q.push_back(node(q[u][i].x-d,q[u][i].y));
	for(int i=hd[u],v;i;i=nxt[i]){
		v=to[i];
		if(v==from||vis[v])continue;
		dfs(v,u,d+1);
	}
	return;
}

void calc(int u,int tag){
	dep=0,Q.clear();
	dfs(u,0,tag==1?0:1);
	for(unsigned i=0;i<Q.size();i++){
		if(Q[i].x>=0)ans[Q[i].y]+=tag*dis[Q[i].x];
	}
	for(int i=0;i<=dep;i++)dis[i]=0;
	return;
}

void divide(int u){
	vis[u]=1;
	calc(u,1);
	for(int i=hd[u],v;i;i=nxt[i]){
		v=to[i];
		if(vis[v])continue;
		calc(v,-1);
		sz=cnt[v],rs=INF,findrt(v,u);
		divide(rt);
	}
	return;
}

signed main(){
	T=read();
	while(T--){
		n=read(),m=read();
		for(int i=1,u,v;i<n;i++)u=read(),v=read(),add(u,v),add(v,u);
		for(int i=1,x,k;i<=m;i++)x=read(),k=read(),q[x].push_back(node(k,i)),ans[i]=0;
		sz=n,rs=INF,findrt(1,0);
		divide(rt);
		for(int i=1;i<=m;i++)printf("%d\n",ans[i]);
		for(int i=1;i<=n;i++)q[i].clear(),hd[i]=vis[i]=0;
		for(int i=1;i<=ec;i++)to[i]=nxt[i]=0;
		ec=0;
	}
	return 0;
}

