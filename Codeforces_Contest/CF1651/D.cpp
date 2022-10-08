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

const int N=2e6+7,Mod=998244353,INF=1e9+7;
int n,x[N],y[N],tot,dx[4]={0,-1,0,1},dy[4]={1,0,-1,0};
map< pair<int,int> , int> id;
queue<int> Q;

int hd[N],nxt[N],to[N],ec;
int dis[N],vis[N],fr[N];
void add(int u,int v){
	nxt[++ec]=hd[u],hd[u]=ec,to[ec]=v;
	return;
}

signed main(){
	n=read();
	tot=n;
	for(int i=1;i<=n;i++){
		x[i]=read(),y[i]=read();
		id[make_pair(x[i],y[i])]=i;
	}
	for(int i=1;i<=n;i++){
		for(int j=0;j<4;j++){
			int tx=x[i]+dx[j],ty=y[i]+dy[j];
			if(!id[make_pair(tx,ty)])id[make_pair(tx,ty)]=++tot,x[tot]=tx,y[tot]=ty;
			int v=id[make_pair(tx,ty)];
			add(i,v),add(v,i);
		}
	}
	id.clear();
	for(int i=1;i<=n;i++)dis[i]=INF;
	for(int i=n+1;i<=tot;i++)Q.push(i),fr[i]=i;
	while(!Q.empty()){
		int u=Q.front();
		Q.pop();
		if(vis[u]++)continue;
		for(int i=hd[u],v;i;i=nxt[i]){
			v=to[i];
			if(dis[u]+1<dis[v]){
				dis[v]=dis[u]+1,Q.push(v);
				fr[v]=fr[u];
			}
		}
	}
	for(int i=1;i<=n;i++)printf("%d %d\n",x[fr[i]],y[fr[i]]);
	return 0;
}

