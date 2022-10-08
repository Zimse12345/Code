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

const int N=4e3+20,M=2e3+10,Mod=998244353,INF=1e9+7;
int T,n,hd[N],nxt[N],to[N],ec;
int f[2200][N][2][2],sz[N];
int g[N][2][2],ans;
void add(int u,int v){nxt[++ec]=hd[u],hd[u]=ec,to[ec]=v;return;}

void dp(int u,int from){
	f[u][0+M][0][0]=f[u][1+M][1][1]=1,sz[u]=1;
	for(int i=hd[u],v;i;i=nxt[i]){
		v=to[i];
		if(v==from)continue;
		dp(v,u);
		for(int a=-sz[u]-sz[v];a<=sz[u]+sz[v];a++)for(int t1=0;t1<2;t1++)for(int t2=0;t2<2;t2++)g[a+M][t1][t2]=0;
		for(int a=-sz[u];a<=sz[u];a++){
			for(int b=-sz[v];b<=sz[v];b++){
				(g[a+b+M][1][1]+=f[u][a+M][1][1]*f[v][b+M][1][1])%=Mod;
				(g[a+b-2+M][1][1]+=f[u][a+M][1][1]*f[v][b+M][0][1])%=Mod;
				(g[a+M][1][1]+=f[u][a+M][1][1]*f[v][b+M][0][0])%=Mod;
				(g[a+b-2+M][0][1]+=f[u][a+M][0][1]*f[v][b+M][1][1])%=Mod;
				(g[a+b-2+M][0][1]+=f[u][a+M][0][1]*f[v][b+M][0][1])%=Mod;
				(g[a+M][0][1]+=f[u][a+M][0][1]*f[v][b+M][0][0])%=Mod;
				(g[b+M][0][1]+=f[u][a+M][0][0]*f[v][b+M][1][1])%=Mod;
				(g[b+M][0][1]+=f[u][a+M][0][0]*f[v][b+M][0][1])%=Mod;
				(g[0+M][0][0]+=f[u][a+M][0][0]*f[v][b+M][0][0])%=Mod;
			}
		}
		sz[u]+=sz[v];
		for(int a=-sz[u];a<=sz[u];a++)for(int t1=0;t1<2;t1++)for(int t2=0;t2<2;t2++){
			f[u][a+M][t1][t2]=g[a+M][t1][t2];
		}
	}
	return;
}

signed main(){
	T=read();
	while(T--){
		n=read(),ans=0;
		for(int i=1,x,y;i<n;i++)x=read(),y=read(),add(x,y),add(y,x);
		dp(1,0);
		for(int i=-n;i<0;i++)for(int t1=0;t1<2;t1++)for(int t2=0;t2<2;t2++)ans-=i*f[1][i+M][t1][t2],ans%=Mod;
		for(int i=1;i<=n;i++){
			for(int j=-sz[i];j<=sz[i];j++){
				for(int t1=0;t1<2;t1++)for(int t2=0;t2<2;t2++)f[i][j+M][t1][t2]=0;
			}
			hd[i]=0;
		}
		for(int i=1;i<=ec;i++)to[i]=nxt[i]=0;
		ec=0;
		ans=(ans*2)%Mod;
		printf("%lld\n",(ans+Mod)%Mod);
	}
	return 0;
}

