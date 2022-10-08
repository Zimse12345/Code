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
#define M ((L+R)>>1)
#define Lid (id<<1)
#define Rid ((id<<1)|1)
#define t tree[id]
#define _t tree[_id]

using namespace std;

int read(){int qrx=0,qry=1;char qrc=getchar();
while(qrc<'0'||qrc>'9'){if(qrc=='-'){qry=-1,qrc=getchar();}else qrc=getchar();}
while(qrc>='0'&&qrc<='9')qrx=qrx*10+qrc-48,qrc=getchar();return qrx*qry;}

const int N=2e6+7,Mod=998244353,INF=1e9;
int n,q;
struct node{int x,y;node(int x=0,int y=0):x(x),y(y){}}tree[N*4];

void build(int L,int R,int id){
	tree[id]=node(0,0);
	if(L^R)build(L,M,Lid),build(M+1,R,Rid);
	return;
}

void mergetag(int id,int _id){
//	printf("[%d,%d] -> [%d,%d]\n",t.x,t.y,_t.x,_t.y);
	if(t.x<=_t.x&&t.y>=_t.y)return;
	else if(t.y<_t.x)_t=node(t.y,t.y);
	else if(t.x>_t.y)_t=node(t.x,t.x);
	else _t=node(max(t.x,_t.x),min(t.y,_t.y));
//	printf("{%d,%d}\n",_t.x,_t.y);
	return;
}

void pushdown(int id){
	if(Rid<4*N)mergetag(id,Lid),mergetag(id,Rid);
	tree[id]=node(0,INF);
	return;
}

void update(int L,int R,int id,int l,int r,int op,int k){
	if(L^R)pushdown(id);
	if(r<L||R<l)return;
	if(l<=L&&r>=R){
		if(L^R){
			if(op==1)tree[id].x=k;
			else tree[id].y=k;
			pushdown(id);
		}
		else{
			if(op==1)tree[id].x=tree[id].y=max(tree[id].x,k);
			else tree[id].x=tree[id].y=min(tree[id].x,k);
		}
	}
	else update(L,M,Lid,l,r,op,k),update(M+1,R,Rid,l,r,op,k);
	return;
}

int query(int L,int R,int id,int x){
	if(L^R)pushdown(id);
	else return tree[id].x;
	if(x<=M)return query(L,M,Lid,x);
	else return query(M+1,R,Rid,x);
}

signed main(){
	n=read(),q=read();
	for(int i=1,op,l,r,h;i<=q;i++){
		op=read(),l=read()+1,r=read()+1,h=read();
		update(1,n,1,l,r,op,h);
	}
	for(int i=1;i<=n;i++)printf("%d\n",query(1,n,1,i));
	return 0;
}

