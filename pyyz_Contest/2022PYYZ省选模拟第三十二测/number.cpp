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

inline int read(){int qrx=0,qry=1;char qrc=getchar();
while(qrc<'0'||qrc>'9'){if(qrc=='-'){qry=-1,qrc=getchar();}else qrc=getchar();}
while(qrc>='0'&&qrc<='9')qrx=qrx*10+qrc-48,qrc=getchar();return qrx*qry;}

const int N=2e4+7,Mod=998244353,INF=1e9+7;
int n,K,hd[N],nxt[N],to[N],ec,ans,prime[N*100],pr[N*100],tot;
int P,dp[N][40][40],c,f[40][40],g[N][40],b[2][N*100];
inline void add(int u,int v){nxt[++ec]=hd[u],hd[u]=ec,to[ec]=v;return;}

void dfs(int u,int from){
	for(int i=0;i<=c;i++)for(int j=0;j<=c;j++)dp[u][i][j]=0;
	for(int i=0;i<=c;i++)dp[u][i][i]=1;
	for(int i=hd[u],v;i;i=nxt[i]){
		v=to[i];
		if(v==from)continue;
		dfs(v,u);
		for(int x=0;x<=c;x++)for(int y=0;y<=c;y++)f[x][y]=0;
		for(int x=0;x<=c;x++){
			for(int y=0;y<=x;y++){
				for(int z=0;z+x<=c;z++){
					for(int w=0;w<=min(z,y);w++){
						(f[x+z][y]+=dp[u][x][y]*dp[v][z][w])%=Mod;
					}
				}
			}
		}
		for(int x=0;x<=c;x++)for(int y=0;y<=c;y++)dp[u][x][y]=f[x][y];
	}
	return;
}

signed main(){
	n=read(),K=read();
	for(int i=1,u,v;i<n;i++)u=read(),v=read(),add(u,v),add(v,u);
	if(n==1){
		printf("%lld\n",K);
		return 0;
	}
	if(n==2){
		for(int l=1,r;l<=K;){
			r=K/(K/l);
			(ans+=(r-l+1)*(K/l))%=Mod;
			l=r+1;
		}
		printf("%lld\n",ans);
		return 0;
	}
	for(int i=2;i<N*100;i++){
		if(!pr[i])pr[i]=i,prime[++tot]=i;
		for(int j=1;j<=tot&&prime[j]*i<N*100;j++){
			pr[prime[j]*i]=prime[j];
			if(pr[i]==prime[j])break;
		}
	}
	int k=0;
	for(int i=2;i*i<=K;i++)if(pr[i]==i){
		P=i,c=0,++k;
		int pp=P;
		while(pp<=K)pp*=i,++c;
		dfs(1,0);
		for(int x=0;x<=c;x++){
			for(int y=0;y<=x;y++)g[k][x]+=dp[1][x][y];
		}
//		for(int j=0;j<=c;j++)printf("(%lld %lld %lld)\n",prime[k],j,g[k][j]);
	}
	int T=0;
	b[T][1]=1;
	for(int i=1;i<=k;i++){
		T^=1;
		for(int j=0;j<=K;j++)b[T][j]=b[T^1][j];
		int v=1;
		for(int j=1;v*prime[i]<=K;j++){
			v*=prime[i];
//			printf("(%lld %lld)\n",v,g[i][j]);
			for(int u=1;u*v<=K;u++)b[T][u*v]=(b[T][u*v]+b[T^1][u]*g[i][j])%Mod;
		}
	}
	for(int i=1;i<=K;i++)ans=(ans+b[T][i])%Mod,b[T][i]+=b[T][i-1];
	for(int i=1;i<=K;i++)if(i*i>K&&pr[i]==i){
		ans=(ans+b[T][K/i])%Mod;
	}
	printf("%lld\n",ans);
	return 0;
}

