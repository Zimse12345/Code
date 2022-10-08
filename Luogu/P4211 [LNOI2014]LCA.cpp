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

using namespace std;

int read(){int qrx=0,qry=1;char qrc=getchar();
while(qrc<'0'||qrc>'9'){if(qrc=='-'){qry=-1,qrc=getchar();}else qrc=getchar();}
while(qrc>='0'&&qrc<='9')qrx=qrx*10+qrc-48,qrc=getchar();return qrx*qry;}

const int N=1e5+7,Mod=201314,INF=1e9+7;
int n,m,ans[N];
int fa[N],dep[N],cnt[N],hv[N],dfn[N],top[N],ct;
int sum[N*4],tag[N*4],len[N*4];
vector<int> g[N];
struct qu{
	int p,ty,z,id;
	qu(int p=0,int ty=0,int z=0,int id=0):p(p),ty(ty),z(z),id(id){}
	bool operator < (const qu& A)const{return p<A.p;} 
}q[N];

void dfs1(int u,int pr,int dp){
	fa[u]=pr,dep[u]=dp,cnt[u]=1;
	for(int i=0,v;i<signed(g[u].size());i++){
		v=g[u][i];
		if(v==pr)continue;
		dfs1(v,u,dp+1),cnt[u]+=cnt[v];
		if(cnt[hv[u]]<cnt[v])hv[u]=v;
	}
	return;
}

void dfs2(int u,int pr){
	dfn[u]=++ct,top[u]=pr;
	if(hv[u])dfs2(hv[u],pr);
	for(int i=0,v;i<signed(g[u].size());i++){
		v=g[u][i];
		if(v==hv[u]||v==fa[u])continue;
		dfs2(v,v);
	}
	return;
}

void build(int L,int R,int id){
	len[id]=R-L+1;
	if(L!=R)build(L,(L+R)/2,Lid),build((L+R)/2+1,R,Rid);
	return;
}

void pushdown(int id){
	if(tag[id]){
		sum[id]=(sum[id]+tag[id]*len[id])%Mod;
		if(len[id]>1)tag[Lid]+=tag[id],tag[Rid]+=tag[id];
		tag[id]=0;
	}
	return;
}

void update(int L,int R,int id,int l,int r){
	pushdown(id);
	if(l<=L&&r>=R)tag[id]=1,pushdown(id);
	else{
		int M=(L+R)>>1;
		if(l<=M)update(L,M,Lid,l,r);
		else pushdown(Lid);
		if(r>M)update(M+1,R,Rid,l,r);
		else pushdown(Rid);
		sum[id]=sum[Lid]+sum[Rid];
	}
	return;
}

int query(int L,int R,int id,int l,int r){
	pushdown(id);
	if(l<=L&&r>=R)return sum[id];
	int M=(L+R)>>1,res=0;
	if(l<=M)res+=query(L,M,Lid,l,r);
	if(r>M)res+=query(M+1,R,Rid,l,r);
	return res;
}

int main(){
	n=read(),m=read();
	for(int i=2,fa;i<=n;i++){
		fa=read()+1;
		g[fa].push_back(i),g[i].push_back(fa);
	}
	dfs1(1,0,1),dfs2(1,1);
	build(1,n,1);
	for(int i=1,l,r,z;i<=m;i++){
		l=read()+1,r=read()+1,z=read()+1;
		q[i*2-1]=qu(l-1,-1,z,i);
		q[i*2]=qu(r,1,z,i);
	}
	sort(q+1,q+m*2+1);
	for(int i=1,j=1,u,res;i<=m*2;i++){
		while(j<=q[i].p){
			u=j++;
			while(u)update(1,n,1,dfn[top[u]],dfn[u]),u=fa[top[u]];
		}
		u=q[i].z,res=0;
		while(u)res=(res+query(1,n,1,dfn[top[u]],dfn[u]))%Mod,u=fa[top[u]];
		ans[q[i].id]+=q[i].ty*res;
	}
	for(int i=1;i<=m;i++)printf("%d\n",(ans[i]%Mod+Mod)%Mod);
	return 0;
}
