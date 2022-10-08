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
namespace fhq{
const int N=1e6+7;
int rt=0,tot=0,ans2=1e9+7;
struct node{int l,r,v,ky,sz;
node(int l=0,int r=0,int v=0,int ky=0,int sz=0):l(l),r(r),v(v),ky(ky),sz(sz){}}tree[N];
void update(int id){t.sz=tree[t.l].sz+tree[t.r].sz+1;return;}

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
	if(tree[t.l].sz>k)return kth(t.l,k);
	if(tree[t.l].sz+1<k)return kth(t.r,k-tree[t.l].sz-1);
	return id;
}

void Insert(int x){
	int l,r;
	split(rt,x,l,r);
	int lv=tree[kth(l,tl.sz)].v,rv=tree[kth(r,1)].v;
	if(l)ans2=min(ans2,abs(lv-x));
	if(r)ans2=min(ans2,abs(rv-x));
	tree[++tot]=node(0,0,x,rand(),1),rt=merge(merge(l,tot),r);
	return;
}
}//fhq

int read(){int qrx=0,qry=1;char qrc=getchar();
while(qrc<'0'||qrc>'9'){if(qrc=='-'){qry=-1,qrc=getchar();}else qrc=getchar();}
while(qrc>='0'&&qrc<='9')qrx=qrx*10+qrc-48,qrc=getchar();return qrx*qry;}

const int N=1e6+7,Mod=998244353,INF=1e9+7;
int n,m,a[N],rt,tot;
int sum[N];
multiset<int> ans1;
char op[N];
struct node{int l,r,v,ky,sz;
node(int l=0,int r=0,int v=0,int ky=0,int sz=0):l(l),r(r),v(v),ky(ky),sz(sz){}}tree[N];
void update(int id){t.sz=tree[t.l].sz+tree[t.r].sz+1;return;}

inline void ub(int& x){x+=(x&(-x));return;}
inline void db(int& x){x-=(x&(-x));return;}
inline void add(int x){for(;x<=n;ub(x))++sum[x];}
inline int q(int x){int k=0;for(;x;db(x))k+=sum[x];return k;}

void split(int id,int x,int& l,int& r){
	if(!id){l=r=0;return;}
	if(tree[t.l].sz<x)l=id,split(t.r,x-tree[t.l].sz-1,t.r,r);
	else if(tree[t.l].sz>=x)r=id,split(t.l,x,l,t.l);
	update(id);return;
}

int merge(int l,int r){
	if(!l||!r)return l^r;
	if(tl.ky>=tr.ky){tl.r=merge(tl.r,r),update(l);return l;}
	tr.l=merge(l,tr.l),update(r);return r;
}

int kth(int id,int k){
	if(k<=tree[t.l].sz)return kth(t.l,k);
	if(k>tree[t.l].sz+1)return kth(t.r,k-tree[t.l].sz-1);
	return id;
}

void Insert(int k,int x){
	int l,r;
	split(rt,k,l,r);
	int lv=0,rv=0;
	if(l)lv=tree[kth(l,tl.sz)].v;
	if(r)rv=tree[kth(r,1)].v;
	if(l&&r)if(ans1.count(abs(lv-rv)))ans1.erase(ans1.find(abs(lv-rv)));
	if(l)ans1.insert(abs(lv-x));
	if(r)ans1.insert(abs(rv-x));
	tree[++tot]=node(0,0,x,rand(),1),rt=merge(merge(l,tot),r);
	return;
}

void print(){
	printf("  < ");
	for(set<int>::iterator it=ans1.begin();it!=ans1.end();it++)printf("%d ",*it);
	printf(">\n");
	return;
}

signed main(){
	srand(time(0));
	n=read(),m=read();
	for(int i=1;i<=n;i++){
		a[i]=read();
		Insert(i-1,a[i]),add(i);
		fhq::Insert(a[i]);
	}
	
	for(int i=1;i<=m;i++){
		scanf("%s",op+1);
		if(op[1]=='I'){
			int k=read(),x=read();
			Insert(q(k),x),add(k);
			fhq::Insert(x);
		}
		else if(op[5]=='G')printf("%d\n",*ans1.begin());
		else if(op[5]=='S')printf("%d\n",fhq::ans2);
	}
	return 0;
}

