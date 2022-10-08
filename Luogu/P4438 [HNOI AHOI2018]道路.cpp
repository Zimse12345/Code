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
#define Lid ch[u][0]
#define Rid ch[u][1]

using namespace std;

int read(){int qrx=0,qry=1;char qrc=getchar();
while(qrc<'0'||qrc>'9'){if(qrc=='-'){qry=-1,qrc=getchar();}else qrc=getchar();}
while(qrc>='0'&&qrc<='9')qrx=qrx*10+qrc-48,qrc=getchar();return qrx*qry;}

const int N=4e4+7,Mod=998244353,INF=1e9+7;
int n,ch[N][2];
ll a[N],b[N],c[N],f[100][100][100];

void dp(int p,int u,int x,int y){
	for(int i=0;i<100;i++)for(int j=0;j<100;j++)f[p][i][j]=INF;
	if(u>=n){
		for(int i=0;i<=x;i++)for(int j=0;j<=y;j++)f[p][i][j]=c[u]*(a[u]+i)*(b[u]+j);
		return;
	}
	int lc=p+1,rc=p+2;
	dp(lc,Lid,x+1,y),dp(rc,Rid,x,y+1);
	for(int i=0;i<=x;i++)for(int j=0;j<=y;j++)f[p][i][j]=min(f[lc][i][j]+f[rc][i][j+1],f[lc][i+1][j]+f[rc][i][j]);
	return;
}

signed main(){
	n=read();
	for(int i=1,x,y;i<n;i++){
		x=read(),y=read();
		if(x<0)x=n-x-1;
		if(y<0)y=n-y-1;
		ch[i][0]=x,ch[i][1]=y;
	}
	for(int i=n;i<n*2;i++)a[i]=read(),b[i]=read(),c[i]=read();
	dp(1,1,0,0);
	printf("%lld\n",f[1][0][0]);
	return 0;
}

