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

inline int read(){int qrx=0,qry=1;char qrc=getchar();
while(qrc<'0'||qrc>'9'){if(qrc=='-'){qry=-1,qrc=getchar();}else qrc=getchar();}
while(qrc>='0'&&qrc<='9')qrx=qrx*10+qrc-48,qrc=getchar();return qrx*qry;}

const int N=1e3+7,Mod=998244353,INF=1e9+7;
int n,m,DateId,U[N],V[N],vis[N],ans,d[N][N];
vector<int> g[N];

int qp(int x,int k){
	int res=1;
	while(k){
		if(k&1ll)res=(res*x)%Mod;
		x=(x*x)%Mod,k/=2;
	}
	return res;
}

int dfs(int u){
	int res=(1<<u);
	if(vis[u]++)return res;
	for(unsigned i=0;i<g[u].size();i++)res|=dfs(g[u][i]);
	return res;
}

signed main(){
	n=read(),m=read(),DateId=read();
	for(int i=0;i<m;i++){
		U[i]=read(),V[i]=read();
	}
	if(DateId==2){
		for(int i=1;i<=n;i++)for(int j=1;j<=n;j++)d[i][j]=(i==j?0:INF);
		for(int i=0;i<m;i++)d[U[i]][V[i]]=d[V[i]][U[i]]=1;
		for(int k=1;k<=n;k++){
			for(int i=1;i<=n;i++){
				for(int j=1;j<=n;j++)d[i][j]=d[j][i]=min(d[i][j],d[i][k]+d[k][j]);
			}
		}
		printf("%lld\nÎÒ¶Á´íÌâÁË",(1+d[1][2])*qp(2,m-d[1][2])%Mod);
		return 0;
	}
	for(int i=0;i<(1<<m);i++){
		for(int j=1;j<=n;j++)g[j].resize(0);
		for(int j=0;j<m;j++){
			if(i&(1<<j))g[U[j]].push_back(V[j]);
			else g[V[j]].push_back(U[j]);
		}
		for(int j=1;j<=n;j++)vis[j]=0;
		int A=dfs(1);
		for(int j=1;j<=n;j++)vis[j]=0;
		int B=dfs(2);
		if(A&B)++ans;
	}
	printf("%lld\n",ans);
	return 0;
}

