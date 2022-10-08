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
#define M ((L+R)>>1)
#define Lid (id<<1)
#define Rid ((id<<1)|1)

using namespace std;

int read(){int qrx=0,qry=1;char qrc=getchar();
while(qrc<'0'||qrc>'9'){if(qrc=='-'){qry=-1,qrc=getchar();}else qrc=getchar();}
while(qrc>='0'&&qrc<='9')qrx=qrx*10+qrc-48,qrc=getchar();return qrx*qry;}

const int N=1e6+7,Mod=998244353,INF=1e9+7;
int n,q,rt,cnt;
char op;
struct bl{int L,R,c,p;bl(int L=0,int R=0,int c=0,int p=0):L(L),R(R),c(c),p(p){}};
struct node{int l,r,ky,sz;bl v;node(int l=0,int r=0,int ky=0,int sz=0,bl v=bl(0,0,0,0)):l(l),r(r),ky(ky),sz(sz),v(v){}}tree[N*3];
struct nd{int x,y;nd(int x=0,int y=0):x(x),y(y){}};
vector<nd> opt[N];
inline void update(int id){t.sz=tree[t.l].sz+tree[t.r].sz+1;return;}

int sum[N];
inline void ub(int& x){x+=(x&(-x));return;}
inline void db(int& x){x-=(x&(-x));return;}
inline void ad(int x,int v){for(;x<=n;ub(x))sum[x]+=v;return;}
inline int qu(int x){int res=0;for(;x;db(x))res+=sum[x];return res;}

void split1(int id,int x,int& l,int& r){
	if(!id){l=r=0;return;}
	if(t.v.L<=x)l=id,split1(t.r,x,t.r,r);
	else r=id,split1(t.l,x,l,t.l);
	update(id);return;
}

void split2(int id,int x,int& l,int& r){
	if(!id){l=r=0;return;}
	if(t.v.R<x)l=id,split2(t.r,x,t.r,r);
	else r=id,split2(t.l,x,l,t.l);
	update(id);return;
}

int merge(int l,int r){
	if(!l||!r)return l^r;
	if(tl.ky<tr.ky){tl.r=merge(tl.r,r),update(l);return l;}
	tr.l=merge(l,tr.l),update(r);return r;
}

int kth(int id,int k){
	if(k<=tree[t.l].sz)return kth(t.l,k);
	if(tree[t.l].sz+1<k)return kth(t.r,k-tree[t.l].sz-1);
	return id;
}

void ins(int& id,bl x){
	int l,r;
	split1(id,x.L,l,r),tree[++cnt]=node(0,0,rand(),1,x),id=merge(l,merge(cnt,r));
	return;
}

int calc(int c,int p){
	int L=0,R=opt[c].size()-1,m=0;
	while(L<=R){
		if(opt[c][M].x<p)m=M,L=M+1;
		else R=M-1;
	}
	return opt[c][opt[c].size()-1].y-opt[c][m].y;
}

void sol(int id){
	if(!id)return;
	sol(t.l),sol(t.r);
	int val=calc(t.v.c,t.v.p);
	ad(t.v.L,val),ad(t.v.R+1,-val);
	return;
}

signed main(){
	srand(time(0));
	n=read(),q=read();
	ins(rt,bl(1,n,1,0));
	opt[1].push_back(nd(0,0));
	for(int i=1,L,R,x;i<=q;i++){
		do{op=getchar();}while(op<'A'||op>'Z');
		if(op=='C'){
			L=read(),R=read(),x=read();
			if(opt[x].empty())opt[x].push_back(nd(0,0));
			int l,m,r;
			split2(rt,L,l,m),split1(m,R,m,r);
			bl *_l=&tree[kth(m,1)].v,*_r=&tree[kth(m,tree[m].sz)].v;
			if((*_l).L<L)ins(l,bl((*_l).L,L-1,(*_l).c,(*_l).p)),(*_l).L=L;
			if((*_r).R>R)ins(r,bl(R+1,(*_r).R,(*_r).c,(*_r).p)),(*_r).R=R;
			sol(m);
			tree[++cnt]=node(0,0,rand(),1,bl(L,R,x,i));
			rt=merge(l,merge(cnt,r));
		}
		else if(op=='A'){
			L=read(),R=read();
			if(opt[L].empty())opt[L].push_back(nd(0,0));
			nd p=opt[L][opt[L].size()-1];
			opt[L].push_back(nd(i,p.y+R));
		}
		else{
			x=read();
			int l,r;
			split1(rt,x,l,r);
			bl p=tree[kth(l,tl.sz)].v;
			printf("%lld\n",qu(x)+calc(p.c,p.p));
			rt=merge(l,r);
		}
	}
	return 0;
}

