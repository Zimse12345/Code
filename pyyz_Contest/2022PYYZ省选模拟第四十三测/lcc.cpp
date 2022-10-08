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

inline int read(){int qrx=0,qry=1;char qrc=getchar();
while(qrc<'0'||qrc>'9'){if(qrc=='-'){qry=-1,qrc=getchar();}else qrc=getchar();}
while(qrc>='0'&&qrc<='9')qrx=qrx*10+qrc-48,qrc=getchar();return qrx*qry;}

const int N=2e6+7,Mod=998244353,INF=1e9+7;
int n,hd[N],nxt[N*2],to[N*2],ec,ans,rt,ms=INF;
int cnt[N],fa[N],dep[N],son[N],dfn[N],Time,t1[N],t2[N];
int midu,midv;
vector<int> sz[N];
inline void add(int u,int v){nxt[++ec]=hd[u],hd[u]=ec,to[ec]=v;return;}

void dfs0(int u,int from){
	int mc=0;
	cnt[u]=1;
	for(int i=hd[u],v;i;i=nxt[i]){
		v=to[i];
		if(v==from)continue;
		dfs0(v,u);
		cnt[u]+=cnt[v],mc=max(mc,cnt[v]);
	}
	ans+=cnt[u]*(n-cnt[u]);
	mc=max(mc,n-cnt[u]);
	if(mc<ms)ms=mc,rt=u;
	return;
}

void dfs1(int u,int from){
	fa[u]=from,dep[u]=dep[from]+1,cnt[u]=1;
	for(int i=hd[u],v;i;i=nxt[i]){
		v=to[i];
		if(v==from)continue;
		dfs1(v,u);
		cnt[u]+=cnt[v];
		if(cnt[son[u]]<cnt[v])son[u]=v;
	}
	if(cnt[u]*2==n)midu=u,midv=from;
	return;
}

void dfs2(int u){
	dfn[u]=++Time;
	sz[cnt[u]].push_back(dfn[u]);
	if(son[u])dfs2(son[u]);
	for(int i=hd[u],v;i;i=nxt[i]){
		v=to[i];
		if(v==fa[u]||v==son[u])continue;
		dfs2(v);
	}
	return;
}

void dfs3(int u){
	t1[cnt[u]]++,t2[n-cnt[u]]++;
	if(u!=rt){
		int p=n/2-cnt[u],tot=sz[p].size();
		int dL=dfn[u],dR=dfn[u]+cnt[u]-1;
		int RR=-1,LL=sz[p].size();
		int L=0,R=sz[p].size()-1;
		while(L<=R){
			int M=(L+R)/2;
			if(sz[p][M]>=dL)LL=M,R=M-1;
			else L=M+1;
		}
		L=0,R=sz[p].size()-1;
		while(L<=R){
			int M=(L+R)/2;
			if(sz[p][M]<=dR)RR=M,L=M+1;
			else R=M-1;
		}
		tot-=max(0ll,RR-LL+1)+t1[p];
		tot+=t2[p];
		if(cnt[u]==p)++tot;
		ans-=p*tot*cnt[u];
	}
	for(int i=hd[u],v;i;i=nxt[i]){
		v=to[i];
		if(v==fa[u])continue;
		dfs3(v);
	}
	t1[cnt[u]]--,t2[n-cnt[u]]--;
	return;
}

void dfs4(int u,int from){
	cnt[u]=1;
	for(int i=hd[u],v;i;i=nxt[i]){
		v=to[i];
		if(v==from)continue;
		dfs4(v,u),cnt[u]+=cnt[v];
	}
	ans-=cnt[u]*(n/2-cnt[u]);
	return;
}

signed main(){
	n=read();
	for(int i=1,u,v;i<n;i++)u=read(),v=read(),add(u,v),add(v,u);
	dfs0(1,0);
	if(n&1){
		printf("%lld\n",ans);
		return 0;
	}
	dfs1(rt,0);
	dfs2(rt);
	dfs3(rt);
	if(midu&&midv){
		dfs4(midu,midv);
		dfs4(midv,midu);
		ans-=n*n/4;
	}
	printf("%lld\n",ans);
	return 0;
}

