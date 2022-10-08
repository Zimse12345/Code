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
#define t tree[id]
#define tl tree[l]
#define tr tree[r]

using namespace std;

inline int read(){int qrx=0,qry=1;char qrc=getchar();
while(qrc<'0'||qrc>'9'){if(qrc=='-'){qry=-1,qrc=getchar();}else qrc=getchar();}
while(qrc>='0'&&qrc<='9')qrx=qrx*10+qrc-48,qrc=getchar();return qrx*qry;}

const int N=2e7+7,Mod=998244353,INF=1e9+7;
int n,tot,rt[300000];
struct node{signed l,r,sz,rev;short ky;int val,sum;}tree[N];
inline void update(int id){t.sz=tree[t.l].sz+tree[t.r].sz+1,t.sum=tree[t.l].sum+tree[t.r].sum+t.val;return;}

inline void pushdown(int id){
	if(t.rev){
		int l=0,r=0;
		if(t.l)l=++tot,tl=tree[t.l];
		if(t.r)r=++tot,tr=tree[t.r];
		swap(l,r);
		t.l=l,t.r=r,t.rev=0;
		if(l)tl.rev^=1;
		if(r)tr.rev^=1;
	}
	return;
}

void split_size(int id,int x,signed& l,signed& r){
	if(!id){l=r=0;return;}
	pushdown(id);
	if(tree[t.l].sz+1<=x)l=++tot,tl=t,split_size(t.r,x-tree[t.l].sz-1,tl.r,r),update(l);
	else r=++tot,tr=t,split_size(t.l,x,l,tr.l),update(r);
	return;
}

int merge(int l,int r){
	pushdown(l),pushdown(r);
	if(!l||!r)return l^r;
	int id=++tot;
	if(tl.ky<tr.ky)t=tl,t.r=merge(tl.r,r);
	else t=tr,t.l=merge(l,tr.l);
	update(id);
	return id;
}

signed main(){
	srand(time(0));
	n=read();
	signed l,r,m;
	for(int i=1,p,op,x,y,ans=0;i<=n;i++){
		p=read(),op=read(),rt[i]=rt[p];
		if(op==1){
			x=read()^ans,y=read()^ans;
			split_size(rt[p],x,l,r);
			int id=++tot;
			t.l=t.r=t.rev=0,t.sum=t.val=y,t.ky=rand(),t.sz=1;
			rt[i]=merge(merge(l,id),r);
		}
		if(op==2){
			x=read()^ans;
			split_size(rt[p],x,l,r);
			split_size(l,x-1,l,m);
			rt[i]=merge(l,r);
		}
		if(op==3){
			x=read()^ans,y=read()^ans;
			split_size(rt[p],y,l,r);
			split_size(l,x-1,l,m);
			tree[m].rev^=1;
			rt[i]=merge(merge(l,m),r);
		}
		if(op==4){
			x=read()^ans,y=read()^ans;
			split_size(rt[p],y,l,r);
			split_size(l,x-1,l,m);
			ans=tree[m].sum;
			printf("%lld\n",ans);
			rt[i]=merge(merge(l,m),r);
		}
	}
	return 0;
}

