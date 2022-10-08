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

int read(){int qrx=0,qry=1;char qrc=getchar();
while(qrc<'0'||qrc>'9'){if(qrc=='-'){qry=-1,qrc=getchar();}else qrc=getchar();}
while(qrc>='0'&&qrc<='9')qrx=qrx*10+qrc-48,qrc=getchar();return qrx*qry;}

const int N=1e5+7,Mod=998244353,INF=1e9+7;
int T,n,m,vis[N],ans;
int hd[N],nxt[N],to[N],cost[N],len[N],ec;
int cnt[N],mx,rt,sz;
int D[N],C[N],dt;
int p[N],t,tr[31000000];
inline void add(int u,int v,int c,int w){nxt[++ec]=hd[u],hd[u]=ec,to[ec]=v,cost[ec]=c,len[ec]=w;}

inline void ub(int& x){x+=(x&(-x));return;}
inline void db(int& x){x-=(x&(-x));return;}
inline void update(int x,int y){for(;x<=min(m,n*1000);ub(x))tr[x]=max(tr[x],y);return;}
inline int query(int x){int res=0;for(;x;db(x))res=max(res,tr[x]);return res;}
inline void cl(int x){for(;x<=min(m,n*1000);ub(x))tr[x]=0;}

void findrt(int u,int from){
	cnt[u]=1;
	int ms=0;
	for(int i=hd[u],v;i;i=nxt[i]){
		v=to[i];
		if(vis[v]||v==from)continue;
		findrt(v,u),cnt[u]+=cnt[v];
		ms=max(ms,cnt[v]);
	}
	ms=max(ms,n-cnt[u]);
	if(ms<mx)mx=ms,rt=u;
	return;
}

void dfs(int u,int from,int fc,int fd){
	D[++dt]=fd,C[dt]=fc;
	for(int i=hd[u],v;i;i=nxt[i]){
		v=to[i];
		if(vis[v]||v==from)continue;
		dfs(v,u,fc+cost[i],fd+len[i]);
	}
	return;
}

void clac(int u){
	t=0;
	for(int i=hd[u],v;i;i=nxt[i]){
		v=to[i];
		if(vis[v])continue;
		dt=0,dfs(v,u,cost[i],len[i]);
		for(int i=1;i<=dt;i++)if(C[i]<=m)ans=max(ans,D[i]+query(m-C[i]));
		for(int i=1;i<=dt;i++)update(C[i],D[i]),p[++t]=C[i];
	}
	for(int i=1;i<=t;i++)cl(p[i]);
	return;
}

void sol(int u){
	vis[u]=1,clac(u);
	for(int i=hd[u],v;i;i=nxt[i]){
		v=to[i];
		if(vis[v])continue;
		mx=INF,rt=0,sz=cnt[v],findrt(v,u);
		sol(rt);
	}
	return;
}

signed main(){
	T=read();
	int ct=0;
	while(T--){
		n=read(),m=read(),ans=0;
		for(int i=1,u,v,c,w;i<n;i++)u=read(),v=read(),c=read(),w=read(),add(u,v,c,w),add(v,u,c,w);
		
		mx=INF,rt=0,sz=n,findrt(1,0);
		sol(rt);
		printf("Case %d: %d\n",++ct,ans);
		
		while(ec)nxt[ec--]=0;
		for(int i=1;i<=n;i++)hd[i]=vis[i]=0;
	}
	return 0;
}

