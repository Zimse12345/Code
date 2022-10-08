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

const int N=2e5+7,Mod=1e9+7,INF=1e9+7;
int n,hd[N],nxt[N],to[N],tag[N],ec=1,k,s[N*10];
int fa[N],cnt[N],dep[N],son[N],dfn[N],top[N],ct;
int t1[N],t2[N],tot[N],ans;
inline void add(int u,int v,int tg){nxt[++ec]=hd[u],hd[u]=ec,to[ec]=v,tag[ec]=tg;return; }
inline int qp(int x,int k){int res=1;while(k){if(k&1ll)res=(res*x)%Mod;x=(x*x)%Mod,k/=2;}return res;}

void dfs1(int u,int from,int d){
	fa[u]=from,cnt[u]=1,dep[u]=d;
	for(int i=hd[u],v;i;i=nxt[i]){
		v=to[i];
		if(v==from)continue;
		dfs1(v,u,d+1),cnt[u]+=cnt[v];
		if(cnt[son[u]]<cnt[v])son[u]=v;
	}
	return;
}

void dfs2(int u,int from,int t){
	dfn[u]=++ct,top[u]=t;
	if(son[u])dfs2(son[u],u,t);
	for(int i=hd[u],v;i;i=nxt[i]){
		v=to[i];
		if(v==from||v==son[u])continue;
		dfs2(v,u,v);
	}
	return;
}

int LCA(int u,int v){
	while(top[u]^top[v]){
		if(dep[top[u]]<dep[top[v]])swap(u,v);
		u=fa[top[u]];
	}
	if(dep[u]>dep[v])return v;
	return u;
}

void dfs(int u,int from,int id){
	for(int i=hd[u],v;i;i=nxt[i]){
		v=to[i];
		if(v==from)continue;
		dfs(v,u,i),t1[u]+=t1[v],t2[u]+=t2[v];
	}
	if(tag[id^1])tot[u]=t1[u];
	if(tag[id])tot[u]=t2[u];
	return;
}

signed main(){
	n=read();
	for(int i=1,u,v,tg;i<n;i++)u=read(),v=read(),tg=read(),add(u,v,0),add(v,u,tg);
	dfs1(1,0,1);
	dfs2(1,0,1);
	k=read();
	s[0]=1;
	for(int i=1,lca;i<=k;i++){
		s[i]=read(),lca=LCA(s[i-1],s[i]);
		++t1[lca],++t2[lca],--t1[s[i-1]],--t2[s[i]];
	}
	dfs(1,0,0);
	for(int i=1;i<=n;i++)if(cnt[i])ans=(ans+qp(2,tot[i])-1)%Mod;
	ans=(ans+Mod)%Mod;
	printf("%lld\n",ans);
	return 0;
}

