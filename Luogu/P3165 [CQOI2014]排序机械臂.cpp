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

const int N=2e5+7,Mod=998244353,INF=1e9;
int n,a[N],rt,tot;
struct val{int x,y;val(int x=0,int y=0):x(x),y(y){}
bool operator < (const val& A)const{return x==A.x?y<A.y:x<A.x;}}V[N];
struct node{int l,r,v,ky,sz,re,mn;node(int l=0,int r=0,int v=0,int ky=0,int sz=0,int re=0,int mn=0):l(l),r(r),v(v),ky(ky),sz(sz),re(re),mn(mn){}}tree[N];
inline void update(int id){t.sz=tree[t.l].sz+tree[t.r].sz+1,t.mn=min(min(tree[t.l].mn,tree[t.r].mn),t.v);return;}
inline void pushdown(int id){if(t.re)swap(t.l,t.r),tree[t.l].re^=1,tree[t.r].re^=1,t.re=0;return;}

void split_size(int id,int x,int& l,int& r){
	pushdown(id);
	if(!id){l=r=0;return;}
	if(tree[t.l].sz<x)l=id,split_size(t.r,x-tree[t.l].sz-1,t.r,r);
	else r=id,split_size(t.l,x,l,t.l);
	update(id);return;
}

int merge(int l,int r){
	pushdown(l),pushdown(r);
	if(!l||!r)return l^r;
	if(tl.ky<tr.ky){tl.r=merge(tl.r,r),update(l);return l;}
	tr.l=merge(l,tr.l),update(r);return r;
}

int find(int id,int x){
	pushdown(id);
	if(tree[t.l].mn==x)return find(t.l,x);
	if(t.v==x)return tree[t.l].sz;
	return find(t.r,x)+tree[t.l].sz+1;
}

signed main(){
	srand(time(0));
	n=read();
	tree[0]=node(0,0,0,0,0,0,INF);
	for(int i=1;i<=n;i++)a[i]=read(),V[i]=val(a[i],i);
	sort(V+1,V+n+1);
	for(int i=1;i<=n;i++)a[V[i].y]=i;
	for(int i=1;i<=n;i++)tree[++tot]=node(0,0,a[i],rand(),1,0,a[i]),rt=merge(rt,tot);
	for(int i=1,l,r;i<=n;i++){
		int p=find(rt,tree[rt].mn)+1;
		printf("%d ",p+i-1);
		split_size(rt,p,l,r);
		tl.re^=1,rt=merge(l,r);
		split_size(rt,1,l,rt);
	}
	printf("\n");
	return 0;
}

