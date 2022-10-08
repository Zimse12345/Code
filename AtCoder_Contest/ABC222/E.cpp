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

const int N=1e3+7,Mod=998244353,INF=1e9+7;
int n,m,k,fa[N],fi[N],dep[N],A[N],a[N];
int f[2000007][2];
int s=1000000;
struct edge{
	int to,id;
	edge(int to=0,int id=0):to(to),id(id){};
};
vector<edge> g[N];

void dfs(int u,int pr,int d){
	dep[u]=d;
	for(int i=0;i<g[u].size();i++){
		int v=g[u][i].to;
		if(v==pr)continue;
		dfs(v,u,d+1),fa[v]=u,fi[v]=g[u][i].id;
	}
	return;
}

signed main(){
	n=read(),m=read(),k=read();
	for(int i=1;i<=m;i++)A[i]=read();
	for(int i=1,u,v;i<n;i++){
		u=read(),v=read();
		g[u].push_back(edge(v,i)),g[v].push_back(edge(u,i));
	}
	dfs(1,0,0);
	for(int i=1;i<m;i++){
		int u=A[i],v=A[i+1];
		while(u!=v){
			if(dep[u]>dep[v])++a[fi[u]],u=fa[u];
			else ++a[fi[v]],v=fa[v];
		}
	}
	int p=0;
	f[s][p]=1;
	int L=s,R=s;
	for(int i=1;i<n;i++)if(a[i]){
		//printf("[%d %d]\n",i,a[i]);
		p^=1;
		for(int j=L;j<=R;j++)f[j][p]=0;
		for(int j=L;j<=R;j++){	
			f[j-a[i]][p]=(f[j-a[i]][p]+f[j][p^1])%Mod;
			f[j+a[i]][p]=(f[j+a[i]][p]+f[j][p^1])%Mod;
		}
		L-=a[i],R+=a[i];
	}
	int ans=f[s+k][p];
	for(int i=1;i<n;i++)if(a[i]==0)ans=(ans*2ll)%Mod;
	printf("%lld\n",ans);
	return 0;
}
