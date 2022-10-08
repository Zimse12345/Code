#pragma GCC optimize(2)
#pragma GCC target("avx")
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

const int N=3e6+7,Mod=998244353,INF=1e9+7;
int n,T,a[N],b[N],c[N],m,rt,tot,ans[N];
struct node{
	int l,r,v,ky,sz,tag,mx;
	node(int l=0,int r=0,int v=0,int ky=0,int sz=0,int tag=0,int mx=0):l(l),r(r),v(v),ky(ky),sz(sz),tag(tag),mx(mx){}
}tree[N];
inline void pushdown(int id){if(id&&t.tag!=0)tree[t.l].tag+=t.tag,tree[t.r].tag+=t.tag,t.v+=t.tag,t.mx+=t.tag,t.tag=0;return;}
inline void update(int id){if(id)pushdown(id),pushdown(t.l),pushdown(t.r),t.sz=tree[t.l].sz+tree[t.r].sz+1,t.mx=max(max(tree[t.l].mx,tree[t.r].mx),t.v);return;}

void split_val(int id,int x,int& l,int& r){
	if(!id){l=r=0;return;}
	pushdown(id);
	if(t.v<=x)l=id,split_val(t.r,x,t.r,r);
	if(t.v>x)r=id,split_val(t.l,x,l,t.l);
	update(id);
	return;
}

int merge(int l,int r){
	pushdown(l),pushdown(r);
	if(!l||!r)return l+r;
	if(tl.ky<=tr.ky){tl.r=merge(tl.r,r),update(l);return l;}
	tr.l=merge(l,tr.l),update(r);return r;
}

void ins(int x){
	int l,r;
	split_val(rt,0,l,r);
	tree[++tot]=node(0,0,x,rand(),1,0,x);
	rt=merge(merge(l,tot),r);
	return;
}

void era(int x){
	int l,r,mid;
	split_val(rt,x,l,r);
	split_val(l,x-1,l,mid);
	rt=merge(merge(l,tree[mid].l),merge(tree[mid].r,r));
	return;
}

signed main(){
	n=read(),T=read();
	for(int i=1;i<=n;i++)a[i]=read();
	for(int i=1,s=0;i<=n;i++){
		if(a[i]==1)b[++m]=s,s=0;
		else ++s;
	}
	for(int i=1,L=1,l,r;i<=m;i++){
		c[i]=c[i-1]+b[i];
		tree[rt].tag+=1-b[i];
		pushdown(rt);
		ins(0);
		while(L<=i){
			split_val(rt,0,l,r);
			int tt=c[i]-c[L-1]+tree[r].mx;
			rt=merge(l,r);
			if(tt>T)era(i-L-c[i]+c[L]),++L;
			else break;
		}
		split_val(rt,0,l,r);
		int tt=c[i]-c[L-1]+max(tree[r].mx,i-L+1-c[i]+c[L-1]);
		rt=merge(l,r);
		int rm=T-tt;
		int x=c[i]-c[L-1];
		if(rm>0)x+=min(rm,b[L-1]);
		ans[i]=x;
	}
	int ss=0;
	for(int i=1;i<=m;i++){
		ans[i]=c[i]-ans[i]-ss,ss+=ans[i];
		for(int j=1;j<=ans[i];j++)printf("0 "),--n;
		printf("1 "),--n;
	}
	if(n<=0)return 0;
	while(n--)printf("0 ");
	printf("\n");
	return 0;
}

