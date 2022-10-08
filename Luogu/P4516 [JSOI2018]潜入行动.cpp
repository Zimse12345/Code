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

int read(){int qrx=0,qry=1;char qrc=getchar();
while(qrc<'0'||qrc>'9'){if(qrc=='-'){qry=-1,qrc=getchar();}else qrc=getchar();}
while(qrc>='0'&&qrc<='9')qrx=qrx*10+qrc-48,qrc=getchar();return qrx*qry;}

const int N=2e5+7,Mod=1e9+7,INF=2147483647;
int n,k,hd[N],nxt[N],to[N],ec,sz[N];
int f[100007][107][2][2],g[107][2][2];
inline void addeg(int u,int v){to[++ec]=v,nxt[ec]=hd[u],hd[u]=ec;return;}
inline void add(int& x,long long y){x=(1ll*x+y)%Mod;return;}

void dp(int u,int from){
	f[u][0][0][0]=f[u][1][1][0]=1,sz[u]=1;
	for(int i=hd[u],v;i;i=nxt[i]){
		v=to[i];
		if(v==from)continue;
		dp(v,u);
		for(int j=0;j<=k;j++)g[j][0][0]=g[j][0][1]=g[j][1][0]=g[j][1][1]=0;
		
		for(int a=0;a<=min(k,sz[u]);a++)for(int b=0;a+b<=k&&b<=sz[v];b++){
			add(g[a+b][1][1],1ll*f[u][a][1][0]*(1ll*f[v][b][1][0]+f[v][b][1][1])+1ll*f[u][a][1][1]*(1ll*f[v][b][0][0]+f[v][b][0][1]+f[v][b][1][0]+f[v][b][1][1]));
			add(g[a+b][0][1],1ll*f[u][a][0][0]*f[v][b][1][1]+1ll*f[u][a][0][1]*(1ll*f[v][b][0][1]+f[v][b][1][1]));
			add(g[a+b][1][0],1ll*f[u][a][1][0]*(1ll*f[v][b][0][0]+f[v][b][0][1]));
			add(g[a+b][0][0],1ll*f[u][a][0][0]*f[v][b][0][1]);
		}
		
		for(int j=0;j<=k;j++)for(int t1=0;t1<=1;t1++)for(int t2=0;t2<=1;t2++)f[u][j][t1][t2]=g[j][t1][t2];
		sz[u]+=sz[v];
	}
	return;
}

int main(){
	n=read(),k=read();
	for(int i=1,u,v;i<n;i++)u=read(),v=read(),addeg(u,v),addeg(v,u);
	dp(1,0);
	printf("%d\n",(f[1][k][0][1]+f[1][k][1][1])%Mod);
	return 0;
}

