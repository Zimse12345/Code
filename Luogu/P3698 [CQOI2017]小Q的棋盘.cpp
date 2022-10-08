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

const int N=1e3+7,Mod=998244353,INF=1e9+7;
int n,m,f[N][N],g[N][N],h[N],x[N],ans;
vector<int> G[N];

void dp(int u,int from){
	for(int i=0;i<signed(G[u].size());i++)if(G[u][i]!=from)dp(G[u][i],u);
	for(int i=0;i<=m;i++)f[u][i]=g[u][i]=1;
	
	for(int i=0,v;i<signed(G[u].size());i++){
		v=G[u][i];
		if(v==from)continue;
		for(int K=0;K<=m;K++)x[K]=f[u][K];
		for(int j=0;j+2<=m;j++){
			for(int k=m;k>=j+2;k--)f[u][k]=max(f[u][k],x[k-j-2]+f[v][j]);
		}
	}
	for(int I=0,p;I<signed(G[u].size());I++){
		p=G[u][I];
		if(p==from)continue;
		for(int J=0;J<=m;J++)h[J]=1;
		for(int i=0,v,t;i<signed(G[u].size());i++){
			v=G[u][i];
			if(v==from)continue;
			if(v==p)t=1;else t=2;
			for(int K=0;K<=m;K++)x[K]=h[K];
			for(int j=0;j+t<=m;j++){
				for(int k=m;k>=j+t;k--){
					if(v==p)h[k]=max(h[k],x[k-j-t]+g[v][j]);
					else h[k]=max(h[k],x[k-j-t]+f[v][j]);
				}
			}
		}
		for(int J=0;J<=m;J++)g[u][J]=max(g[u][J],h[J]);
	}
	return;
}

int main(){
	n=read(),m=read();
	for(int i=1,u,v;i<n;i++){
		u=read()+1,v=read()+1;
		G[u].push_back(v),G[v].push_back(u);
	}
	dp(1,0);
	for(int i=0;i<=m;i++)ans=max(ans,g[1][i]);
	printf("%d\n",ans);
	return 0;
}
