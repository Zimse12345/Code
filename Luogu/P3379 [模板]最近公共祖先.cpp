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

const int N=1e6+7,INF=1e9+7;
int n,m,s;
int fa[N],cnt[N],dfn[N],dep[N],top[N],hv[N],ct;
vector<int> g[N],ch[N];

void dfs1(int u,int pr,int d){
	dep[u]=d,dfn[u]=++ct,fa[u]=pr,cnt[u]=1;
	for(int i=0;i<int(g[u].size());i++){
		int v=g[u][i];
		if(v==pr)continue;
		dfs1(v,u,d+1);
		cnt[u]+=cnt[v];
		ch[u].push_back(v);
		if(cnt[hv[u]]<cnt[v])hv[u]=v;
	}
	return;
}

void dfs2(int u,int pr){
	top[u]=pr;
	if(hv[u])dfs2(hv[u],pr);
	for(int i=0;i<int(ch[u].size());i++){
		int v=ch[u][i];
		if(v==hv[u])continue;
		dfs2(v,v);
	}
	return;
}

int main(){
	n=read(),m=read(),s=read();
	for(int i=1;i<n;i++){
		int u=read(),v=read();
		g[u].push_back(v);
		g[v].push_back(u);
	}
	dfs1(s,s,0),dfs2(s,s);
	for(int i=1;i<=m;i++){
		int u=read(),v=read();
		while(top[u]!=top[v]){
			if(dep[top[u]]<=dep[top[v]])v=fa[top[v]];
			else u=fa[top[u]];
		}
		if(dep[u]>dep[v]){int T=u;u=v,v=T;}
		printf("%d\n",u);
	}
	return 0;
}
