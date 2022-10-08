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

inline int read(){int qrx=0,qry=1;char qrc=getchar();
while(qrc<'0'||qrc>'9'){if(qrc=='-')qry=-1;qrc=getchar();}
while(qrc>='0'&&qrc<='9')qrx=qrx*10+qrc-48,qrc=getchar();return qrx*qry;}

const int N=1e6+7,Mod=998244353,INF=1e9+7;
int n,m,hd[N],nxt[N],to[N],ec,dis[N],vis[N],deg[N];
inline void add(int u,int v){nxt[++ec]=hd[u],hd[u]=ec,to[ec]=v;return;}

struct node{
	int x,y;
	node(int x=0,int y=0):x(x),y(y){}
	bool operator < (const node& A)const{return y>A.y;}
};
priority_queue<node> q;

signed main(){
	n=read(),m=read();
	for(int i=1,u,v;i<=m;i++){
		u=read(),v=read();
		if(u==n)continue;
		add(v,u),++deg[u];
	}
	for(int i=1;i<=n;i++)dis[i]=INF;
	dis[n]=0,q.push(node(n,dis[n]));
	while(!q.empty()){
		int u=q.top().x;
		q.pop();
		if(vis[u]++)continue;
		for(int i=hd[u],v;i;i=nxt[i]){
			v=to[i];
			if(dis[u]+deg[v]<dis[v])dis[v]=dis[u]+deg[v],q.push(node(v,dis[v]));
			--deg[v];
		}
	}
	printf("%d\n",dis[1]);
	return 0;
}

