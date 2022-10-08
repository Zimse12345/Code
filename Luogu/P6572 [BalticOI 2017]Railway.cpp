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
#define Lid (id<<1)
#define Rid ((id<<1)|1)
#define M ((L+R)>>1)

using namespace std;

int read(){int qrx=0,qry=1;char qrc=getchar();
while(qrc<'0'||qrc>'9'){if(qrc=='-'){qry=-1,qrc=getchar();}else qrc=getchar();}
while(qrc>='0'&&qrc<='9')qrx=qrx*10+qrc-48,qrc=getchar();return qrx*qry;}

const int N=2e5+7,Mod=998244353,INF=1e9+7;
int n,m,k,hd[N],nxt[N],to[N],id[N],ec;
int fa[N],dep[N],cnt[N],son[N],dfn[N],_dfn[N],top[N],ct;
int tag[N*4],ans[N],tot,e[N];
struct node{int x,y;node(int x=0,int y=0):x(x),y(y){}
bool operator < (const node& A)const{return y<A.y;}}p[N];
inline void add(int u,int v,int t){nxt[++ec]=hd[u],hd[u]=ec,to[ec]=v,id[ec]=t;return;}

void update(int L,int R,int id,int l,int r){
	if(l>R||L>r)return;
	if(l<=L&&r>=R)++tag[id];
	else update(L,M,Lid,l,r),update(M+1,R,Rid,l,r);
	return;
}

int query(int L,int R,int id,int x){
	if(L==R)return tag[id];
	if(x<=M)return query(L,M,Lid,x)+tag[id];
	return query(M+1,R,Rid,x)+tag[id];
}

int LCA(int x,int y){
	while(top[x]^top[y]){
		if(dep[top[x]]<dep[top[y]])swap(x,y);
		x=fa[top[x]];
	}
	if(dep[x]<dep[y])return x;
	return y;
}

void upt(int x,int y){
	while(top[x]^top[y]){
		if(dep[top[x]]<dep[top[y]])swap(x,y);
		update(1,n,1,dfn[top[x]],dfn[x]),x=fa[top[x]];
	}
	if(dep[x]<dep[y])swap(x,y);
	if(x^y)update(1,n,1,dfn[y]+1,dfn[x]);
	return;
}

void dfs1(int u,int from,int d){
	fa[u]=from,dep[u]=d,cnt[u]=1;
	for(int i=hd[u],v;i;i=nxt[i]){
		v=to[i];
		if(v==from)continue;
		dfs1(v,u,d+1),cnt[u]+=cnt[v],e[v]=id[i];
		if(cnt[son[u]]<cnt[v])son[u]=v;
	}
	return;
}

void dfs2(int u,int from,int t){
	dfn[u]=++ct,top[u]=t,_dfn[ct]=u;
	if(son[u])dfs2(son[u],u,t);
	for(int i=hd[u],v;i;i=nxt[i]){
		v=to[i];
		if(v==from||v==son[u])continue;
		dfs2(v,u,v);
	}
	return;
}

signed main(){
	n=read(),m=read(),k=read();
	for(int i=1,u,v;i<n;i++)u=read(),v=read(),add(u,v,i),add(v,u,i);
	dfs1(1,0,1),dfs2(1,0,1);
	for(int i=1,s;i<=m;i++){
		s=read();
		for(int j=1,x;j<=s;j++)x=read(),p[j]=node(x,dfn[x]);
		sort(p+1,p+s+1);
		int lca=LCA(p[1].x,p[2].x);
		upt(p[1].x,p[2].x);
		for(int j=3;j<=s;j++){
			int u=LCA(p[j].x,p[j-1].x);
			if(dep[u]>=dep[lca])upt(u,p[j].x);
			else upt(lca,p[j].x),lca=u;
		}
	}
	for(int i=1;i<=n;i++)if(query(1,n,1,i)>=k)ans[++tot]=e[_dfn[i]];
	printf("%d\n",tot);
	sort(ans+1,ans+tot+1);
	for(int i=1;i<=tot;i++)printf("%d ",ans[i]);
	printf("\n");
	return 0;
}

