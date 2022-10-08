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
#define Lid (id<<1)
#define Rid ((id<<1)|1)

using namespace std;

int read(){int qrx=0,qry=1;char qrc=getchar();
while(qrc<'0'||qrc>'9'){if(qrc=='-'){qry=-1,qrc=getchar();}else qrc=getchar();}
while(qrc>='0'&&qrc<='9')qrx=qrx*10+qrc-48,qrc=getchar();return qrx*qry;}

const int N=4e5+7,Mod=998244353,INF=1e9+7;
int n,m,a[N];
int dfn[N],cnt[N],fa[N],dep[N],son[N],top[N],ct,sum[N*2];
vector<int> g[N];

void dfs1(int u,int from,int d){
	fa[u]=from,dep[u]=d,cnt[u]=1;
	for(int i=0,v;i<signed(g[u].size());i++){
		v=g[u][i];
		if(v==from)continue;
		dfs1(v,u,d+1),cnt[u]+=cnt[v];
		if(cnt[v]>cnt[son[u]])son[u]=v;
	}
	return;
}

void dfs2(int u,int from,int tp){
	dfn[u]=++ct,top[u]=tp;
	if(son[u])dfs2(son[u],u,tp);
	for(int i=0,v;i<signed(g[u].size());i++){
		v=g[u][i];
		if(v==fa[u]||v==son[u])continue;
		dfs2(v,u,v);
	}
	return;
}

void update(int L,int R,int id,int p,int x){
	sum[id]+=x;
	if(L^R){
		int M=(L+R)>>1;
		if(p<=M)update(L,M,Lid,p,x);
		else update(M+1,R,Rid,p,x);
	}
	return;
}

int query(int L,int R,int id,int l,int r){
	if(l<=L&&r>=R)return sum[id];
	int M=(L+R)>>1;
	if(r<=M)return query(L,M,Lid,l,r);
	if(l>M)return query(M+1,R,Rid,l,r);
	return query(L,M,Lid,l,r)+query(M+1,R,Rid,l,r);
}

signed main(){
	n=read(),m=read();
	for(int i=1;i<=n;i++)a[i]=read();
	for(int i=1,u,v;i<n;i++){
		u=read(),v=read();
		g[u].push_back(v),g[v].push_back(u);
	}
	dfs1(1,0,0),dfs2(1,0,1);
	for(int i=1,op,p,x,u,ans;i<=m;i++){
		op=read();
		if(op==1){
			p=read(),x=read();
			if(dep[p]&1ll)x=-x;
			update(1,n,1,dfn[p],x);
		}
		else{
			p=u=read(),ans=0;
			while(u)ans+=query(1,n,1,dfn[top[u]],dfn[u]),u=fa[top[u]];
			if(dep[p]&1ll)ans=-ans;
			printf("%lld\n",a[p]+ans);
		}
	}
	return 0;
}
