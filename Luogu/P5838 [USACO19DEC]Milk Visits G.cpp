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

const int N=2e5+7,Mod=998244353,INF=1e9+7;
int n,m,cl[N],hd[N],nxt[N],to[N],ec;
int top[N],vis[N],ans[N],tc[N];
inline void add(int u,int v){nxt[++ec]=hd[u],hd[u]=ec,to[ec]=v;return;}
struct node{int x,y;node(int x=0,int y=0):x(x),y(y){}};
vector<node> p[N];

void dfs(int u,int from){
	for(int i=0;i<signed(p[u].size());i++){
		if(!vis[p[u][i].x])top[p[u][i].x]=tc[p[u][i].y],vis[p[u][i].x]=1;
		else if(tc[p[u][i].y]!=top[p[u][i].x])ans[p[u][i].x]=1;
	}
	int _tc=tc[cl[u]];
	for(int i=hd[u],v;i;i=nxt[i]){
		v=to[i];
		if(v==from)continue;
		tc[cl[u]]=v,dfs(v,u);
	}
	tc[cl[u]]=_tc;
	return;
}

signed main(){
	n=read(),m=read();
	for(int i=1;i<=n;i++)cl[i]=read();
	for(int i=1,u,v;i<n;i++)u=read(),v=read(),add(u,v),add(v,u);
	for(int i=1,a,b,c;i<=m;i++){
		a=read(),b=read(),c=read();
		if(cl[a]==c||cl[b]==c)ans[i]=1;
		else p[a].push_back(node(i,c)),p[b].push_back(node(i,c));
	}
	dfs(1,0);
	for(int i=1;i<=m;i++)printf("%d",ans[i]);
	printf("\n");
	return 0;
}

