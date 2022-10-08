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
#define M ((L+R)>>1)
#define Lid (id<<1)
#define Rid ((id<<1)|1)

using namespace std;

int read(){int qrx=0,qry=1;char qrc=getchar();
while(qrc<'0'||qrc>'9'){if(qrc=='-'){qry=-1,qrc=getchar();}else qrc=getchar();}
while(qrc>='0'&&qrc<='9')qrx=qrx*10+qrc-48,qrc=getchar();return qrx*qry;}

const int N=1e6+7,Mod=998244353,INF=1e9+7;
int n,q,hd[N],nxt[N],to[N],ec,val[N];
int fa[N],dep[N],cnt[N],son[N],dfn[N],tp[N],ct;
int c1[N],c2[N*4],c3[N*4];
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
	dfn[u]=++ct,tp[u]=t;
	if(son[u])dfs2(son[u],u,t);
	for(int i=hd[u],v;i;i=nxt[i]){
		v=to[i];
		if(v==from||v==son[u])continue;
		dfs2(v,u,v);
	}
	return;
}

int lca(int u,int v){
	while(tp[u]^tp[v]){
		if(dep[tp[u]]<dep[tp[v]])swap(u,v);
		u=fa[tp[u]];
	}
	if(dep[u]<dep[v])return u;
	return v;
}

void update1(int L,int R,int id,int l,int r){
	if(r<L||R<l)return;
	if(l<=L&&r>=R)c2[id]++;
	else update1(L,M,Lid,l,r),update1(M+1,R,Rid,l,r);
	return;
}

void update2(int L,int R,int id,int l,int r){
	if(r<L||R<l)return;
	if(l<=L&&r>=R)c3[id]++;
	else update2(L,M,Lid,l,r),update2(M+1,R,Rid,l,r);
	return;
}

int query1(int L,int R,int id,int x){
	if(L==R)return c2[id];
	if(x<=M)return c2[id]+query1(L,M,Lid,x);
	return c2[id]+query1(M+1,R,Rid,x);
}

int query2(int L,int R,int id,int x){
	if(L==R)return c3[id];
	if(x<=M)return c3[id]+query2(L,M,Lid,x);
	return c3[id]+query2(M+1,R,Rid,x);
}

signed main(){
//	freopen("d.in","r",stdin);
//	freopen("d.out","w",stdout);
	n=read(),q=read();
	for(int i=1;i<=n;i++)val[i]=read(); 
	for(int i=1,u,v;i<n;i++)u=read(),v=read(),add(u,v),add(v,u);
	dfs1(1,0,1),dfs2(1,0,1);
	for(int i=1,op,x,y;i<=q;i++){
		op=read();
		if(op==1){
			x=read(),y=read();
			int mid=lca(x,y);
			while(dep[tp[x]]>dep[mid]){
				//printf("A[%d,%d]\n",dfn[tp[x]],dfn[x]-1);
				update1(1,n,1,dfn[tp[x]],dfn[fa[x]]),x=tp[x],c1[fa[x]]+=val[x],x=fa[x];
			}
			//printf("B[%d,%d]\n",dfn[mid],dfn[fa[x]]);
			update1(1,n,1,dfn[mid],dfn[fa[x]]);
			
			while(dep[tp[y]]>dep[mid]){//printf("C[%d,%d]\n",dfn[tp[y]],dfn[y]);
				update2(1,n,1,dfn[tp[y]],dfn[y]);
				y=fa[tp[y]];
			}
//			printf("D[%d,%d]\n",dfn[mid]+1,dfn[y]);
			update2(1,n,1,dfn[mid]+1,dfn[y]);
		}
		else{
			x=read();
			printf("%lld\n",c1[x]+query1(1,n,1,dfn[x])*val[son[x]]+query2(1,n,1,dfn[x])*val[fa[x]]);
		}
	}
	return 0;
}

