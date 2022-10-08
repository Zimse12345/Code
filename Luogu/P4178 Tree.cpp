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

using namespace std;

inline int read(){ll qrx=0,qry=1;char qrc=getchar();
while(qrc<'0'||qrc>'9'){if(qrc=='-'){qry=-1,qrc=getchar();}else qrc=getchar();}
while(qrc>='0'&&qrc<='9')qrx=qrx*10+qrc-48,qrc=getchar();return qrx*qry;}
inline void write(int x){if(x<0){putchar('-'),x=-x;}if(x>9)write(x/10);putchar(x%10+'0');}

const int N=2e5,INF=1e9+7;
int n,k,hd[N],to[N],c[N],nxt[N],ec;
int vis[N],cnt[N],rt,mx,ts;
int dis[N],dt,ds[N],ct[N],t;
ll ans;

void add(int u,int v,int w){
	to[++ec]=v,c[ec]=w,nxt[ec]=hd[u],hd[u]=ec;
	return;
}

void findrt(int u,int from){
	cnt[u]=1;
	int ms=0;
	for(int i=hd[u],v;i;i=nxt[i]){
		v=to[i];
		if(v==from||vis[v])continue;
		findrt(v,u),cnt[u]+=cnt[v];
		ms=max(ms,cnt[v]);
	}
	ms=max(ms,ts-cnt[u]);
	if(ms<mx)mx=ms,rt=u;
	return;
}

void getdis(int u,int from,int d){
	dis[++dt]=d;
	for(int i=hd[u],v;i;i=nxt[i]){
		v=to[i];
		if(v==from||vis[v])continue;
		getdis(v,u,d+c[i]);
	}
	return;
}

void solve(int u,int w,int T){
	t=dt=0,dis[0]=-1,getdis(u,0,w);
	sort(dis+1,dis+dt+1);
	for(int i=1;i<=dt;i++)if(dis[i]*2<=k)ans-=T;
	for(int i=1;i<=dt;i++){
		if(dis[i]!=dis[i-1])ds[++t]=dis[i],ct[t]=1;
		else ++ct[t];
	}
	for(int R=t,L=1,s=0;R>=1;R--){
		while(L<=t&&ds[R]+ds[L]<=k)s+=ct[L++];
		ans+=1ll*s*ct[R]*T;
	}
	return;
}

void divide(int u){
	vis[u]=1;
	solve(u,0,1);
	for(int i=hd[u],v;i;i=nxt[i]){
		v=to[i];
		if(vis[v])continue;
		solve(v,c[i],-1);
		ts=cnt[v],mx=INF,rt=0,findrt(v,0);
		divide(rt);
	}
	return;
}

int main(){
	n=read();
	for(int i=1,u,v,w;i<n;i++)u=read(),v=read(),w=read(),add(u,v,w),add(v,u,w);
	k=read();
	ts=n,mx=INF,findrt(1,0);
	divide(rt);
	printf("%lld\n",ans/2ll);
	return 0;
}

