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

const int N=2e3+7,Mod=1e9+7,INF=1e9+7;
int T,n,hd[N],nxt[N],to[N],tag[N],ec,f[N][N];
int C[N][N],cnt[N],g[N],pre[N],ans;
char sig;
inline void add(int u,int v,int t){nxt[++ec]=hd[u],hd[u]=ec,to[ec]=v,tag[ec]=t;return;}

void dp(int u,int from){
	f[u][1]=1,cnt[u]=1;
	for(int e=hd[u],v;e;e=nxt[e]){
		v=to[e];
		if(v==from)continue;
		dp(v,u),pre[cnt[v]+1]=0;
		for(int i=1;i<=cnt[v];i++)pre[i]=(pre[i-1]+f[v][i])%Mod;
		for(int i=1;i<=cnt[u]+cnt[v];i++)g[i]=0;
		if(tag[e]){
			for(int i=1;i<=cnt[u];i++){
				for(int k=i+1;k<=i+cnt[v];k++){
					g[k]=(g[k]+f[u][i]*pre[k-i]%Mod*C[k-1][i-1]%Mod*C[cnt[u]+cnt[v]-k][cnt[u]-i])%Mod;
				}
			}
		}
		else{
			for(int i=1;i<=cnt[u];i++){
				for(int k=i;k<=i+cnt[v]-1;k++){
					g[k]=(g[k]+f[u][i]*(pre[cnt[v]]-pre[k-i]+Mod)%Mod*C[k-1][i-1]%Mod*C[cnt[u]+cnt[v]-k][cnt[u]-i])%Mod;
				}
			}
		}
		cnt[u]+=cnt[v];
		for(int i=1;i<=cnt[u];i++)f[u][i]=g[i];
	}
	return;
}

signed main(){
	for(int i=0;i<N;i++){
		C[i][0]=1;
		if(i)for(int j=1;j<=i;j++)C[i][j]=(C[i-1][j-1]+C[i-1][j])%Mod;
	}
	n=read();
	for(int i=2;i<=n;i++){
		do{sig=getchar();}while(sig!='<'&&sig!='>');
		if(sig=='<')add(i,i-1,0),add(i-1,i,1);
		else add(i,i-1,1),add(i-1,i,0);
	}
	dp(1,0),ans=0;
	for(int i=1;i<=n;i++)ans=(ans+f[1][i])%Mod;
	printf("%lld\n",ans);
	return 0;
}

