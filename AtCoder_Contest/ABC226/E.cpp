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

#define int long long
#define ull unsigned long long

using namespace std;

int read(){int qrx=0,qry=1;char qrc=getchar();
while(qrc<'0'||qrc>'9'){if(qrc=='-'){qry=-1,qrc=getchar();}else qrc=getchar();}
while(qrc>='0'&&qrc<='9')qrx=qrx*10+qrc-48,qrc=getchar();return qrx*qry;}

const int N=2e5+7,Mod=998244353,INF=1e9+7;
int n,m,t[N],P,vis[N];
vector<int> g[N],a[N];

void dfs(int u,int tag){
	if(vis[u])return;
	vis[u]=tag,a[tag].push_back(u);
	for(int i=0;i<g[u].size();i++)dfs(g[u][i],tag);
	return;
}

signed main(){
	n=read(),m=read();
	if(n!=m){
		printf("0\n");
		return 0;
	}
	for(int i=1,u,v;i<=m;i++){
		u=read(),v=read(),++t[u],++t[v];
		g[u].push_back(v),g[v].push_back(u);
	}
	int ans=1;
	for(int i=1,c;i<=n;i++)if(!vis[i]){
		dfs(i,++P),c=0;
		for(int j=0;j<a[P].size();j++)c+=t[a[P][j]]-2;
		if(c<0){
			ans=0;
			break;
		}
		for(int i=1;i<=c+1;i++)ans=(ans*2)%Mod;	
	}
	printf("%lld\n",ans);
	return 0;
}
