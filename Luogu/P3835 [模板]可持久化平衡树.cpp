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

const int N=3e7+7,Mod=998244353,INF=2147483647;
int n,tot,rt[N],ver;
struct node{int l,r,v,ky,sz;}tree[N];
inline void update(int id){t.sz=tree[t.l].sz+tree[t.r].sz+1;return;}

inline void split(int id,int x,int& l,int& r){
	if(!id){l=r=0;return;}
	if(t.v<=x){
		l=++tot,tl=t,split(t.r,x,tl.r,r);
		update(l);
	}
	else{
		r=++tot,tr=t,split(t.l,x,l,tr.l);
		update(r);
	}
	return;
}

inline int merge(int l,int r){
	if(!l||!r)return l^r;
	int id=++tot;
	if(tl.ky<tr.ky){
		t=tl;
		t.r=merge(tl.r,r);
	}
	else{
		t=tr;
		t.l=merge(l,tr.l);
	}
	update(id);
	return id;
}

inline int kth(int id,int k){
	if(k<=tree[t.l].sz)return kth(t.l,k);
	if(tree[t.l].sz+1<k)return kth(t.r,k-tree[t.l].sz-1);
	return id;
}

signed main(){
	srand(time(0));
	n=read();
	for(int i=1,p,op,x,l,r,m;i<=n;i++){
		p=read(),op=read(),x=read(),rt[i]=rt[p];
		if(op==1){
			split(rt[p],x,l,r);
			++tot;
			tree[tot].l=tree[tot].r=0,tree[tot].v=x,tree[tot].ky=rand(),tree[tot].sz=1;
			rt[i]=merge(merge(l,tot),r);
		}
		if(op==2){
			split(rt[p],x,l,r);
			split(l,x-1,l,m);
			rt[i]=merge(merge(l,tree[m].l),merge(tree[m].r,r));
		}
		if(op==3){
			split(rt[p],x-1,l,r);
			printf("%d\n",tl.sz+1);
		}
		if(op==4){
			printf("%d\n",tree[kth(rt[p],x)].v);
		}
		if(op==5){
			split(rt[p],x-1,l,r);
			if(l)printf("%d\n",tree[kth(l,tree[l].sz)].v);
			else printf("%d\n",-INF);
		}
		if(op==6){
			split(rt[p],x,l,r);
			if(r)printf("%d\n",tree[kth(r,1)].v);
			else printf("%d\n",INF);
		}
	}
	return 0;
}

