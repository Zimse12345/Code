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

const int N=15,Mod=998244353,INF=1e9+7;
int n,m,dis[N][N],f[10000][20],D[10000][20],ans=INF;

signed main(){
	n=read(),m=read();
	for(int i=0;i<n;i++)for(int j=0;j<n;j++)if(i^j)dis[i][j]=INF;
	while(m--){
		int u=read()-1,v=read()-1;
		dis[u][v]=dis[v][u]=min(dis[u][v],read());
	}
	for(int i=0;i<(1<<n);i++)for(int j=0;j<n;j++)if(!(i&(1<<j))){
		D[i][j]=INF;
		for(int w=0;w<n;w++)if(i&(1<<w))D[i][j]=min(D[i][j],dis[j][w]);
	}
	for(int i=0;i<(1<<n);i++)f[i][1]=INF;
	for(int i=0;i<n;i++)f[1<<i][1]=0;
	for(int k=2;k<=n;k++)for(int i=1;i<(1<<n);i++){
		f[i][k]=INF;
		for(int j=(i-1)&i;j;j=(j-1)&i)if(f[j][k-1]<INF){
			int d=0;
			for(int w=0;w<n;w++)if(!((1<<w)&j))if((1<<w)&i)d+=D[j][w];
			f[i][k]=min(f[i][k],f[j][k-1]+(k-1)*d);
		}
	}
	for(int k=1;k<=n;k++)ans=min(ans,f[(1<<n)-1][k]);
	printf("%lld\n",ans);
	return 0;
}

