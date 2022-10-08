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

const int N=1e5+7,Mod=998244353,INF=1e9+7;
int n,m,fa[N],cnt[N],dep[N],top[N],dfn[N],son[N],p[N],ct,mi[N<<2],tag[N<<2],ans[N];
struct edge{
	int u,v,w;
	edge(int u=0,int v=0,int w=0):u(u),v(v),w(w){};
	bool operator < (const edge& A)const{return w<A.w;}
}ex[N];
struct eg{
	int to,id;
	eg(int to=0,int id=0):to(to),id(id){}
};
vector<eg> g[N];

void dfs1(int u,int pr,int d){
	fa[u]=pr,dep[u]=d,cnt[u]=1;
	for(int i=0,v;i<int(g[u].size());i++){
		v=g[u][i].to;
		if(v==pr)continue;
		dfs1(v,u,d+1);
		cnt[u]+=cnt[v],p[g[u][i].id]=v;
		if(cnt[son[u]]<cnt[v])son[u]=v;
	}
	return;
}

void dfs2(int u,int pr){
	top[u]=pr,dfn[u]=++ct;
	if(son[u])dfs2(son[u],pr);
	for(int i=0,v;i<int(g[u].size());i++){
		v=g[u][i].to;
		if(v!=fa[u]&&v!=son[u])dfs2(v,v);
	}
	return;
}

void build(int L,int R,int id){
	mi[id]=INF;
	if(L!=R)build(L,(L+R)/2,id<<1),build((L+R)/2+1,R,(id<<1)|1);
	return;
}

void pushdown(int id){
	if(tag[id])mi[id]=tag[id],tag[id<<1]=tag[id],tag[(id<<1)|1]=tag[id],tag[id]=0;
	return;
}

void update(int L,int R,int id,int l,int r,int x){
	pushdown(id);
	if(l<=L&&r>=R)tag[id]=x,pushdown(id);
	else{
		int M=(L+R)>>1;
		if(l<=M)update(L,M,id<<1,l,r,x);
		else pushdown(id<<1);
		if(r>M)update(M+1,R,(id<<1)|1,l,r,x);
		else pushdown((id<<1)|1);
		mi[id]=min(mi[id<<1],mi[(id<<1)|1]);
	}
	return;
}

int query(int L,int R,int id,int x){
	pushdown(id);
	if(L==R)return mi[id];
	int M=(L+R)>>1;
	if(x<=M)return query(L,M,id<<1,x);
	else return query(M+1,R,(id<<1)|1,x);
}

int main(){
	n=read(),m=read();
	for(int i=1,u,v;i<n;i++){
		u=read(),v=read();
		g[u].push_back(eg(v,i)),g[v].push_back(eg(u,i));
	}
	for(int i=1,u,v,w;i<=m;i++)u=read(),v=read(),w=read(),ex[i]=edge(u,v,w);
	sort(ex+1,ex+m+1);
	dfs1(1,0,0),dfs2(1,1),build(1,n,1);
	for(int i=m,u,v,w;i>=1;i--){
		u=ex[i].u,v=ex[i].v,w=ex[i].w;
		while(top[u]!=top[v]){
			if(dep[top[u]]<dep[top[v]])swap(u,v);
			update(1,n,1,dfn[top[u]],dfn[u],w),u=fa[top[u]];
		}
		if(dep[u]>dep[v])swap(u,v);
		if(u!=v)update(1,n,1,dfn[u]+1,dfn[v],w);
	}
	for(int i=1;i<n;i++){
		ans[i]=query(1,n,1,dfn[p[i]]);
		if(ans[i]>=INF)ans[i]=-1;
	}
	for(int i=1;i<n;i++)printf("%d\n",ans[i]);
	return 0;
}
