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

const int N=2e3+7,Mod=998244353,INF=1e9+7;
int n,k,f[N][N],vis[N][N],ans;
int cnt[N],dep[N],fa[N];
struct edge{
	int to,w;
	edge(int to=0,int w=0):to(to),w(w){}
};
vector<edge> g[N];

void dfs1(int u,int pr,int d){
	cnt[u]=1,dep[u]=d;
	for(int i=0;i<g[u].size();i++){
		int v=g[u][i].to;
		if(v==pr)continue;
		dfs1(v,u,d+1),fa[v]=u,cnt[u]+=cnt[v];
	}
	return;
}

void dfs2(int u){
	f[u][0]=f[u][1]=0;
	if(cnt[u]==1)return;
	for(int i=0;i<g[u].size();i++){
		int v=g[u][i].to,w=g[u][i].w;
		if(v==fa[u])continue;
		dfs2(v);
		for(int j=min(k,cnt[u]);j>=0;j--){
			if(f[u][j]!=-1)f[u][j]+=f[v][0]+cnt[v]*(n-cnt[v]-k)*w;
			for(int z=min(j,cnt[v]);z>=1;z--){
				if(f[u][j-z]==-1)continue;
				int W=z*(k-z)*w+(cnt[v]-z)*(n-cnt[v]-k+z)*w+f[v][z];
				f[u][j]=max(f[u][j],f[u][j-z]+W);
			}
		}
	}
	return;
}

signed main(){
	n=read(),k=read();
	for(int i=1,u,v,w;i<n;i++){
		u=read(),v=read(),w=read();
		g[u].push_back(edge(v,w));
		g[v].push_back(edge(u,w));
	}
	memset(f,-1,sizeof(f));
	dfs1(1,0,0);
	dfs2(1);
	printf("%lld\n",f[1][k]);
	return 0;
}
