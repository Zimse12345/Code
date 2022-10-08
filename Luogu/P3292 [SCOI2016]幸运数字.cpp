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
#define ull unsigned long long

using namespace std;

ll read(){ll qrx=0,qry=1;char qrc=getchar();
while(qrc<'0'||qrc>'9'){if(qrc=='-'){qry=-1,qrc=getchar();}else qrc=getchar();}
while(qrc>='0'&&qrc<='9')qrx=qrx*10+qrc-48,qrc=getchar();return qrx*qry;}

const int N=2e4+7,Mod=998244353,INF=1e9+7;
int n,q,fa[N][16],dep[N];
int hd[N],nxt[N*2],to[N*2],ec,_2[N];
ll g[N];
inline void add(int u,int v){nxt[++ec]=hd[u],hd[u]=ec,to[ec]=v;return;}

struct node{
	ll d[61];
	void ins(ll x){
		for(ll i=60;i>=0;i--)if(x&(1ll<<i)){
			if(!d[i]){d[i]=x;return;}
			x^=d[i];
		}
		return;
	}
}p[N][16];

node merge(node x,node y){
	for(int i=0;i<=60;i++)if(y.d[i])x.ins(y.d[i]);
	return x;
}

void dfs(int u,int from,int d){
	fa[u][0]=from,dep[u]=d;
	for(int i=hd[u],v;i;i=nxt[i]){
		v=to[i];
		if(v==from)continue;
		dfs(v,u,d+1);
	}
	return;
}

int LCA(int x,int y){
	if(x==y)return x;
	if(dep[x]<dep[y])swap(x,y);
	for(int i=15;i>=0;i--)if(dep[fa[x][i]]>=dep[y])x=fa[x][i];
	if(x==y)return x; 
	for(int i=15;i>=0;i--)if(fa[x][i]^fa[y][i])x=fa[x][i],y=fa[y][i];
	return fa[x][0];
}

int fr(int x,int y){
	for(int i=15;i>=0;i--)if(y&(1<<i))x=fa[x][i];
	return x;
}

signed main(){
	n=read(),q=read();
	for(int i=2;i<=n;i++)_2[i]=_2[i>>1]+1;
	for(int i=1;i<=n;i++)g[i]=read(),p[i][0].ins(g[i]);
	for(int i=1,u,v;i<n;i++)u=read(),v=read(),add(u,v),add(v,u);
	dfs(1,0,1);
	for(int i=1;i<=15;i++){
		for(int j=1;j<=n;j++){
			fa[j][i]=fa[fa[j][i-1]][i-1];
			p[j][i]=merge(p[j][i-1],p[fa[j][i-1]][i-1]);
		}
	}
	while(q--){
		int x=read(),y=read(),dis,t,lca=LCA(x,y);
		ll ans=0;
		dis=dep[x]-dep[lca]+1,t=_2[dis];
		node A=merge(p[x][t],p[fr(x,dis-(1<<t))][t]);
		dis=dep[y]-dep[lca]+1,t=_2[dis];
		node B=merge(p[y][t],p[fr(y,dis-(1<<t))][t]);
		node a=merge(A,B);
		for(int i=60;i>=0;i--)if((ans^a.d[i])>ans)ans^=a.d[i];
		printf("%lld\n",ans);
	}
	return 0;
}

