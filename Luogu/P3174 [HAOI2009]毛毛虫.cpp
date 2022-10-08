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
int n,m,f[N],g[N],ans;
vector<int> G[N];

void dp(int u,int from){
	int m1=0,m2=0,sz=G[u].size();
	if(from!=0)--sz;
	for(int i=0,v;i<signed(G[u].size());i++){
		v=G[u][i];
		if(v==from)continue;
		dp(v,u);
		f[u]=max(f[u],f[v]+sz);
		if(f[v]>m1)m2=m1,m1=f[v];
		else if(f[v]>m2)m2=f[v];
	}
	g[u]=m1+m2+sz;
	if(m2)--g[u];
	if(sz==0)f[u]=g[u]=1;
	ans=max(ans,g[u]+(from==0?0:1));
	return;
}

int main(){
	n=read(),m=read();
	for(int i=1,u,v;i<=m;i++){
		u=read(),v=read();
		G[u].push_back(v),G[v].push_back(u);
	}
	dp(1,0);
	printf("%d\n",ans);
	return 0;
}
