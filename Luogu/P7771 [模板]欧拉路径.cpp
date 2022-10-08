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

using namespace std;

inline int read(){int qrx=0,qry=1;char qrc=getchar();
while(qrc<'0'||qrc>'9'){if(qrc=='-'){qry=-1,qrc=getchar();}else qrc=getchar();}
while(qrc>='0'&&qrc<='9')qrx=qrx*10+qrc-48,qrc=getchar();return qrx*qry;}
inline void write(int x){if(x<0){putchar('-'),x=-x;}if(x>9)write(x/10);putchar(x%10+'0');}

const int N=4e5+7,Mod=998244353,INF=1e9+7;
int n,m,indeg[N],outdeg[N],ans[N],t,del[N];
vector<int> g[N];

void dfs(int u){
	for(int i=del[u];i<signed(g[u].size());i=del[u]){
		del[u]=i+1;
		dfs(g[u][i]);
	}
	ans[++t]=u;
	return;
}

signed main(){
	n=read(),m=read();
	for(int i=1,u,v;i<=m;i++){
		u=read(),v=read(),++indeg[v],++outdeg[u];
		g[u].push_back(v);
	}
	int c1=0,c2=0,s=1;
	for(int i=1;i<=n;i++){
		if(indeg[i]>outdeg[i])c1++;
		else if(indeg[i]<outdeg[i])c2++,s=i;
		else if(indeg[i]!=outdeg[i])return !printf("No\n");
		if(c1>1||c2>1)return !printf("No\n");
		sort(g[i].begin(),g[i].end());
	}
	if(c1^c2)return !printf("No\n");
	dfs(s);
	for(int i=t;i>=1;i--)printf("%d ",ans[i]);
	printf("\n");
	return 0;
}
