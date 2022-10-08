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

const int N=1e2+7,Mod=998244353,INF=1e8+7;
int n,m,dis[N][N],a[N][N],ans=INF;

int main(){
	n=read(),m=read();
	for(int i=1;i<=n;i++)for(int j=1;j<=n;j++)dis[i][j]=INF;
	for(int i=1,u,v,w;i<=m;i++){
		u=read(),v=read(),w=read();
		dis[u][v]=min(dis[u][v],w);
		dis[v][u]=min(dis[v][u],w);
	}
	for(int i=1;i<=n;i++)for(int j=1;j<=n;j++)a[i][j]=dis[i][j];
	for(int k=1;k<=n;k++){
		for(int i=1;i<k;i++)for(int j=i+1;j<=k;j++)ans=min(ans,dis[i][j]+a[i][k]+a[k][j]);
		for(int i=1;i<=n;i++)for(int j=1;j<=n;j++)dis[i][j]=dis[j][i]=min(dis[i][j],dis[i][k]+dis[k][j]);
	}
	if(ans>=INF)printf("No solution.\n");
	else printf("%d\n",ans);
	return 0;
}
