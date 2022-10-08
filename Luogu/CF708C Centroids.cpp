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

const int N=1e6+7,Mod=998244353,INF=1e9+7;
int n,hd[N],nxt[N],to[N],ec,f[N];
int fa[N],cnt[N],mxson[N];
inline void add(int u,int v){to[++ec]=v,nxt[ec]=hd[u],hd[u]=ec;return;}

void dfs1(int u,int from){
	fa[u]=from,cnt[u]=1;
	for(int i=hd[u],v;i;i=nxt[i]){
		v=to[i];
		if(v==from)continue;
		dfs1(v,u),cnt[u]+=cnt[v];
		if(mxson[v]>mxson[u])mxson[u]=mxson[v];
		if(cnt[v]<=n/2&&cnt[v]>mxson[u])mxson[u]=cnt[v];
	}
	return;
}

void dfs2(int u,int from,int famx){
	for(int i=hd[u],v;i;i=nxt[i]){
		v=to[i];
		if(v==from)continue;
		if(cnt[v]-mxson[v]>n/2)f[u]=1;
	}
	if(n-cnt[u]-famx>n/2)f[u]=1;
	
	int m1=famx,m2=famx,mp=0;
	for(int i=hd[u],v;i;i=nxt[i]){
		v=to[i];
		if(v==from)continue;
		int m=mxson[v];
		if(cnt[v]<=n/2)m=cnt[v];
		if(m>=m1)m2=m1,m1=m,mp=v;
		else if(m>m2)m2=m;
	}
	for(int i=hd[u],v;i;i=nxt[i]){
		v=to[i];
		if(v==from)continue;
		int fw=m1;
		if(v==mp)fw=m2;
		if(n-cnt[v]<=n/2)fw=n-cnt[v];
		dfs2(v,u,fw);
	}
	return;
}

signed main(){
	n=read();
	for(int i=1,u,v;i<n;i++)u=read(),v=read(),add(u,v),add(v,u);
	dfs1(1,0),dfs2(1,0,0);
	for(int i=1;i<=n;i++)printf("%d ",f[i]^1);
	printf("\n");
	return 0;
}

