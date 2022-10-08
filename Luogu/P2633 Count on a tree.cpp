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
#define Lid ch[id][0]
#define Rid ch[id][1]

using namespace std;

int read(){int qrx=0,qry=1;char qrc=getchar();
while(qrc<'0'||qrc>'9'){if(qrc=='-'){qry=-1,qrc=getchar();}else qrc=getchar();}
while(qrc>='0'&&qrc<='9')qrx=qrx*10+qrc-48,qrc=getchar();return qrx*qry;}

const int N=2e5+7,M=4e6+7,INF=1e9+7;
int n,m,a[N];
int to[N],nxt[N],hd[N],ec;
int fa[N],cnt[N],dep[N],son[N],dfn[N],top[N],ct;
int sum[M],ch[M][2],Rt[N],tot;
inline void add(int u,int v){to[++ec]=v,nxt[ec]=hd[u],hd[u]=ec;return;}

void update(int L,int R,int id,int _id,int x){
	Lid=ch[_id][0],Rid=ch[_id][1],++sum[id];
	if(L==R)return;
	int M=(1ll*L+R)>>1ll;
	if(x<=M)Lid=++tot,sum[Lid]=sum[ch[_id][0]],update(L,M,Lid,ch[_id][0],x);
	else Rid=++tot,sum[Rid]=sum[ch[_id][1]],update(M+1,R,Rid,ch[_id][1],x);
	return;
}

int query(int L,int R,int id1,int id2,int id3,int id4,int k){
	if(L==R)return L;
	int M=(1ll*L+R)>>1ll;
	int lv=sum[ch[id1][0]]+sum[ch[id2][0]]-sum[ch[id3][0]]-sum[ch[id4][0]];
	if(k<=lv)return query(L,M,ch[id1][0],ch[id2][0],ch[id3][0],ch[id4][0],k);
	return query(M+1,R,ch[id1][1],ch[id2][1],ch[id3][1],ch[id4][1],k-lv);
}

void dfs1(int u,int from,int dp){
	fa[u]=from,cnt[u]=1,dep[u]=dp;
	for(int i=hd[u],v;i;i=nxt[i]){
		v=to[i];
		if(v==from)continue;
		dfs1(v,u,dp+1),cnt[u]+=cnt[v];
		if(cnt[v]>cnt[son[u]])son[u]=v;
	}
	return;
}

void dfs2(int u,int from,int tp){
	dfn[u]=++ec,top[u]=tp;
	Rt[u]=++tot,update(1,2147483647,Rt[u],Rt[fa[u]],a[u]);
	if(son[u])dfs2(son[u],u,tp);
	for(int i=hd[u],v;i;i=nxt[i]){
		v=to[i];
		if(v==from||v==son[u])continue;
		dfs2(v,u,v);
	}
	return;
}

int LCA(int u,int v){
	while(top[u]^top[v]){
		if(dep[top[u]]<dep[top[v]])swap(u,v);
		u=fa[top[u]];
	}
	if(dep[u]<dep[v])return u;
	return v;
}

signed main(){
	n=read(),m=read();
	for(int i=1;i<=n;i++)a[i]=read();
	for(int i=1,u,v;i<n;i++)u=read(),v=read(),add(u,v),add(v,u);
	dfs1(1,0,0),dfs2(1,0,1);
	for(int i=1,u,v,k,ans=0;i<=m;i++){
		u=read()^ans,v=read(),k=read(),ans=0;
		int lca=LCA(u,v);
		ans=query(1,2147483647,Rt[u],Rt[v],Rt[lca],Rt[fa[lca]],k);
		printf("%d\n",ans);
	}
	return 0;
}
