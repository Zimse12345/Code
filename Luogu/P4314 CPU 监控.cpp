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
#define t tr[id]
#define _t tr[_id]
#define M ((L+R)>>1)
#define Lid (id<<1)
#define Rid ((id<<1)|1)

using namespace std;

int read(){int qrx=0,qry=1;char qrc=getchar();
while(qrc<'0'||qrc>'9'){if(qrc=='-'){qry=-1,qrc=getchar();}else qrc=getchar();}
while(qrc>='0'&&qrc<='9')qrx=qrx*10+qrc-48,qrc=getchar();return qrx*qry;}

const int N=1e5+7,Mod=998244353,INF=1e9+7;
int n,m,a[N];
char op;
struct node{int mx,his,tag,mxval,val,mxadd,add;node(int mx=0,int his=0,int tag=0,int mxval=0,int val=0,int mxadd=0,int add=0):mx(mx),his(his),tag(tag),val(val),mxadd(mxadd),add(add){}}tr[N*4];
node merge(node l,node r){return node(max(l.mx,r.mx),max(l.his,r.his),0,0,0,0,0);}
void mergetag(int id,int _id);
void pushdown(int id);

void mergetag(int id,int _id){
	if(_t.tag){
		_t.mxval=max(_t.mxval,_t.val+_t.mxadd),_t.val+=_t.add;
		if(t.tag)_t.mxval=max(_t.mxval,t.mxval),_t.val=t.val;
		_t.add=t.add,_t.mxadd=t.mxadd;
	}
	else if(!(_t.add==0&&_t.mxadd==0)){
		if(t.tag)pushdown(_id),_t.tag=1,_t.val=t.val+t.add,_t.mxval=max(t.mxval,t.val+t.mxadd);
		else _t.mxadd=max(_t.mxadd,_t.add+t.mxadd),_t.add+=t.add;
	}
	else if(t.tag)_t.tag=1,_t.val=t.val+t.add,_t.mxval=max(t.mxval,t.val+t.mxadd),_t.add=_t.mxadd=0;
	else _t.add=t.add,_t.mxadd=t.mxadd;
	return;
}

void pushdown(int id){
	if(Rid<4*N)mergetag(id,Lid),mergetag(id,Rid);
	if(t.tag)t.his=max(t.his,max(t.mxval,t.val+t.mxadd)),t.mx=t.val+t.add;
	else t.his=max(t.his,t.mx+t.mxadd),t.mx+=t.add;
	t.tag=t.mxval=t.val=t.mxadd=t.add=0;
	return;
}

node build(int L,int R,int id){
	if(L==R)t=node(a[L],a[L],0,0,0,0,0);
	else t=merge(build(L,M,Lid),build(M+1,R,Rid));
	return t;
}

void update1(int L,int R,int id,int l,int r,int x){
	pushdown(id);
	if(r<L||R<l)return;
	if(l<=L&&r>=R)t.mxadd=t.add=x,pushdown(id);
	else{
		update1(L,M,Lid,l,r,x),update1(M+1,R,Rid,l,r,x);
		t=merge(tr[Lid],tr[Rid]);
	}
	return;
}

void update2(int L,int R,int id,int l,int r,int x){
	pushdown(id);
	if(r<L||R<l)return;
	if(l<=L&&r>=R)t.tag=1,t.val=t.mxval=x,pushdown(id);
	else{
		update2(L,M,Lid,l,r,x),update2(M+1,R,Rid,l,r,x);
		t=merge(tr[Lid],tr[Rid]);
	}
	return;
}

node query(int L,int R,int id,int l,int r){
	pushdown(id);
	if(l<=L&&r>=R)return t;
	if(r<=M)return query(L,M,Lid,l,r);
	if(l>M)return query(M+1,R,Rid,l,r);
	return merge(query(L,M,Lid,l,r),query(M+1,R,Rid,l,r));
}

signed main(){
	n=read();
	for(int i=1;i<=n;i++)a[i]=read();
	build(1,n,1);
	m=read();
	for(int i=1,l,r;i<=m;i++){
		do{op=getchar();}while(op<'A'||op>'Z');
		l=read(),r=read();
		if(op=='Q'||op=='A'){
			node ans=query(1,n,1,l,r);
			if(op=='Q')printf("%d\n",ans.mx);
			else printf("%d\n",ans.his);
		}
		if(op=='P')update1(1,n,1,l,r,read());
		if(op=='C')update2(1,n,1,l,r,read());
	}
	return 0;
}

