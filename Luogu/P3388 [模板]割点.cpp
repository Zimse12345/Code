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
int n,m,dfn[N],ct,low[N],ans[N],t,rc,tag[N];
vector<int> g[N];

void tarjan(int u,int pr){
	dfn[u]=low[u]=++ct;
	for(int i=0,v;i<int(g[u].size());i++){
		v=g[u][i];
		if(!dfn[v]){
			tarjan(v,pr);
			low[u]=min(low[u],low[v]);
			if(low[v]>=dfn[u]&&u!=pr)tag[u]=1;
			if(u==pr)++rc;
		}
		low[u]=min(low[u],dfn[v]);
	}
	if(u==pr&&rc>1)tag[u]=1;
	return;
}

int main(){
	n=read(),m=read();
	for(int i=1,u,v;i<=m;i++){
		u=read(),v=read();
		g[u].push_back(v),g[v].push_back(u);
	}
	for(int i=1;i<=n;i++)if(!dfn[i])rc=0,tarjan(i,i);
	for(int i=1;i<=n;i++)if(tag[i])ans[++t]=i;
	printf("%d\n",t);
	for(int i=1;i<=t;i++)printf("%d ",ans[i]);
	printf("\n");
	return 0;
}
