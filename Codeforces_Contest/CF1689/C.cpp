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
int T,n,cnt[N];
vector<int> g[N];

void dfs0(int u,int from){
	cnt[u]=1;
	for(unsigned i=0;i<g[u].size();i++)if(g[u][i]!=from)dfs0(g[u][i],u),cnt[u]+=cnt[g[u][i]];
	return;
}

int dfs(int u,int from){
	int sz=0;
	for(unsigned i=0;i<g[u].size();i++)if(g[u][i]!=from)++sz;
	if(!sz)return 0;
	if(sz==1){
		for(unsigned i=0;i<g[u].size();i++)if(g[u][i]!=from)return cnt[g[u][i]]-1;
		return 0;
	}
	else{
		int lc=0,rc=0,ls=0,rs=0;
		for(unsigned i=0;i<g[u].size();i++)if(g[u][i]!=from){
			if(!ls)ls=cnt[g[u][i]]-1,lc=dfs(g[u][i],u);
			else rs=cnt[g[u][i]]-1,rc=dfs(g[u][i],u);
		}
		return max(lc+rs,ls+rc);
	}
}

signed main(){
	T=read();
	while(T--){
		n=read();
		for(int i=1,u,v;i<n;i++){
			u=read(),v=read();
			g[u].push_back(v),g[v].push_back(u);
		}
		dfs0(1,0);
		printf("%d\n",dfs(1,0));
		for(int i=1;i<=n;i++)g[i].resize(0);
	}
	return 0;
}

