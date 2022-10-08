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
int n,m,pr[N],pt[N],f[N][N],h[N];
vector<int> g[N];

void dp(int u){
	for(int i=0,v;i<signed(g[u].size());i++){
		v=g[u][i],dp(v);
		for(int k=0;k<=m;k++)h[k]=f[u][k];
		for(int j=0;j<=m;j++){
			for(int k=j;k<=m;k++)h[k]=max(h[k],f[u][k-j]+f[v][j]);
		}
		for(int k=0;k<=m;k++)f[u][k]=h[k];
	}
	for(int i=m;i>=1;i--)f[u][i]=f[u][i-1]+pt[u];
	return;
}

int main(){
	n=read(),m=read()+1;
	for(int i=1;i<=n;i++)pr[i]=read(),pt[i]=read(),g[pr[i]].push_back(i);
	dp(0);
	printf("%d\n",f[0][m]);
	return 0;
}
