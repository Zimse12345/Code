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

const int N=1e2+7,Mod=998244353,INF=1e9+7;
int n,m,k,U[N],V[N],P[N],v[N],hd[N],nxt[N],to[N],ec,vis[N],sz,ans;
inline int qp(int x,int k){int res=1;while(k){if(k&1ll)res=(res*x)%Mod;x=(x*x)%Mod,k/=2;}return res;}
inline int inv(int x){return qp(x,Mod-2);}
inline void add(int u,int v){nxt[++ec]=hd[u],hd[u]=ec,to[ec]=v;return;}

void dfs(int u){
	if(vis[u]++)return;
	sz+=v[u];
	for(int i=hd[u];i;i=nxt[i])dfs(to[i]);
	return;
}

signed main(){
	n=read(),k=read(),m=n-1;
	for(int i=1;i<=n;i++)v[i]=read();
	for(int i=0,a,b;i<m;i++){
		U[i]=read(),V[i]=read();
		a=read(),b=read();
		P[i]=(a*inv(b))%Mod;
	}
	for(int i=0;i<(1<<m);i++){
		int p=1;
		for(int j=1;j<=n*2;j++)hd[j]=nxt[j]=to[j]=vis[j]=0;ec=0;
		for(int j=0;j<m;j++){
			if(i&(1<<j))add(U[j],V[j]),add(V[j],U[j]),p=(p*P[j])%Mod;
			else p=(p*(1-P[j]))%Mod;
		}
		for(int j=1;j<=n;j++)if(!vis[j]){
			sz=0,dfs(j);
			ans=(ans+p*qp(sz,k))%Mod;
		}
	}
	printf("%lld\n",ans);
	return 0;
}

