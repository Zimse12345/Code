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

const int N=1e2+7,Mod=998244353,INF=1e9+7;
int n,m,a[N][3],k,ff[N][20],f[N][N][20],vis[N][N];

void dp(int x,int y){
	if(vis[x][y]++)return;
	for(int i=1;i<=k;i++)f[x][y][i]=-INF;
	if(x!=0){
		dp(x-1,y);
		for(int i=0;i<=k;i++)f[x][y][i]=max(f[x][y][i],f[x-1][y][i]);
	}
	if(y!=0){
		dp(x,y-1);
		for(int i=0;i<=k;i++)f[x][y][i]=max(f[x][y][i],f[x][y-1][i]);
	}
	for(int i=x,s=0;i>=1;i--){
		s+=a[i][1];
		dp(i-1,y);
		for(int j=1;j<=k;j++)f[x][y][j]=max(f[x][y][j],f[i-1][y][j-1]+s);
	}
	for(int i=y,s=0;i>=1;i--){
		s+=a[i][2];
		dp(x,i-1);
		for(int j=1;j<=k;j++)f[x][y][j]=max(f[x][y][j],f[x][i-1][j-1]+s);
	}
	if(x==y){
		for(int i=x,s=0;i>=1;i--){
			s+=a[i][1]+a[i][2];
			dp(i-1,i-1);
			for(int j=1;j<=k;j++)f[x][y][j]=max(f[x][y][j],f[i-1][i-1][j-1]+s);
		}
	}
	return;
}

signed main(){
	n=read(),m=read(),k=read();
	for(int i=1;i<=n;i++)for(int j=1;j<=m;j++)a[i][j]=read();
	if(m==1){
		for(int i=1;i<=n;i++){
			for(int j=0;j<=k;j++)ff[i][j]=ff[i-1][j];
			for(int j=i,s=0;j>=1;j--){
				s+=a[j][1];
				for(int p=1;p<=k;p++)ff[i][p]=max(ff[i][p],ff[j-1][p-1]+s);
			}
		}
		printf("%lld\n",ff[n][k]);
		return 0;
	}
	dp(n,n);
	printf("%lld\n",f[n][n][k]);
	return 0;
}

