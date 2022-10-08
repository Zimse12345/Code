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

//#define ll long long

using namespace std;

inline int read(){int qrx=0,qry=1;char qrc=getchar();
while(qrc<'0'||qrc>'9'){if(qrc=='-'){qry=-1,qrc=getchar();}else qrc=getchar();}
while(qrc>='0'&&qrc<='9')qrx=qrx*10+qrc-48,qrc=getchar();return qrx*qry;}
inline void write(int x){if(x<0){putchar('-'),x=-x;}if(x>9)write(x/10);putchar(x%10+'0');}

const int N=4e5+7,INF=1e9+7;
struct node{int x,y;node(int x=0,int y=0):x(x),y(y){}
bool operator < (const node& A)const{return x<A.x;}}dis[N];
int n,k,ans=INF,hd[N],to[N],c[N],nxt[N],ec;
int vis[N],cnt[N],rt,mx,ts,dt,mi[N*10];

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

void getdis(int u,int from,int d,int le){
	if(d>k||le>=ans)return;
	dis[++dt]=node(d,le);
	for(int i=hd[u],v;i;i=nxt[i]){
		v=to[i];
		if(v==from||vis[v])continue;
		getdis(v,u,d+c[i],le+1);
	}
	return;
}

void solve(int u){
	dt=0,mi[0]=0;
	for(int i=hd[u],v;i;i=nxt[i]){
		v=to[i];
		if(vis[v])continue;
		int pt=dt;
		getdis(v,u,c[i],1);
		for(int j=pt+1;j<=dt;j++)ans=min(ans,mi[k-dis[j].x]+dis[j].y);
		for(int j=pt+1;j<=dt;j++)mi[dis[j].x]=min(mi[dis[j].x],dis[j].y);
	}
	for(int i=1;i<=dt;i++)mi[dis[i].x]=INF;
	return;
}

void divide(int u){
	vis[u]=1;
	solve(u);
	for(int i=hd[u],v;i;i=nxt[i]){
		v=to[i];
		if(vis[v])continue;
		ts=cnt[v],mx=INF,rt=0,findrt(v,0);
		divide(rt);
	}
	return;
}

signed main(){
	n=read(),k=read();
	for(int i=1;i<=k;i++)mi[i]=INF;
	for(int i=1,u,v,w;i<n;i++)u=read()+1,v=read()+1,w=read(),add(u,v,w),add(v,u,w);
	ts=n,mx=INF,findrt(1,0);
	divide(rt);
	if(ans>n)ans=-1;
	printf("%d\n",ans);
	return 0;
}
