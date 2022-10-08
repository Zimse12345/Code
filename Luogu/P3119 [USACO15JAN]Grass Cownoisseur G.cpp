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

const int N=4e5+7,Mod=998244353,INF=1e9+7;
int n,m,dfn[N],low[N],cl[N],ins[N],st[N],top,ct,c,cnt[N],f[N],vis[N],dis[N]; 
vector<int> g[N],G[N];
queue<int> q;

void tarjan(int u){
	dfn[u]=low[u]=++ct,st[++top]=u,ins[u]=1;
	for(int i=0,v;i<int(g[u].size());i++){
		v=g[u][i];
		if(!dfn[v])tarjan(v),low[u]=min(low[u],low[v]);
		else if(ins[v])low[u]=min(low[u],dfn[v]);
	}
	if(low[u]==dfn[u]){
		++c,cl[u]=c,++cnt[c];
		while(st[top]!=u)cl[st[top]]=c,ins[st[top]]=0,--top,++cnt[c];
		ins[u]=0,--top;
	}
	return;
}

int dp(int u){
	if(vis[u])return f[u];
	for(int i=0;i<int(G[u].size());i++)f[u]=max(f[u],dp(G[u][i]));
	f[u]+=cnt[u];
	return f[u];
}

int main(){
	n=read(),m=read();
	for(int i=1,u,v;i<=m;i++){
		u=read(),v=read();
		g[u].push_back(v);
	}
	for(int i=1;i<=n;i++)if(!dfn[i])tarjan(i);
	for(int u=1;u<=n;u++){
		for(int i=0,v;i<int(g[u].size());i++){
			v=g[u][i];
			if(cl[u]!=cl[v]){
				G[cl[u]].push_back(cl[v]);
				G[cl[u]+c].push_back(cl[v]+c);
				G[cl[v]].push_back(cl[u]+c);
			}
		}
	}
	for(int i=1;i<=c;i++)cnt[c+i]=cnt[i];
	n=2*c;
	dis[cl[1]]=cnt[cl[1]];
	q.push(cl[1]),vis[cl[1]]=1;
	while(!q.empty()){
		int u=q.front();
		q.pop(),vis[u]=0;
		for(int i=0,v;i<int(G[u].size());i++){
			v=G[u][i];
			if(dis[u]+cnt[v]>dis[v]){
				dis[v]=dis[u]+cnt[v];
				if(!vis[v])q.push(v),vis[v]=0;
			}
		}
	}
	printf("%d\n",dis[cl[1]+c]-cnt[cl[1]]);
	return 0;
}
