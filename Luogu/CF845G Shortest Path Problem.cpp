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

const int N=2e5+7,Mod=998244353,INF=1e9+7;
int n,m,d[100];
int hd[N],nxt[N],to[N],c[N],ec,dis[N],vis[N];
inline void add(int u,int v,int w){nxt[++ec]=hd[u],hd[u]=ec,to[ec]=v,c[ec]=w;return;}

void ins(int x){
	for(int i=61;i>=0;i--)if(x&(1ll<<i)){
		if(!d[i]){
			d[i]=x;
			return;
		}
		x^=d[i];
	}
	return;
}

void dfs(int u){
	vis[u]=1;
	for(int i=hd[u],v;i;i=nxt[i]){
		v=to[i];
		if(vis[v])ins(c[i]^dis[u]^dis[v]);
		else dis[v]=dis[u]^c[i],dfs(v);
	}
	return;
}

signed main(){
	n=read(),m=read();
	for(int i=1,u,v,w;i<=m;i++)u=read(),v=read(),w=read(),add(u,v,w),add(v,u,w);
	dfs(1);
	int ans=dis[n];
	for(int i=61;i>=0;i--)if((ans^d[i])<ans)ans^=d[i];
	printf("%lld\n",ans);
	return 0;
}

