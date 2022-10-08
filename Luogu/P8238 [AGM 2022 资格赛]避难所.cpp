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
#define M ((L+R)>>1)
#define Lid (id<<1)
#define Rid ((id<<1)|1)

using namespace std;

inline int read(){int qrx=0,qry=1;char qrc=getchar();
while(qrc<'0'||qrc>'9'){if(qrc=='-'){qry=-1,qrc=getchar();}else qrc=getchar();}
while(qrc>='0'&&qrc<='9')qrx=qrx*10+qrc-48,qrc=getchar();return qrx*qry;}

const int N=2e5+7,Mod=998244353,INF=1e9+7;
int n,q,hd[N],nxt[N],to[N],ec,fa[N],dep[N],cnt[N],son[N],dfn[N],top[N],ct,s[N*4],a[N],sta[N];
set<int> S;
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

void dfs2(int u,int from,int d){
	dfn[u]=++ct,top[u]=d;
	if(son[u])dfs2(son[u],u,d);
	for(int i=hd[u],v;i;i=nxt[i]){
		v=to[i];
		if(v==from||v==son[u])continue;
		dfs2(v,u,v);
	}
	return;
}

void update(int L,int R,int id,int l,int r,int x){
	if(l<=L&&r>=R)s[id]+=x;
	else{
		if(l<=M)update(L,M,Lid,l,r,x);
		if(r>M)update(M+1,R,Rid,l,r,x);
	}
	return;
}

int query(int L,int R,int id,int x){
	if(L==R)return s[id];
	if(x<=M)return s[id]+query(L,M,Lid,x);
	return s[id]+query(M+1,R,Rid,x);
}

void upt(int x,int y){
	while(x){
		int l=dfn[top[x]],r=dfn[x];
		set<int>::iterator it=S.upper_bound(r);--it;
		if(l<=(*it)){update(1,n,1,*it,r,y);break;}
		update(1,n,1,l,r,y),x=fa[top[x]];
	}
	return;
}

signed main(){
	n=read(),q=read(),S.insert(n+1),S.insert(0);
	for(int i=1,u,v;i<n;i++)u=read(),v=read(),add(u,v),add(v,u);
	dfs1(1,0,1),dfs2(1,0,1);
	for(int i=1;i<=n;i++)a[i]=read(),upt(i,a[i]);
	for(int i=1,op,x,y;i<=q;i++){
		op=read();
		if(op==1){
			x=read(),y=read();
			upt(x,-a[x]+y),a[x]=y;
		}
		else{
			x=read(),y=query(1,n,1,dfn[x]);
			if(sta[x])upt(fa[x],y),S.erase(dfn[x]);
			else upt(fa[x],-y),S.insert(dfn[x]);
			sta[x]^=1;
		}
		printf("%lld\n",query(1,n,1,dfn[1]));
	}
	return 0;
}

