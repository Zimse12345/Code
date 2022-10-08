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
int n,m,hd[N],nxt[N],to[N],ec,pr[N];
int dfn[N],low[N],st[N],top,cl[N],ct,cc,ans;

void add(int u,int v){
	to[++ec]=v,nxt[ec]=hd[u],hd[u]=ec;
	return;
}

void tarjan(int u){
	dfn[u]=low[u]=++ct,st[++top]=u;
	for(int i=hd[u],v;i;i=nxt[i]){
		v=to[i];
		if(!dfn[v])tarjan(v),low[u]=min(low[u],low[v]);
		else if(!cl[v])low[u]=min(low[u],dfn[v]);
	}
	if(dfn[u]==low[u]){
		cl[u]=++cc;
		int tot=1;
		while(st[top]!=u)cl[st[top]]=cc,--top,++tot;
		if(tot>1)++ans;
		--top;
	}
	return;
}

int main(){
	n=read(),m=read();
	for(int i=1,u,v;i<=m;i++)u=read(),v=read(),add(u,v);
	for(int i=1;i<=n;i++)if(!dfn[i])tarjan(i);
	printf("%d\n",ans);
	return 0;
}
