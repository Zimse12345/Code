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

const int N=4e5+7,Mod=998244353,INF=1e12+7;
int n,hd[N],nxt[N],to[N],c[N],ec;
int f[N],g[N],ans;
inline void add(int u,int v,int w){nxt[++ec]=hd[u],hd[u]=ec,to[ec]=v,c[ec]=w;return;}

void dfs(int u,int from){
	f[u]=0,g[u]=-INF;
	int mx=-INF;
	for(int i=hd[u],v;i;i=nxt[i]){
		v=to[i];
		if(v==from)continue;
		dfs(v,u);
		int d=max(f[v],g[v]+c[i]);
		f[u]+=d;
		mx=max(mx,-d+f[v]+c[i]);
	}
	g[u]=f[u]+mx;
	return;
}

void dp(int u,int from,int F,int G,int fw){
	int sum=max(F,G+fw);
	for(int i=hd[u],v;i;i=nxt[i]){
		v=to[i];
		if(v==from)continue;
		sum+=max(f[v],g[v]+c[i]);
	}
	ans=max(ans,sum);
	int mx=-max(F,G+fw)+F+fw,mxpos=0,se=-INF;
	if(fw==0)mx=-INF;
	for(int i=hd[u],v;i;i=nxt[i]){
		v=to[i];
		if(v==from)continue;
		int d=max(f[v],g[v]+c[i]);
		d=-d+f[v]+c[i];
		if(d>mx)se=mx,mx=d,mxpos=v;
		else if(d>se)se=d;
	}
	for(int i=hd[u],v;i;i=nxt[i]){
		v=to[i];
		if(v==from)continue;
		int _f=sum-max(f[v],g[v]+c[i]);
		if(v==mxpos)dp(v,u,_f,_f+se,c[i]);
		else dp(v,u,_f,_f+mx,c[i]);
	}
	return;
}

signed main(){
	n=read();
	for(int i=1,u,v,w;i<n;i++)u=read(),v=read(),w=read(),add(u,v,w),add(v,u,w);
	dfs(1,0);
	dp(1,0,0,0,0);
	printf("%lld\n",ans);
	return 0;
}

