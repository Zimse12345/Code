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
int m,hd[N],to[N],nxt[N],ec;
int dfn[N],low[N],ct,cut[N];
ll n,ans[N],siz[N];

void add(int u,int v){
	to[++ec]=v,nxt[ec]=hd[u],hd[u]=ec;
	return;
}

void tarjan(int u){
	dfn[u]=low[u]=++ct,siz[u]=1;
	int tot=0;ll s=0;
	for(int i=hd[u],v;i;i=nxt[i]){
		v=to[i];
		if(!dfn[v]){
			tarjan(v);
			siz[u]+=siz[v];
			low[u]=min(low[u],low[v]);
			if(low[v]>=dfn[u]){
				ans[u]+=siz[v]*(n-siz[v]);
				s+=siz[v],++tot;
				if(u!=1||tot>1)cut[u]=1;
			}
		}
		else low[u]=min(low[u],dfn[v]);
	}
	if(!cut[u])ans[u]=2*(n-1);
	else ans[u]+=(n-s-1)*(s+1)+(n-1);
	return;
}

int main(){
	n=read(),m=read();
	for(int i=1,u,v;i<=m;i++){
		u=read(),v=read();
		add(u,v);
		add(v,u);
	}
	tarjan(1);
	for(int i=1;i<=n;i++)printf("%lld\n",ans[i]);
	return 0;
}

