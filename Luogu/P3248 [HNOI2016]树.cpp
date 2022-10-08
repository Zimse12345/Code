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
#define ll long long
#define Lid ch[id][0]
#define Rid ch[id][1]
#define M ((L+R)>>1)

using namespace std;

int read(){int qrx=0,qry=1;char qrc=getchar();
while(qrc<'0'||qrc>'9'){if(qrc=='-'){qry=-1,qrc=getchar();}else qrc=getchar();}
while(qrc>='0'&&qrc<='9')qrx=qrx*10+qrc-48,qrc=getchar();return qrx*qry;}

const int N=2e5+7,Mod=998244353,INF=1e9+7;
int n,m,q,hd[N],nxt[N],to[N],ec,fa[N],dep[N],cnt[N],son[N],top[N],dfn[N],ct;
int Hd[N],Nxt[N],To[N],c[N],Ec,fn[N],tn[N],nc,lid[N];
int Fa[N],Dep[N],Cnt[N],Son[N],Top[N],Dfn[N],_dfn[N],Ct;
int Rt[N],sum[N*16],ch[N*16][2],cc;
ll len[N];
struct node{int x,y;node(int x=0,int y=0):x(x),y(y){}
bool operator < (const node& A)const{return x<A.x;}}p[N];

inline void add(int u,int v){nxt[++ec]=hd[u],hd[u]=ec,to[ec]=v;return;}
inline void Add(int u,int v,int w){Nxt[++Ec]=Hd[u],Hd[u]=Ec,To[Ec]=v,c[Ec]=w;return;}

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

void dfs2(int u,int t){
	dfn[u]=++ct,top[u]=t;
	if(son[u])dfs2(son[u],t);
	for(int i=hd[u],v;i;i=nxt[i]){
		v=to[i];
		if(v==fa[u]||v==son[u])continue;
		dfs2(v,v);
	}
	return;
}

void dfs3(int u,int from,int d,ll D){
	Fa[u]=from,Dep[u]=d,len[u]=D,Cnt[u]=1;
	for(int i=Hd[u],v;i;i=Nxt[i]){
		v=To[i];
		if(v==from)continue;
		dfs3(v,u,d+1,D+c[i]),Cnt[u]+=Cnt[v];
		if(Cnt[Son[u]]<Cnt[v])Son[u]=v;
	}
	return;
}

void dfs4(int u,int t){
	Dfn[u]=++Ct,Top[u]=t;
	if(Son[u])dfs4(Son[u],t);
	for(int i=Hd[u],v;i;i=Nxt[i]){
		v=To[i];
		if(v==Fa[u]||v==Son[u])continue;
		dfs4(v,v);
	}
	return;
}

int dis(int u,int v){
	int res=0;
	while(top[u]^top[v]){
		if(dep[top[u]]<dep[top[v]])swap(u,v);
		res+=dep[u]-dep[top[u]]+1,u=fa[top[u]];
	}
	if(dep[v]<dep[u])swap(u,v);
	return res+dep[v]-dep[u];
}

int LCA(int u,int v){
	while(Top[u]^Top[v]){
		if(Dep[Top[u]]<Dep[Top[v]])swap(u,v);
		u=Fa[Top[u]];
	}
	if(Dep[u]<Dep[v])return u;
	return v;
}

ll Dis(int u,int v,int d1,int d2,int xx,int yy){
	ll res=0;int lca=LCA(u,v);
	if(u!=lca)res+=d1;
	if(v!=lca)res+=d2;
	while(Top[u]!=Top[lca]&&Fa[u]!=lca){
		if(Fa[Top[u]]==lca){res+=len[u]-len[Top[u]],u=Top[u];break;}
		res+=len[u]-len[Fa[Top[u]]],u=Fa[Top[u]];
	}
	if(u!=lca&&Fa[u]!=lca){
		int uu=_dfn[Dfn[lca]+1];
		res+=len[u]-len[uu],u=uu;
	}
	while(Top[v]!=Top[lca]&&Fa[v]!=lca){
		if(Fa[Top[v]]==lca){res+=len[v]-len[Top[v]],v=Top[v];break;}
		res+=len[v]-len[Fa[Top[v]]],v=Fa[Top[v]];
	}
	if(v!=lca&&Fa[v]!=lca){
		int vv=_dfn[Dfn[lca]+1];
		res+=len[v]-len[vv],v=vv;
	}
	if(u!=lca)++res,xx=tn[u];
	if(v!=lca)++res,yy=tn[v];
	res+=dis(xx,yy);
	return res;
}

void update(int L,int R,int& id,int _id,int x){
	id=++cc,sum[id]=sum[_id]+1;
	if(L^R){
		if(x<=M)update(L,M,Lid,ch[_id][0],x),Rid=ch[_id][1];
		else update(M+1,R,Rid,ch[_id][1],x),Lid=ch[_id][0];
	}
	return;
}

int query(int L,int R,int id,int l,int r){
	if(l>R||L>r)return 0;
	if(l<=L&&r>=R)return sum[id];
	return query(L,M,Lid,l,r)+query(M+1,R,Rid,l,r);
}

int kth(int id,int k){
	int L=1,R=n,res=1;
	while(L<=R){
		if(query(1,n,Rt[M],dfn[id],dfn[id]+cnt[id]-1)>=k)res=M,R=M-1;
		else L=M+1;
	}
	return res;
}

signed main(){
	n=read(),m=read(),q=read();
	for(int i=1,u,v;i<n;i++)u=read(),v=read(),add(u,v),add(v,u);
	fn[++nc]=1,lid[1]=1;
	dfs1(1,0,1),dfs2(1,1);
	for(int i=1;i<=n;i++)p[i]=node(i,dfn[i]);
	sort(p+1,p+n+1);
	for(int i=1;i<=n;i++)update(1,n,Rt[i],Rt[i-1],p[i].y);
	for(int i=1,x,y;i<=m;i++){
		x=read(),y=read();
		int L=1,R=nc,v=1;
		while(L<=R){
			if(lid[M]<=y)v=M,L=M+1;
			else R=M-1;
		}
		fn[++nc]=x,tn[nc]=kth(fn[v],y-lid[v]+1),lid[nc]=lid[nc-1]+cnt[fn[nc-1]];
		Add(v,nc,dep[tn[nc]]-dep[fn[v]]+1);
	}
	dfs3(1,0,1,0),dfs4(1,1);
	for(int i=1;i<=nc;i++)_dfn[Dfn[i]]=i;
	
	for(int i=1,x,y;i<=q;i++){
		x=read(),y=read();
		int L=1,R=nc,v1=1,v2=1;
		while(L<=R){
			if(lid[M]<=x)v1=M,L=M+1;
			else R=M-1;
		}
		L=1,R=nc;
		while(L<=R){
			if(lid[M]<=y)v2=M,L=M+1;
			else R=M-1;
		}
		int xx=kth(fn[v1],x-lid[v1]+1),yy=kth(fn[v2],y-lid[v2]+1);
		printf("%lld\n",Dis(v1,v2,dis(xx,fn[v1]),dis(yy,fn[v2]),xx,yy));
	}
	return 0;
}

