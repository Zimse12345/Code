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

const int N=4e5+7,Mod=998244353,INF=1e9+7;
int n,m;
int fa[N],cnt[N],dep[N],son[N],dfn[N],top[N],ct,c[N],e[N],sw[N],sid[N];
int sum[N*4],mx[N*4],mi[N*4],tag[N*4],len[N*4];
char s[N];
struct edge{
	int to,w,id;
	edge(int to=0,int w=0,int id=0):to(to),w(w),id(id){}
};
vector<edge> g[N];

void dfs1(int u,int from,int dp){
	fa[u]=from,cnt[u]=1,dep[u]=dp;
	for(int i=0,v;i<signed(g[u].size());i++){
		v=g[u][i].to;
		if(v==from)continue;
		dfs1(v,u,dp+1),cnt[u]+=cnt[v];
		if(cnt[v]>cnt[son[u]])son[u]=v,sw[u]=g[u][i].w,sid[u]=g[u][i].id;
	}
	return;
}

void dfs2(int u,int tp,int from,int fw,int fid){
	dfn[u]=++ct,top[u]=tp,c[dfn[u]]=fw,e[fid]=ct;
	if(son[u])dfs2(son[u],tp,u,sw[u],sid[u]);
	for(int i=0,v;i<signed(g[u].size());i++){
		v=g[u][i].to;
		if(v==from||v==son[u])continue;
		dfs2(v,v,u,g[u][i].w,g[u][i].id);
	}
	return;
}

void pushup(int id){
	sum[id]=sum[Lid]+sum[Rid];
	mx[id]=max(mx[Lid],mx[Rid]),mi[id]=min(mi[Lid],mi[Rid]);
	return;
}

void pushdown(int id){
	if(tag[id]){
		sum[id]=-sum[id],swap(mx[id],mi[id]),mx[id]=-mx[id],mi[id]=-mi[id];
		if(len[id]>1)tag[Lid]^=1,tag[Rid]^=1;
		tag[id]=0;
	}
	return;
}

void build(int L,int R,int id){
	tag[id]=0,len[id]=R-L+1;
	if(L==R)sum[id]=mx[id]=mi[id]=c[L];
	else{
		int M=(L+R)>>1;
		build(L,M,Lid),build(M+1,R,Rid);
		pushup(id); 
	}
	return;
}

void update1(int L,int R,int id,int p,int x){
	pushdown(id);
	if(L==R)sum[id]=mx[id]=mi[id]=x;
	else{
		int M=(L+R)>>1;
		if(p<=M)update1(L,M,Lid,p,x);
		else pushdown(Lid);
		if(p>M)update1(M+1,R,Rid,p,x);
		else pushdown(Rid);
		pushup(id);
	}
	return;
}

void update2(int L,int R,int id,int l,int r){
	pushdown(id);
	if(l<=L&&r>=R)tag[id]=1,pushdown(id);
	else{
		int M=(L+R)>>1;
		if(l<=M)update2(L,M,Lid,l,r);
		else pushdown(Lid);
		if(r>M)update2(M+1,R,Rid,l,r);
		else pushdown(Rid);
		pushup(id);
	}
	return;
}

int query(int L,int R,int id,int l,int r,int ty){
	pushdown(id);
	int M=(L+R)>>1,res=0;
	if(l<=L&&r>=R){
		if(ty==1)res=sum[id];
		if(ty==2)res=mx[id];
		if(ty==3)res=mi[id];
	}
	else if(r<=M)return query(L,M,Lid,l,r,ty);
	else if(l>M)return query(M+1,R,Rid,l,r,ty);
	else{
		if(ty==1)res=query(L,M,Lid,l,r,ty)+query(M+1,R,Rid,l,r,ty);
		if(ty==2)res=max(query(L,M,Lid,l,r,ty),query(M+1,R,Rid,l,r,ty));
		if(ty==3)res=min(query(L,M,Lid,l,r,ty),query(M+1,R,Rid,l,r,ty));
	}
	return res;
}

int update(int ans,int x,int y,int ty){
	if(ty==1)return ans+query(1,n,1,x,y,ty);
	if(ty==2)return max(ans,query(1,n,1,x,y,ty));
	return min(ans,query(1,n,1,x,y,ty));
}

int main(){
	n=read();
	for(int i=1,u,v,w;i<n;i++){
		u=read()+1,v=read()+1,w=read();
		g[u].push_back(edge(v,w,i)),g[v].push_back(edge(u,w,i));
	}
	dfs1(1,0,0),dfs2(1,1,0,0,0),build(1,n,1);
	m=read();
	for(int i=1,op,x,y,ans;i<=m;i++){
		scanf("%s",s+1);
		if(s[1]=='C')op=1;
		else if(s[1]=='N')op=2;
		else if(s[1]=='S')op=3;
		else if(s[2]=='A')op=4;
		else op=5;
		x=read(),y=read();
		if(op!=1)++x,++y;
		if(op==1)update1(1,n,1,e[x],y);
		else if(op==2){
			while(top[x]!=top[y]){
				if(dep[top[x]]<dep[top[y]])swap(x,y);
				update2(1,n,1,dfn[top[x]],dfn[x]),x=fa[top[x]];
			}
			if(dep[x]>dep[y])swap(x,y);
			if(x!=y)update2(1,n,1,dfn[x]+1,dfn[y]);
		}
		else{
			op-=2;
			if(op==1)ans=0;if(op==2)ans=-INF;if(op==3)ans=INF;
			while(top[x]!=top[y]){
				if(dep[top[x]]<dep[top[y]])swap(x,y);
				ans=update(ans,dfn[top[x]],dfn[x],op),x=fa[top[x]];
			}
			if(dep[x]>dep[y])swap(x,y);
			if(x!=y)ans=update(ans,dfn[x]+1,dfn[y],op);
			printf("%d\n",ans);
		}
	}
	return 0;
}
