//Completely wrong code but AC
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

const int N=4e6+7,Mod=998244353,INF=1e9+7;
int n,hd[N],nxt[N],to[N],ec,f[N],vis[N],ans,m[2001][2001];
int dfn[N],low[N],ct,st[N],top,cl[N],cc,siz[N];
char s[2001][2001];

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
		--top,siz[cc]=tot;
	}
	return;
}

void dp(int u){
	if(vis[u]++)return;
	f[u]=siz[u];
	for(int i=hd[u],v;i;i=nxt[i]){
		v=to[i];
		dp(v),f[u]+=f[v];
	}
	printf("%d %d %d\n",u,f[u],siz[u]);
	return;
}

int main(){
	n=read();
	for(int i=1;i<=n;i++){
		scanf("%s",s[i]+1);
		for(int j=1;j<=n;j++)if(s[i][j]=='1')add(i,j);
	}
	for(int i=1;i<=n;i++)if(!dfn[i])tarjan(i);
	for(int i=1;i<=ec;i++)hd[i]=to[i]=nxt[i]=0;
	ec=0;
	for(int u=1;u<=n;u++){
		printf("[%d %d]\n",u,cl[u]);
		for(int v=1;v<=n;v++)if(s[u][v]=='1'){
			if(cl[u]!=cl[v]&&!m[cl[u]][cl[v]])add(cl[u],cl[v]),m[cl[u]][cl[v]]=1;
		}
	}
	for(int i=1;i<=cc;i++)if(!vis[i])dp(i);
	for(int i=1;i<=cc;i++)ans+=siz[i]*f[i];
	printf("%d\n",ans);
	return 0;
}
