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
#define M ((L+R)>>1)
#define Lid (id<<1)
#define Rid ((id<<1)|1)

using namespace std;

int read(){int qrx=0,qry=1;char qrc=getchar();
while(qrc<'0'||qrc>'9'){if(qrc=='-'){qry=-1,qrc=getchar();}else qrc=getchar();}
while(qrc>='0'&&qrc<='9')qrx=qrx*10+qrc-48,qrc=getchar();return qrx*qry;}

const int N=2e5+7,Mod=998244353,INF=1e9+7;
int n,q,hd[N],nxt[N],to[N],ec;
int Rt,rt,sz,rs,cnt[N],vis[N],Fa[N],To[N];
ll ffrom[N],gfrom[N],S;
ll d[N],f[N],g[N],dep[N],len[N];
int num[20][N],dfn[N],_dfn[N],ct,LOG[N]; 
int fa[N],siz[N],son[N],Dfn[N],top[N],tt;
inline void add(int u,int v,int w){nxt[++ec]=hd[u],hd[u]=ec,to[ec]=v,len[ec]=w;return;}

ll tr[N];
inline void ub(int& x){x+=(x&(-x));return;}
inline void db(int& x){x-=(x&(-x));return;}
inline void bit_add(int x,ll t){for(;x<=n;ub(x))tr[x]+=t;return;}
inline ll bit_sum(int x){ll res=0;for(;x;db(x))res+=tr[x];return res;}

void update(int x,int t){
	while(x){
		bit_add(Dfn[top[x]],t),bit_add(Dfn[x]+1,-t);
		x=fa[top[x]];
	}
	return;
}

void dfs(int u,int from,ll d){
	dfn[u]=++ct,_dfn[ct]=u;
	num[0][ct]=dfn[u],dep[u]=d;
	fa[u]=from,siz[u]=1;
	for(int i=hd[u],v;i;i=nxt[i]){
		v=to[i];
		if(v==from)continue;
		dfs(v,u,d+len[i]),num[0][++ct]=dfn[u],siz[u]+=siz[v];
		if(siz[son[u]]<siz[v])son[u]=v;
	}
	return;
}

void dfs2(int u,int from,int t){
	Dfn[u]=++tt,top[u]=t;
	if(son[u])dfs2(son[u],u,t);
	for(int i=hd[u],v;i;i=nxt[i]){
		v=to[i];
		if(v==from||v==son[u])continue;
		dfs2(v,u,v);
	}
	return;
}

int RMQ(int L,int R){
	int l=R-L+1,t=LOG[l];
	return min(num[t][R],num[t][L+(1<<t)-1]);
}

ll dis(int u,int v){
	if(dfn[u]>dfn[v])swap(u,v);
	int lca=_dfn[RMQ(dfn[u],dfn[v])];
	return dep[u]+dep[v]-dep[lca]*2;
}

void findrt(int u,int from){
	cnt[u]=1;
	int ms=0;
	for(int i=hd[u],v;i;i=nxt[i]){
		v=to[i];
		if(vis[v]||v==from)continue;
		findrt(v,u),cnt[u]+=cnt[v];
		ms=max(ms,cnt[v]);
	}
	ms=max(ms,sz-cnt[u]);
	if(ms<rs)rs=ms,rt=u;
	return;
}

void divide(int u){
	vis[u]=1;
	for(int i=hd[u],v;i;i=nxt[i]){
		v=to[i];
		if(vis[v])continue;
		sz=cnt[v],rs=INF,findrt(v,u);
		Fa[rt]=u,To[i]=rt;
		divide(rt);
	}
	return;
}

ll work(int u){
	ll res=0;int from=0,x=u;
	while(u){
		res+=g[u]-gfrom[from]+dis(u,x)*(f[u]-ffrom[from]);
		from=u,u=Fa[u];
	}
	return res;
}

signed main(){
	n=read(),q=read();
	for(int i=1,u,v,w;i<n;i++)u=read(),v=read(),w=read(),add(u,v,w),add(v,u,w);
	dfs(1,0,0),dfs2(1,0,1);
	for(int i=2;i<=ct;i++)LOG[i]=LOG[i>>1]+1;
	for(int i=1;i<=18;i++)for(int j=(1<<i);j<=ct;j++)num[i][j]=min(num[i-1][j],num[i-1][j-(1<<(i-1))]);
	sz=n,rs=INF,findrt(1,0),Rt=rt;
	divide(rt);
	while(q--){
		int u=read();ll e=read();int x=u,p=Rt,from=0;
		update(u,e);
		while(x){
			ll c=dis(u,x)*e;
			f[x]+=e,g[x]+=c;
			if(from)ffrom[from]+=e,gfrom[from]+=c;
			from=x,x=Fa[x];
		}
		d[u]+=e,S+=e;
		while(1){
			int tg=0;
			for(int i=hd[p];i;i=nxt[i])if(To[i]){
				if((fa[to[i]]==p&&bit_sum(Dfn[to[i]])*2>S)||(fa[p]==to[i]&&bit_sum(Dfn[p])*2<S)){
					p=To[i],tg=1;
					break;
				}
			}
			if(!tg)break;
		}
		printf("%lld\n",work(p));
	}
	return 0;
}

