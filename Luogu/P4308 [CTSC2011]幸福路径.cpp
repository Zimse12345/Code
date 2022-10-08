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

const int N=1e2+7,Mod=998244353,INF=1e9+7;
int n,m,s;
double w[N],f[N][N],g[N][N],p,ans;

signed main(){
	n=read(),m=read();
	for(int i=1;i<=n;i++)scanf("%lf",&w[i]);
	s=read(),scanf("%lf",&p);
	for(int i=1;i<=n;i++)for(int j=1;j<=n;j++)if(i!=j)f[i][j]=-1e100;
	for(int i=1,u,v;i<=m;i++)u=read(),v=read(),f[u][v]=w[v]*p;
	for(int T=1;T<=32;T++){
		for(int i=1;i<=n;i++)for(int j=1;j<=n;j++)g[i][j]=f[i][j],f[i][j]=-1e100;
		for(int k=1;k<=n;k++)for(int i=1;i<=n;i++)for(int j=1;j<=n;j++)f[i][j]=max(f[i][j],g[i][k]+p*g[k][j]);
		p*=p;
	}
	for(int i=1;i<=n;i++)ans=max(ans,f[s][i]);
	printf("%.1lf\n",ans+w[s]);
	return 0;
}

