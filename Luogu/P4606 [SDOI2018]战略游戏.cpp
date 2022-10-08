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

inline int read(){int qrx=0,qry=1;char qrc=getchar();
while(qrc<'0'||qrc>'9'){if(qrc=='-'){qry=-1,qrc=getchar();}else qrc=getchar();}
while(qrc>='0'&&qrc<='9')qrx=qrx*10+qrc-48,qrc=getchar();return qrx*qry;}

const int N=4e5+7,Mod=998244353,INF=1e9+7;
int T,_n,n,m,Q,Time,hd[N],nxt[N],to[N],ec;
int Hd[N],Nxt[N*2],To[N*2],Ec;
int dfn[N],low[N],stk[N],top;
int fa[N],dep[N],cnt[N],son[N],Dfn[N],Top[N];
int tr[N];
inline void db(int& x){x-=(x&(-x));return;}
inline void ub(int& x){x+=(x&(-x));return;}
inline void inc(int x,int t){for(;x<N;ub(x))tr[x]+=t;return;}
inline int sum(int x){int res=0;for(;x;db(x))res+=tr[x];return res;} 
inline void add(int u,int v){nxt[++ec]=hd[u],hd[u]=ec,to[ec]=v;return;}
inline void Add(int u,int v){Nxt[++Ec]=Hd[u],Hd[u]=Ec,To[Ec]=v;return;}
struct node{int x,y;node(int x=0,int y=0):x(x),y(y){}bool operator < (const node& A)const{return y<A.y;}};

void tarjan(int u){
	dfn[u]=low[u]=++Time,stk[++top]=u;
	for(int i=hd[u],v;i;i=nxt[i]){
		v=to[i];
		if(!dfn[v]){
			tarjan(v),low[u]=min(low[u],low[v]);
			if(low[v]>=dfn[u]){
				++_n,Add(_n,u),Add(u,_n);
				do{Add(_n,stk[top]),Add(stk[top],_n),--top;}while(stk[top+1]^v);
			}
		}
		else low[u]=min(low[u],dfn[v]);
	}
	return;
}

void dfs1(int u,int from,int d){
	fa[u]=from,dep[u]=d,cnt[u]=1;
	for(int i=Hd[u],v;i;i=Nxt[i]){
		v=To[i];
		if(v==from)continue;
		dfs1(v,u,d+1),cnt[u]+=cnt[v];
		if(cnt[son[u]]<cnt[v])son[u]=v;
	}
	return;
}

void dfs2(int u,int from,int d){
	Dfn[u]=++Time,Top[u]=d;
	if(son[u])dfs2(son[u],u,d);
	for(int i=Hd[u],v;i;i=Nxt[i]){
		v=To[i];
		if(v==from||v==son[u])continue;
		dfs2(v,u,v);
	}
	return;
}

int LCA(int u,int v){
	while(Top[u]^Top[v]){
		if(dep[Top[u]]<dep[Top[v]])swap(u,v);
		u=fa[Top[u]];
	}
	return dep[u]<dep[v]?u:v;
}

int calc(int u,int v){
	int res=0;
	if(u<=n)--res;
	if(v<=n)--res;
	while(Top[u]^Top[v]){
		if(dep[Top[u]]<dep[Top[v]])swap(u,v);
		res+=sum(Dfn[u])-sum(Dfn[Top[u]]-1),u=fa[Top[u]];
	}
	if(Dfn[v]<Dfn[u])swap(u,v);
	res+=sum(Dfn[v])-sum(Dfn[u]-1);
	return res;
}

signed main(){
	T=read();
	while(T--){
		_n=n=read(),m=read();
		for(int i=1,u,v;i<=m;i++)u=read(),v=read(),add(u,v),add(v,u);
		Time=0,tarjan(1);
		dfs1(1,0,1);
		Time=0,dfs2(1,0,1);
		for(int i=1;i<=n;i++)inc(Dfn[i],1);
		Q=read();
		while(Q--){
			int t=read(),lca,ans=0;
			vector<node> q;
			for(int i=0,x;i<t;i++)x=read(),q.push_back(node(x,Dfn[x]));
			sort(q.begin(),q.end());
			lca=LCA(q[0].x,q[1].x);
			ans+=calc(q[0].x,q[1].x);
			for(int i=2;i<signed(q.size());i++){
				int _lca=LCA(q[i-1].x,q[i].x);
				if(dep[_lca]>=dep[lca])ans+=calc(_lca,q[i].x);
				else ans+=calc(lca,q[i].x),lca=_lca;
			}
			printf("%d\n",ans);
		}
		for(int i=1;i<=n;i++)hd[i]=dfn[i]=0,inc(Dfn[i],-1);
		for(int i=1;i<=_n;i++)Hd[i]=son[i]=0;
 		for(int i=1;i<=ec;i++)nxt[i]=to[i]=0;
		for(int i=1;i<=Ec;i++)Nxt[i]=To[i]=0;
		ec=Ec=top=0;
	}
	return 0;
}

