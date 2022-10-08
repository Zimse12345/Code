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

const int N=5e5+7,Mod=998244353,INF=1e9+7;
int n,cl[N],hd[N],nxt[N],to[N],c[N],ec,mx[N],se[N],ans;
inline void add(int u,int v){nxt[++ec]=hd[u],hd[u]=ec,to[ec]=v;return;}

void dfs(int u,int from){
	for(int i=hd[u],v;i;i=nxt[i]){
		v=to[i];
		if(v==from)continue;
		dfs(v,u);
		if(cl[u]^cl[v])c[v]=1;
		if(mx[v]+c[v]>=mx[u])se[u]=mx[u],mx[u]=mx[v]+c[v];
		else if(mx[v]+c[v]>se[u])se[u]=mx[v]+c[v];
	}
	ans=max(ans,mx[u]+se[u]);
	return;
}

signed main(){
	n=read();
	for(int i=1;i<=n;i++)cl[i]=read();
	for(int i=1,u,v;i<n;i++)u=read(),v=read(),add(u,v),add(v,u);
	dfs(1,0);
	ans=(ans+1)/2;
	printf("%d\n",ans);
	return 0;
}

