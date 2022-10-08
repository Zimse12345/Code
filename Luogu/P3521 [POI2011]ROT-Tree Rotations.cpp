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

int read(){int qrx=0,qry=1;char qrc=getchar();
while(qrc<'0'||qrc>'9'){if(qrc=='-'){qry=-1,qrc=getchar();}else qrc=getchar();}
while(qrc>='0'&&qrc<='9')qrx=qrx*10+qrc-48,qrc=getchar();return qrx*qry;}

const int N=4e5+7,Mod=998244353,INF=1e9+7;
int n,ct=1,tot,rt[N];ll ans;
stack<int> rbs;
struct node{int l,r,v;short ky;int sz;node(int l=0,int r=0,int v=0,short ky=0,int sz=0):l(l),r(r),v(v),ky(ky),sz(sz){}}tree[N/2];
inline void update(int id){t.sz=tree[t.l].sz+tree[t.r].sz+1;return;}
inline int newnode(){if(rbs.empty())return ++tot;int res=rbs.top();rbs.pop();return res;}

void split(int id,int x,int& l,int& r){
	if(!id){l=r=0;return;}
	if(t.v<=x)l=id,split(t.r,x,t.r,r);
	else r=id,split(t.l,x,l,t.l);
	update(id);return;
}

int merge(int l,int r){
	if(!l||!r)return l^r;
	if(tl.ky>=tr.ky){tl.r=merge(tl.r,r),update(l);return l;}
	tr.l=merge(l,tr.l),update(r);return r;
}

int kth(int id,int k){
	if(tree[t.l].sz>=k)return kth(t.l,k);
	if(tree[t.l].sz+1<k)return kth(t.r,k-tree[t.l].sz-1);
	return id;
}

void Insert(int& id,int x){
	int l,r,nn=newnode();
	split(id,x,l,r),tree[nn]=node(0,0,x,rand(),1),id=merge(merge(l,nn),r);
	return;
}

ll dfs(int from,int& to){
	if(!from)return 0;
	int l,r,x=tree[from].v;
	split(to,x,l,r);
	ll res=tree[r].sz;
	to=merge(l,r),res+=dfs(tree[from].l,to)+dfs(tree[from].r,to);
	rbs.push(from),Insert(to,x);
	return res;
}

void readtree(int u){
	int x=read();
	if(x==0){
		int lc=++ct,rc=++ct;
		readtree(lc),readtree(rc);
		if(tree[rt[lc]].sz<tree[rt[rc]].sz)swap(lc,rc);
		ll q=1ll*tree[rt[lc]].sz*tree[rt[rc]].sz,p=dfs(rt[rc],rt[lc]);
		ans+=min(p,q-p),rt[u]=rt[lc];
	}
	else Insert(rt[u],x);
	return;
}

signed main(){
	srand(time(0));
	n=read();
	readtree(1);
	printf("%lld\n",ans);
	return 0;
}

