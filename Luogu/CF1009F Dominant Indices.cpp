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

const int N=2e6+7,Mod=998244353,INF=1e9+7;
int n,hd[N],nxt[N],to[N],ec;
inline void add(int u,int v){to[++ec]=v,nxt[ec]=hd[u],hd[u]=ec;return;}
vector<int> dp[N];
int x[N],p[N];

void dfs(int u,int from){
	dp[u].push_back(1);
	x[u]=1,p[u]=0;
	for(int i=hd[u],v;i;i=nxt[i]){
		v=to[i];
		if(v==from)continue;
		dfs(v,u),dp[v].push_back(0);
		if(dp[u].size()<dp[v].size())swap(dp[u],dp[v]),x[u]=x[v],p[u]=p[v]+1;
		int p1=dp[u].size()-1,p2=dp[v].size()-1,D=0;
		while(p2>=0){
			dp[u][p1]+=dp[v][p2];
			if(dp[u][p1]>x[u]||(dp[u][p1]==x[u]&&D<p[u]))p[u]=D,x[u]=dp[u][p1];
			++D,--p1,--p2;
		}
		dp[v].resize(0);
	}
	return;
}

signed main(){
	n=read();
	for(int i=1,u,v;i<n;i++)u=read(),v=read(),add(u,v),add(v,u);
	dfs(1,0);
	for(int i=1;i<=n;i++)printf("%d\n",p[i]);
	return 0;
}

