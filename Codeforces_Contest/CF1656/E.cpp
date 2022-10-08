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
while(qrc<'0'||qrc>'9'){if(qrc=='-'){qry=-1,qrc=getchar();}else qrc=getchar();}
while(qrc>='0'&&qrc<='9')qrx=qrx*10+qrc-48,qrc=getchar();return qrx*qry;}

const int N=1e6+7,Mod=998244353,INF=1e9+7;
int n,hd[N],nxt[N],to[N],ec,deg[N];
inline void add(int u,int v){nxt[++ec]=hd[u],hd[u]=ec,to[ec]=v;return;}

void dfs(int u,int from,int t){
	deg[u]*=t;
	for(int i=hd[u],v;i;i=nxt[i]){
		v=to[i];
		if(v==from)continue;
		dfs(v,u,-t);
	}
	return;
}

signed main(){
	int T=read();
	while(T--){
	n=read();
	for(int i=1,u,v;i<n;i++){
		u=read(),v=read();
		add(u,v),add(v,u);
		++deg[u],++deg[v];
	}
	dfs(1,0,1);
	for(int i=1;i<=n;i++)printf("%d ",deg[i]);
	printf("\n");
	for(int i=1;i<=n;i++)deg[i]=hd[i]=0;
	for(int i=1;i<=ec;i++)nxt[i]=to[i]=0;
}
	return 0;
}

