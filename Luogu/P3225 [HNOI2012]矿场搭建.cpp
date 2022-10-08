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

int read(){int qrx=0,qry=1;char qrc=getchar();
while(qrc<'0'||qrc>'9'){if(qrc=='-'){qry=-1,qrc=getchar();}else qrc=getchar();}
while(qrc>='0'&&qrc<='9')qrx=qrx*10+qrc-48,qrc=getchar();return qrx*qry;}

const int N=1e4+7,Mod=998244353,INF=2147483647;
int n=1e3,m,hd[N],to[N],nxt[N],ec,cut[N];
int dfn[N],low[N],ct,rc,vis[N],c1,c2,nd,T,tag;
ll ans;
inline void add(int u,int v){to[++ec]=v,nxt[ec]=hd[u],hd[u]=ec;return;}

void tarjan(int u,int from){
	dfn[u]=low[u]=++ct;
	for(int i=hd[u],v;i;i=nxt[i]){
		v=to[i];
		if(!dfn[v]){
			tarjan(v,from),low[u]=min(low[u],low[v]);
			if(low[v]>=dfn[u]&&u!=from)cut[u]=1;
			if(u==from)++rc;
		}
		low[u]=min(low[u],dfn[v]);
	}
	if(u==from&&rc>1)cut[u]=1;
	return;
}

void dfs(int u){
	if(vis[u]==tag)return;
	vis[u]=tag;
	if(cut[u]){++c2;return;}
	++c1;
	for(int i=hd[u];i;i=nxt[i])dfs(to[i]);
	return;
}

int main(){
	while(1){
		m=read(),ct=nd=0,ans=1,++T;
		if(!m)break;
		while(ec)to[ec]=nxt[ec]=0,--ec;
		for(int i=1;i<=n;i++)hd[i]=cut[i]=dfn[i]=low[i]=vis[i]=0;
		for(int i=1,u,v;i<=m;i++)u=read(),v=read(),add(u,v),add(v,u);
		for(int i=1;i<=n;i++)if(!dfn[i])rc=0,tarjan(i,i);
		for(int i=1;i<=n;i++)if(!(vis[i]||cut[i]||(!hd[i]))){
			c1=0,c2=0,++tag;
			dfs(i);
			if(c2==0)nd+=2,ans=(ans*(c1*(c1-1)/2));
			if(c2==1)nd+=1,ans=(ans*c1);
		}
		printf("Case %d: %d %lld\n",T,nd,ans);
	}
	return 0;
}

