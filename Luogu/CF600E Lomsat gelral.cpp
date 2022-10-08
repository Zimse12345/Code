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

const int N=2e5+7,Mod=998244353,INF=1e9+7;
int n,ty[N],hd[N],nxt[N],to[N],ec,mx;
ll sum,ans[N];
int fa[N],cnt[N],son[N],ct[N];
inline void add(int u,int v){to[++ec]=v,nxt[ec]=hd[u],hd[u]=ec;return;}
inline void ins(int x){++ct[x];if(ct[x]>mx)mx=ct[x],sum=x;else if(ct[x]==mx)sum+=x;return;}

void dfs1(int u,int from){
	fa[u]=from,cnt[u]=1;
	for(int i=hd[u],v;i;i=nxt[i]){
		v=to[i];
		if(v==from)continue;
		dfs1(v,u),cnt[u]+=cnt[v];
		if(cnt[son[u]]<cnt[v])son[u]=v;
	}
	return;
}

void dfs2(int u,int from){
	ins(ty[u]);
	for(int i=hd[u];i;i=nxt[i])if(to[i]^from)dfs2(to[i],u);
	return;
}

void dfs3(int u,int from){
	--ct[ty[u]];
	for(int i=hd[u];i;i=nxt[i])if(to[i]^from)dfs3(to[i],u);
	return;
}

void dfs4(int u,int from){
	for(int i=hd[u],v;i;i=nxt[i]){
		v=to[i];
		if(v==from||v==son[u])continue;
		dfs4(v,u);
	}
	if(son[u])dfs4(son[u],u);
	for(int i=hd[u],v;i;i=nxt[i]){
		v=to[i];
		if(v==from||v==son[u])continue;
		dfs2(v,u);
	}
	ins(ty[u]);
	ans[u]=sum;
	if(u^son[fa[u]])dfs3(u,from),mx=sum=0;
	return;
}

signed main(){
	n=read();
	for(int i=1;i<=n;i++)ty[i]=read();
	for(int i=1,u,v;i<n;i++)u=read(),v=read(),add(u,v),add(v,u);
	dfs1(1,0),dfs4(1,0);
	for(int i=1;i<=n;i++)printf("%lld ",ans[i]);
	return 0;
}

