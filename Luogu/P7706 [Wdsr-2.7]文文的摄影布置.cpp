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
#define Lid (id<<1)
#define Rid ((id<<1)|1)

using namespace std;

int read(){int qrx=0,qry=1;char qrc=getchar();
while(qrc<'0'||qrc>'9'){if(qrc=='-'){qry=-1,qrc=getchar();}else qrc=getchar();}
while(qrc>='0'&&qrc<='9')qrx=qrx*10+qrc-48,qrc=getchar();return qrx*qry;}

const int N=5e5+7,Mod=998244353,INF=1e9+7;
int n,m,a[N],b[N];
struct node{
	int a,b,c,ab,bc,abc;
	node(int a=0,int b=0,int c=0,int ab=0,int bc=0,int abc=0):
	a(a),b(b),c(c),ab(ab),bc(bc),abc(abc){}
}t[N*4];

node pushup(node L,node R){
	return node(max(L.a,R.a),max(L.b,R.b),max(L.c,R.c),
	max(max(L.ab,R.ab),L.a+R.b),max(max(L.bc,R.bc),L.b+R.c),
	max(max(L.abc,R.abc),max(L.a+R.bc,L.ab+R.c)));
}

void build(int L,int R,int id){
	if(L==R)t[id]=node(a[L],-b[L],a[L],-INF,-INF,-INF);
	else{
		int M=(L+R)>>1;
		build(L,M,Lid),build(M+1,R,Rid);
		t[id]=pushup(t[Lid],t[Rid]);
	}
	return;
}

void update(int L,int R,int id,int ty,int x,int k){
	if(L==R){
		if(ty==1)a[x]=k;
		else b[x]=k;
		t[id]=node(a[L],-b[L],a[L],-INF,-INF,-INF);
	}
	else{
		int M=(L+R)>>1;
		if(x<=M)update(L,M,Lid,ty,x,k);
		if(x>M)update(M+1,R,Rid,ty,x,k);
		t[id]=pushup(t[Lid],t[Rid]);
	}
	return;
}

node query(int L,int R,int id,int l,int r){
	if(l<=L&&r>=R)return t[id];
	int M=(L+R)>>1;
	if(r<=M)return query(L,M,Lid,l,r);
	if(l>M)return query(M+1,R,Rid,l,r);
	return pushup(query(L,M,Lid,l,r),query(M+1,R,Rid,l,r));
}

int main(){
	n=read(),m=read();
	for(int i=1;i<=n;i++)a[i]=read();
	for(int i=1;i<=n;i++)b[i]=read();
	build(1,n,1);
	for(int i=1,op,l,r;i<=m;i++){
		op=read(),l=read(),r=read();
		if(op<=2)update(1,n,1,op,l,r);
		else printf("%d\n",query(1,n,1,l,r).abc);
	}
	return 0;
}
