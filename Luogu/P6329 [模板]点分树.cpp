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

const int N=2e5+7,Mod=998244353,INF=1e9+7;
int n,m,val[N];
int hd[N],nxt[N],to[N],ec;
int cnt[N],rt,rs,sz,Rt,vis[N];
int fa[N],dep[N],son[N],top[N];
int Fa[N],fl[N];
vector<int> C[N],c[N];
inline void add(int u,int v){nxt[++ec]=hd[u],hd[u]=ec,to[ec]=v;return;}

void dfs1(int u,int from,int d){
	fa[u]=from,dep[u]=d,cnt[u]=1;
	for(int i=hd[u],v;i;i=nxt[i]){
		v=to[i];
		if(v==from)continue;
		dfs1(v,u,d+1),cnt[u]+=cnt[v];
		if(cnt[son[u]]<cnt[v])son[u]=v;
	}
	return;
}

void dfs2(int u,int from,int t){
	top[u]=t;
	if(son[u])dfs2(son[u],u,t);
	for(int i=hd[u],v;i;i=nxt[i]){
		v=to[i];
		if(v==from||v==son[u])continue;
		dfs2(v,u,v);
	}
	return;
}

int dis(int x,int y){
	int res=0;
	while(top[x]^top[y]){
		if(dep[top[x]]<dep[top[y]])swap(x,y);
		res+=dep[x]-dep[top[x]]+1,x=fa[top[x]];
	}
	if(dep[x]<dep[y])swap(x,y);
	return res+dep[x]-dep[y];
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

int finddep(int u,int from){
	int res=0;
	for(int i=hd[u],v;i;i=nxt[i]){
		v=to[i];
		if(v==from||vis[v])continue;
		res=max(res,finddep(v,u));
	}
	return res+1;
}

inline void ub(int& x){x+=(x&(-x));return;}
inline void db(int& x){x-=(x&(-x));return;}
inline void bit_add(vector<int>& v,int x,int t){++x;for(;x<signed(v.size());ub(x))v[x]+=t;return;}
inline int bit_sum(vector<int>& v,int x){++x;if(x>=signed(v.size()))x=v.size()-1;int res=0;for(;x;db(x))res+=v[x];return res;}

void calc(int u,int from,int d,vector<int>& V){
	bit_add(V,d,val[u]);
	for(int i=hd[u],v;i;i=nxt[i]){
		v=to[i];
		if(v==from||vis[v])continue;
		calc(v,u,d+1,V);
	}
	return;
}

void divide(int u){
	vis[u]=1;
	int D=finddep(u,0)+1;
	while(D--)C[u].push_back(0);
	calc(u,0,0,C[u]);
	for(int i=hd[u],v;i;i=nxt[i]){
		v=to[i];
		if(vis[v])continue;
		D=finddep(v,u)+2;
		rs=INF,sz=cnt[v],findrt(v,u);
		while(D--)c[rt].push_back(0);
		calc(v,u,1,c[rt]);
		Fa[rt]=u,fl[rt]=v,divide(rt);
	}
	return;
}

signed main(){
	n=read(),m=read();
	for(int i=1;i<=n;i++)val[i]=read();
	for(int i=1,u,v;i<n;i++)u=read(),v=read(),add(u,v),add(v,u);
	dfs1(1,0,1),dfs2(1,0,1);
	rs=INF,sz=n,findrt(1,0),Rt=rt;
	divide(rt);
	for(int i=1,ans=0,op,x,y;i<=m;i++){
		op=read(),x=read()^ans,y=read()^ans;
		if(op==0){
			int u=x,v=0;
			ans=0;
			while(x){
				int d=y-dis(u,x);
				if(d>=0&&C[x].size()>1)ans+=bit_sum(C[x],d);
				if(d>=0&&c[v].size()>1)ans-=bit_sum(c[v],d);
				v=x,x=Fa[x];
			}
			printf("%lld\n",ans);
		}
		else{
			int u=x,v=0;
			while(x){
				int d=dis(u,x);
				bit_add(C[x],d,y-val[u]);
				if(v)bit_add(c[v],d,y-val[u]);
				v=x,x=Fa[x];
			}
			val[u]=y;
		}
	}
	return 0;
}

