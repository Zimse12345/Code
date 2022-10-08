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
inline void write(int x){if(x<0){putchar('-'),x=-x;}if(x>9)write(x/10);putchar(x%10+'0');}

const int N=5e5+7,Mod=998244353,INF=1e9+7;
struct node{int l,r,v,ky,sz,tag;
node(int l=0,int r=0,int v=0,int ky=0,int sz=0):l(l),r(r),v(v),ky(ky),sz(sz){}}tree[N];
struct query{int l,r,k,id;query(int l=0,int r=0,int k=0,int id=0):l(l),r(r),k(k),id(id){}
bool operator < (const query& A)const{return l<A.l;}}q[N];
inline void update(int id){t.sz=tree[t.l].sz+tree[t.r].sz+1;return;}
int n,m,rt,tot,a[N],ans[N];

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

void Insert(int x){
	int l,r;
	split(rt,x,l,r),tree[++tot]=node(0,0,x,rand(),1),rt=merge(merge(l,tot),r);
	return;
}

void Erase(int x){
	int l,r,m;
	split(rt,x,l,r),split(l,x-1,l,m);
	rt=merge(merge(l,tree[m].l),merge(tree[m].r,r));
	return;
}

int main(){
	srand(time(0));
	n=read(),m=read();
	for(int i=1;i<=n;i++)a[i]=read();
	for(int i=1,l,r,k;i<=m;i++)l=read(),r=read(),k=read(),q[i]=query(l,r,k,i);
	sort(q+1,q+m+1);
	for(int i=1,L=1,R=0,l,r,k;i<=m;i++){
		l=q[i].l,r=q[i].r,k=q[i].k;
		while(R<r)Insert(a[++R]);
		while(L<l)Erase(a[L++]);
		ans[q[i].id]=tree[kth(rt,k)].v;
	}
	for(int i=1;i<=m;i++)printf("%d\n",ans[i]);
	return 0;
}

