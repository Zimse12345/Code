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

const int N=1e6+7,Mod=998244353,INF=1e9+7;
int n,m,k,vis[N],ans[N],t;
vector<int> g[N];

void dfs(int u,int d){
	vis[u]=1;
	if(d==0)return;
	for(int i=0;i<int(g[u].size());i++){
		int v=g[u][i];
		dfs(v,d-1);
	}
	return;
}

int main(){
	n=read(),m=read(),k=read();
	for(int i=1,u,v;i<=m;i++)u=read(),v=read(),g[u].push_back(v),g[v].push_back(u);
	for(int i=1;i<=n;i++)if(!vis[i]){
		ans[++t]=i;
		dfs(i,2);
	}
	printf("%d\n",t);
	for(int i=1;i<=t;i++)printf("%d ",ans[i]);
	printf("\n");
	return 0;
}
