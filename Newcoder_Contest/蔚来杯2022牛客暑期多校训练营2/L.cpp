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

const int N=1e4+7,Mod=998244353,INF=1e9+7;
int n,m,f[N],g[N];

signed main(){
	n=read(),m=read();
	int ans=INF; 
	for(int i=1;i<=m;i++)f[i]=-INF;
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++)g[j]=-INF;
		int k=read();
		while(k--){
			int u=read(),v=read();
			g[v]=max(g[v],f[u]);
			if(u==1)g[v]=i;
		}
		for(int u=1;u<=n;u++){
			int v=u;
			g[v]=max(g[v],f[u]);
			if(u==1)g[v]=i;
		}
		for(int j=1;j<=m;j++)f[j]=g[j];
		ans=min(ans,i-f[m]+1);
	}
	if(ans>n)ans=-1;
	printf("%d\n",ans);
	return 0;
}

