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
#define ull unsigned long long

using namespace std;

int read(){int qrx=0,qry=1;char qrc=getchar();
while(qrc<'0'||qrc>'9'){if(qrc=='-'){qry=-1,qrc=getchar();}else qrc=getchar();}
while(qrc>='0'&&qrc<='9')qrx=qrx*10+qrc-48,qrc=getchar();return qrx*qry;}

const int N=4e5+7,Mod=998244353,INF=1e9+7;
int n,m,a[N];
int mx[N<<2],tag[N<<2];

void pushdown(int id){
	if(tag[id]){
		mx[id]=max(mx[id],tag[id]);
		tag[id<<1]=tag[(id<<1)|1]=tag[id],tag[id]=0;
	}
	return;
}

void build(int L,int R,int id){
	if(L==R)mx[id]=a[L];
	else{
		int M=(L+R)>>1;
		build(L,M,id<<1),build(M+1,R,(id<<1)|1);
		mx[id]=max(mx[id<<1],mx[(id<<1)|1]);
	}
	return;
}

void update(int L,int R,int id,int l,int r,int x){
	pushdown(id);
	if(l<=L&&r>=R)tag[id]=x,pushdown(id);
	else{
		int M=(L+R)>>1;
		if(l<=M)update(L,M,id<<1,l,r,x);
		else pushdown(id<<1);
		if(r>M)update(M+1,R,(id<<1)|1,l,r,x);
		else pushdown((id<<1)|1);
		mx[id]=max(mx[id<<1],mx[(id<<1)|1]);
	}
	return;
}

int query(int L,int R,int id,int l,int r){
	pushdown(id);
	if(l<=L&&r>=R)return mx[id];
	int M=(L+R)>>1,res=0;
	if(l<=M)res=max(res,query(L,M,id<<1,l,r));
	if(r>M)res=max(res,query(M+1,R,(id<<1)|1,l,r));
	return res;
}

int main(){
	n=read(),m=read();
	for(int i=1;i<=n;i++)a[i]=read();
	build(1,n,1);
	for(int i=1,l,r;i<=m;i++){
		char op=getchar();
		while(op!='Q'&&op!='U')op=getchar();
		l=read(),r=read();
		if(op=='Q')printf("%d\n",query(1,n,1,l,r));
		else update(1,n,1,l,l,r);
	}
	return 0;
}
