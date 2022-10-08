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

using namespace std;

inline int read(){int qrx=0,qry=1;char qrc=getchar();
while(qrc<'0'||qrc>'9'){if(qrc=='-'){qry=-1,qrc=getchar();}else qrc=getchar();}
while(qrc>='0'&&qrc<='9')qrx=qrx*10+qrc-48,qrc=getchar();return qrx*qry;}

const int N=300,INF=1e9;
int n,m,dis[N][N],p[N][N],ans[N];

signed main(){
	n=read(),m=read();
	for(int i=1;i<=n;i++)for(int j=i+1;j<=n;j++)dis[i][j]=dis[j][i]=INF; 
	for(int i=1,u,v,w;i<=m;i++){
		u=read(),v=read(),w=read();
		dis[u][v]=dis[v][u]=min(dis[u][v],w);
	}
	for(int k=1;k<=n;k++){
		for(int i=1;i<=n;i++)if(i!=k){
			for(int j=1;j<=n;j++)if(j!=k&&j!=i){
				if(dis[i][k]+dis[k][j]<dis[i][j]){
					dis[i][j]=dis[i][k]+dis[k][j];
					p[i][j]=k;
				}
				else if(dis[i][k]+dis[k][j]==dis[i][j])p[i][j]=0;
			}
		}
	}
	for(int i=1;i<=n;i++)for(int j=1;j<=n;j++)ans[p[i][j]]=1;
	int tag=0;
	for(int i=1;i<=n;i++)if(ans[i])printf("%d ",i),tag=1;
	if(!tag)printf("No important cities.");
	putchar(10);
	return 0;
}
