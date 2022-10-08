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
#define Lid (ch[id][0])
#define Rid (ch[id][1])
#define M ((L+R)>>1)

using namespace std;

int read(){int qrx=0,qry=1;char qrc=getchar();
while(qrc<'0'||qrc>'9'){if(qrc=='-'){qry=-1,qrc=getchar();}else qrc=getchar();}
while(qrc>='0'&&qrc<='9')qrx=qrx*10+qrc-48,qrc=getchar();return qrx*qry;}

const int N=2e5+7,Mod=998244353,INF=1e9+7;
int n,m,hd[N],nxt[N],to[N],ec,ans[N];
int fa[N],dep[N],cnt[N],son[N],top[N];
int rt[N],v[N*24],ch[N*24][2],tot;
struct node{int x,y;node(int x=0,int y=0):x(x),y(y){}};
vector<node> op[N];
node mx[N*24];
stack<int> rbs;
inline void add(int u,int v){to[++ec]=v,nxt[ec]=hd[u],hd[u]=ec;return;}
inline int newnode(){if(rbs.empty())return ++tot;int res=rbs.top();rbs.pop();return res;}

void update(int& id,int L,int R,int x,int y){
	if(!id)id=newnode();
	v[id]+=y;
	if(L==R)mx[id]=node(v[id],L);
	else{
		if(x<=M)update(Lid,L,M,x,y);
		else update(Rid,M+1,R,x,y);
		if(mx[Lid].x>mx[Rid].x||(mx[Lid].x==mx[Rid].x&&mx[Lid].y<mx[Rid].y))mx[id]=mx[Lid];
		else mx[id]=mx[Rid];
	}
	return;
}

void merge(int& id,int y,int L,int R){
	if(!id){id=y;return;}
	if(!y)return;
	v[id]+=v[y];
	if(L==R)mx[id]=node(v[id],L);
	else{
		merge(Lid,ch[y][0],L,M),merge(Rid,ch[y][1],M+1,R);
		if(mx[Lid].x>mx[Rid].x||(mx[Lid].x==mx[Rid].x&&mx[Lid].y<mx[Rid].y))mx[id]=mx[Lid];
		else mx[id]=mx[Rid];
		ch[y][0]=ch[y][1]=v[y]=0,mx[y]=node(0,0),rbs.push(y);
	}
	return;
}

void dfs1(int u,int from,int d){
	fa[u]=from,dep[u]=d,cnt[u]=1;
	for(int i=hd[u],v;i;i=nxt[i]){
		v=to[i];
		if(v==from)continue;
		dfs1(v,u,d+1),cnt[u]+=cnt[v];
		if(cnt[v]>cnt[son[u]])son[u]=v;
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

void dfs(int u,int from){
	for(unsigned i=0;i<op[u].size();i++)update(rt[u],1,1e5,op[u][i].x,op[u][i].y);
	for(int i=hd[u],v;i;i=nxt[i]){
		v=to[i];
		if(v==from)continue;
		dfs(v,u);
		merge(rt[u],rt[v],1,1e5);
	}
	ans[u]=mx[rt[u]].y;
	return;
}

inline int LCA(int x,int y){
	while(top[x]^top[y]){
		if(dep[top[x]]<dep[top[y]])swap(x,y);
		x=fa[top[x]];
	}
	if(dep[x]>dep[y])swap(x,y);
	return x;
} 

signed main(){
	n=read(),m=read();
	for(int i=1,u,v;i<n;i++)u=read(),v=read(),add(u,v),add(v,u);
	dfs1(1,0,1),dfs2(1,0,1);
	for(int i=1,x,y,z,lca;i<=m;i++){
		x=read(),y=read(),z=read();
		lca=LCA(x,y);
		op[x].push_back(node(z,1)),op[y].push_back(node(z,1));
		op[lca].push_back(node(z,-1)),lca=fa[lca];
		if(lca)op[lca].push_back(node(z,-1));
	}
	dfs(1,0);
	for(int i=1;i<=n;i++)printf("%d\n",ans[i]);
	return 0;
}

