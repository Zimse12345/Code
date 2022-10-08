#include <cstdio>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <queue>
#include <bitset>
#include <ctime>

#define int long long
using namespace std;

int read(){int qrx=0,qry=1;char qrc=getchar();
while(qrc<'0'||qrc>'9'){if(qrc=='-')qry=-1;qrc=getchar();}
while('0'<=qrc&&qrc<='9')qrx=qrx*10+qrc-'0',qrc=getchar();return qrx*qry;}

const int N=1e3+7,Mod=1e9+7;
int n,k,hd[N],nxt[N*2],to[N*2],ec,sz[N];
int f[1005][5005][6],t[5005][6],ans[5005];
int f1[N],f0[N];
inline void add(int u,int v){nxt[++ec]=hd[u],hd[u]=ec,to[ec]=v;return;}

void dfs(int u,int from){
	sz[u]=1;
	for(int i=1;i<=k;i++)f[u][0][i]=1;
	for(int i=hd[u],v;i;i=nxt[i]){
		v=to[i];
		if(v==from)continue;
		dfs(v,u);
		for(int a0=0;a0<=sz[u]*k;a0++){
			for(int a1=0;a1<=k;a1++)if(f[u][a0][a1]){
				for(int b0=0;b0<=sz[v]*k;b0++){
					for(int b1=0,a,b;b1<=k;b1++)if(f[v][b0][b1]){
						a=a0+b0+b1,b=a0+a1+b0;
						(t[a][max(a,b)-a]+=f[u][a0][a1]*f[v][b0][b1])%=Mod;
					}
				}
			}
		}
		sz[u]+=sz[v];
		for(int a=0;a<=sz[u]*k;a++){
			for(int b=0;b<=k;b++){
				f[u][a][b]=t[a][b],t[a][b]=0;
			}
		}
	}
	return;
}

void dfs2(int u,int from){
	f1[u]=1;
	for(int i=hd[u],v;i;i=nxt[i]){
		v=to[i];
		if(v==from)continue;
		dfs2(v,u);
		f1[u]+=f0[v];
		f0[u]+=max(f0[v],f1[v]);
	}
	return;
}

signed main(){
	n=read(),k=read();
	for(int i=1,u,v;i<n;i++)u=read(),v=read(),add(u,v),add(v,u);
	if(k==1){
		dfs2(1,0);
		int mx=max(f1[1],f0[1]);
		ans[mx]++;
		for(int i=1;i<=n*k;i++){
			printf("%lld\n",ans[i]);
		}
		return 0;
	}
	dfs(n/2,0);
	for(int a=0;a<=n*k;a++){
		for(int b=0;b<=k;b++){
			(ans[a+b]+=f[n/2][a][b])%=Mod;
		}
	}
	
	for(int i=1;i<=n*k;i++){
		printf("%lld\n",ans[i]);
	}
	return 0;
}

