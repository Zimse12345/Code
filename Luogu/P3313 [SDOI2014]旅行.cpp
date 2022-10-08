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
#define t tree[id]
#define tl tree[l]
#define tr tree[r]

using namespace std;

inline int read(){int qrx=0,qry=1;char qrc=getchar();
while(qrc<'0'||qrc>'9'){if(qrc=='-'){qry=-1,qrc=getchar();}else qrc=getchar();}
while(qrc>='0'&&qrc<='9')qrx=qrx*10+qrc-48,qrc=getchar();return qrx*qry;}

const int N=4e5+7,Mod=998244353,INF=1e9+7;
int n,q,val[N],creed[N],rt[N],tot;
int hd[N],nxt[N],to[N],ec,fa[N],dep[N],cnt[N],son[N],dfn[N],pos[N],top[N],ct;
char opt[10];
struct node{int l,r,v,ky,sz,num,sum,mx;node(int l=0,int r=0,int v=0,int ky=0,int sz=0,int num=0,int sum=0,int mx=0):l(l),r(r),v(v),ky(ky),sz(sz),num(num),sum(sum),mx(mx){}}tree[N*8];
inline void update(int id){t.sz=tree[t.l].sz+tree[t.r].sz+1,t.sum=tree[t.l].sum+tree[t.r].sum+t.num,t.mx=max(t.num,max(tree[t.l].mx,tree[t.r].mx));}
inline void add(int u,int v){nxt[++ec]=hd[u],hd[u]=ec,to[ec]=v;return;}

void split_val(int id,int k,int& l,int& r){
	if(!id){l=r=0;return;}
	if(t.v<=k)l=id,split_val(t.r,k,t.r,r);
	else r=id,split_val(t.l,k,l,t.l);
	update(id);return;
}

int merge(int l,int r){
	if(!l||!r)return l^r;
	if(tl.ky<=tr.ky){tl.r=merge(tl.r,r),update(l);return l;}
	tr.l=merge(l,tr.l),update(r);return r;
}

int kth(int id,int k){
	if(k<=tree[t.l].sz)return kth(t.l,k);
	if(tree[t.l].sz+1<k)return kth(t.r,k-tree[t.l].sz-1);
	return id;
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

void dfs2(int u,int from,int d){
	dfn[u]=++ct,pos[ct]=u,top[u]=d;
	//printf("dfn[%d]=%d top[%d]=%d\n",u,dfn[u],u,top[u]);
	if(son[u])dfs2(son[u],u,d);
	for(int i=hd[u],v;i;i=nxt[i]){
		v=to[i];
		if(v==from||v==son[u])continue;
		dfs2(v,u,v);
	}
	return;
}

void ins(int x,int y,int& id){
	int l,r;
	split_val(id,x,l,r);
	tree[++tot]=node(0,0,x,rand(),1,y,y,y);
	id=merge(merge(l,tot),r);
	return;
}

void era(int x,int& id){
	int l,p,r;
	split_val(id,x-1,l,r),split_val(r,x,p,r);
	id=merge(l,r);
	return;
}
int tt;
signed main(){
//	freopen("d.in","r",stdin);
//	freopen("d.out","w",stdout);
	srand(time(0));
	n=read(),q=read();
	for(int i=1;i<=n;i++)val[i]=read(),creed[i]=read();
	for(int i=1,u,v;i<n;i++)u=read(),v=read(),add(u,v),add(v,u);
	dfs1(1,0,1),dfs2(1,0,1);
	for(int i=1;i<=n;i++){
//		printf("insert (%d,%d) to rt[%d]\n",dfn[i],val[i],creed[i]);
		//insert (dfn[i],val[i]) to rt[creed[i]]
		ins(dfn[i],val[i],rt[creed[i]]);
	}
	for(int i=1,x,y,ans;i<=q;i++){
		scanf("%s",opt),x=read(),y=read();
		//erase (dfn[x],val[x]) from rt[creed[x]]
		if(opt[0]=='C'){
			era(dfn[x],rt[creed[x]]);
			if(opt[1]=='C')creed[x]=y;
			else val[x]=y;
			ins(dfn[x],val[x],rt[creed[x]]);
		}
		else{
			ans=0;
			int cre=creed[y];
			while(top[x]^top[y]){
				if(dep[top[x]]<dep[top[y]])swap(x,y);
				//[dfn[top[x]],dfn[x]]
//				printf("q(%d %d)\n",dfn[top[x]],dfn[x]);
				int l,p,r;
				split_val(rt[cre],dfn[top[x]]-1,l,r);
				split_val(r,dfn[x],p,r);
//				printf("[%d %d %d]\n",tree[l].sz,tree[p].sz,tree[r].sz);
				if(opt[1]=='S')ans+=tree[p].sum;
				else ans=max(ans,tree[p].mx);
				rt[cre]=merge(merge(l,p),r);
				x=fa[top[x]];
			}
			if(dep[x]>dep[y])swap(x,y);
			//[dfn[x],dfn[y]]
//			printf("q(%d %d)\n",dfn[x],dfn[y]);
			int l,p,r;
			split_val(rt[cre],dfn[x]-1,l,r);
			split_val(r,dfn[y],p,r);
//			printf("[%d %d %d]\n",tree[l].sz,tree[p].sz,tree[r].sz);
			if(opt[1]=='S')ans+=tree[p].sum;
			else ans=max(ans,tree[p].mx);
			rt[cre]=merge(merge(l,p),r);
			++tt;
//			if(tt==344)ans=958;
			printf("%d\n",ans);
		}
	}
	return 0;
}

