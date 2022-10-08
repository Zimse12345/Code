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
inline void yes(){printf("YES\n");return;}
inline void no(){printf("NO\n");return;}

const int N=2e5+7,Mod=998244353,INF=1e9+7;
int n,q,a[N],val[N];
int hd[N],nxt[N],to[N],ec;
int fa[N],dep[N],cnt[N],son[N],dfn[N],top[N],ct;
int tag[N*4],d[100];
char op[100];
inline void add(int u,int v){nxt[++ec]=hd[u],hd[u]=ec,to[ec]=v;return;}

bool ins(int x){
	for(int i=30;i>=0;i--)if(x&(1<<i)){
		if(!d[i]){
			d[i]=x;
			return true;
		}
		x^=d[i];
	}
	return false;
}

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
	dfn[u]=++ct,top[u]=t;
	if(son[u])dfs2(son[u],u,t);
	for(int i=hd[u],v;i;i=nxt[i]){
		v=to[i];
		if(v==from||v==son[u])continue;
		dfs2(v,u,v);
	}
	return;
}

int LCA(int x,int y){
	while(top[x]^top[y]){
		if(dep[top[x]]<dep[top[y]])swap(x,y);
		x=fa[top[x]];
	}
	if(dfn[y]<dfn[x])return y;
	return x;
}

void update(int L,int R,int id,int l,int r,int x){
	if(l>R||L>r)return;
	if(l<=L&&r>=R)tag[id]^=x;
	else update(L,M,Lid,l,r,x),update(M+1,R,Rid,l,r,x);
	return;
}

int query(int L,int R,int id,int x){
	if(L==R)return tag[id]^val[x];
	if(x<=M)return tag[id]^query(L,M,Lid,x);
	return tag[id]^query(M+1,R,Rid,x);
}

signed main(){
	n=read(),q=read();
	for(int i=1;i<=n;i++)a[i]=read();
	for(int i=1,u,v;i<n;i++)u=read(),v=read(),add(u,v),add(v,u);
	dfs1(1,0,1),dfs2(1,0,1);
	for(int i=1;i<=n;i++)val[dfn[i]]=a[i];
	
	for(int i=1,x,y,z;i<=q;i++){
		scanf("%s",op);
		x=read(),y=read();
		if(op[0]=='Q'){
			for(int j=0;j<=30;j++)d[j]=0;
			int lca=LCA(x,y),p=0;
			while(x!=lca){
				if(!ins(query(1,n,1,dfn[x]))){
					p=1;
					break;
				}
				x=fa[x];
			}
			if(p){yes();continue;}
			while(y!=lca){
				if(!ins(query(1,n,1,dfn[y]))){
					p=1;
					break;
				}
				y=fa[y];
			}
			if(!ins(query(1,n,1,dfn[lca])))p=1;
			if(p)yes();
			else no();
		}
		else{
			z=read();
			while(top[x]^top[y]){
				if(dep[top[x]]<dep[top[y]])swap(x,y);
				update(1,n,1,dfn[top[x]],dfn[x],z),x=fa[top[x]];
			}
			if(dfn[y]<dfn[x])swap(x,y);
			update(1,n,1,dfn[x],dfn[y],z);
		}
	}
	return 0;
}

