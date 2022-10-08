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
int n,k,val[N],fa[N],f[N][30],c[N][30];
vector<int> g[N];

void dfs(int u,int pr){
	fa[u]=pr;
	int p=u,q=0;
	while(q<=k&&p)f[p][q]+=val[u],p=fa[p],++q;
	for(int i=0,v;i<int(g[u].size());i++){
		v=g[u][i];
		if(v==pr)continue;
		dfs(v,u);
	}
	return;
}

void dfs2(int u,int pr){
	if(u!=1){
		for(int i=k;i>=2;i--)c[u][i]+=c[fa[u]][i-1]-c[u][i-2];
		c[u][1]+=c[fa[u]][0];
	}
	for(int i=0,v;i<int(g[u].size());i++){
		v=g[u][i];
		if(v==pr)continue;
		dfs2(v,u);
	}
	return;
}

int main(){
	n=read(),k=read();
	for(int i=1,u,v;i<n;i++){
		u=read(),v=read();
		g[u].push_back(v),g[v].push_back(u);
	}
	for(int i=1;i<=n;i++)val[i]=read();
	dfs(1,0);
	for(int i=1;i<=n;i++){
		c[i][0]=f[i][0];
		for(int j=1;j<=k;j++)c[i][j]=c[i][j-1]+f[i][j];
	}
	dfs2(1,0);
	for(int i=1;i<=n;i++)printf("%d\n",c[i][k]);
	return 0;
}