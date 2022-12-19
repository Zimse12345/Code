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

#define t tree[id]
#define tl tree[l]
#define tr tree[r]
#define int long long

using namespace std;

int read(){int qrx=0,qry=1;char qrc=getchar();
while(qrc<'0'||qrc>'9'){if(qrc=='-'){qry=-1,qrc=getchar();}else qrc=getchar();}
while(qrc>='0'&&qrc<='9')qrx=qrx*10+qrc-48,qrc=getchar();return qrx*qry;}

const int N=1e6+7,Mod=998244353,INF=1e9+7;
int n,rt,cnt;
struct fhq{int l,r,v,ky,siz,sum;
fhq(int l=0,int r=0,int v=0,int ky=0,int siz=0,int sum=0):l(l),r(r),v(v),ky(ky),siz(siz),sum(sum){}}tree[N];
void update(int id){t.siz=tree[t.l].siz+tree[t.r].siz+1,t.sum=tree[t.l].sum+tree[t.r].sum+t.v;return;}

void split(int id,int x,int& l,int& r){
	if(!id){l=r=0;return;}
	if(t.v<=x)l=id,split(t.r,x,t.r,r);
	else r=id,split(t.l,x,l,t.l);
	update(id);return;
}

void Split(int id,int x,int& l,int& r){
	if(!id){l=r=0;return;}
	if(tree[t.l].siz<x)l=id,Split(t.r,x-tree[t.l].siz-1,t.r,r);
	else r=id,Split(t.l,x,l,t.l);
	update(id);return;
}

int merge(int l,int r){
	if(!l||!r)return l^r;
	if(tl.ky>tr.ky){tl.r=merge(tl.r,r),update(l);return l;}
	tr.l=merge(l,tr.l),update(r);return r;
}

int kth(int id,int k){
	if(k<=tree[t.l].siz)return kth(t.l,k);
	if(k>tree[t.l].siz+1)return kth(t.r,k-tree[t.l].siz-1);
	return id;
}

int a[1000001];

void ins(int x){
	int l,r;
	split(rt,x,l,r),tree[++cnt]=fhq(0,0,x,rand(),1,x),rt=merge(merge(l,cnt),r);
	return;
}

void del(int x){
	int l,r,p;
	split(rt,x,l,r),split(l,x-1,l,p),rt=merge(merge(l,tree[p].l),merge(tree[p].r,r));
	return;
}

signed main(){
	srand(time(0));
	n=read();
	int m=read(),k=read();
	for(int i=1;i<=n;i++)a[i]=read();
	for(int i=1;i<m;i++)ins(a[i]);
	for(int i=m;i<=n;i++){
		ins(a[i]);
		int l,r;
		Split(rt,k,l,r);
		printf("%lld ",tree[l].sum);
//		_write(tree[l].sum);
		rt=merge(l,r);
		del(a[i-m+1]);
	}
	printf("\n");
//	for(int i=1,p,op,x;i<=n;i++){
//		op=read(),x=read();
//		int l,r;
//		if(op==1)split(rt,x,l,r),tree[++cnt]=fhq(0,0,x,rand(),1),rt=merge(merge(l,cnt),r);
//		if(op==2)split(rt,x,l,r),split(l,x-1,l,p),rt=merge(merge(l,tree[p].l),merge(tree[p].r,r));
//		if(op==3)split(rt,x-1,l,r),printf("%d\n",tl.siz+1),rt=merge(l,r);
//		if(op==4)printf("%d\n",tree[kth(rt,x)].v);
//		if(op==5)split(rt,x-1,l,r),printf("%d\n",tree[kth(l,tl.siz)].v),rt=merge(l,r);
//		if(op==6)split(rt,x,l,r),printf("%d\n",tree[kth(r,1)].v),rt=merge(l,r);
//	}
	return 0;
}
