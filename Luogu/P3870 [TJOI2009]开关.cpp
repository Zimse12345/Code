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

const int N=2e5+7,Mod=998244353,INF=1e9+7;
int n,m;
int sum[N<<2],tag[N<<2],len[N<<2];

void pushdown(int id){
	if(tag[id]){
		sum[id]=len[id]-sum[id];
		tag[id<<1]^=1,tag[(id<<1)|1]^=1,tag[id]=0;
	}
	return;
}

void build(int L,int R,int id){
	len[id]=R-L+1;
	if(L!=R){
		int M=(L+R)>>1;
		build(L,M,id<<1),build(M+1,R,(id<<1)|1);
	}
	return;
}

void update(int L,int R,int id,int l,int r){
	pushdown(id);
	if(l<=L&&r>=R)tag[id]^=1,pushdown(id);
	else{
		int M=(L+R)>>1;
		if(l<=M)update(L,M,id<<1,l,r);
		if(r>M)update(M+1,R,(id<<1)|1,l,r);
		pushdown(id<<1),pushdown((id<<1)|1);
		sum[id]=sum[id<<1]+sum[(id<<1)|1];
	}
	return;
}

int query(int L,int R,int id,int l,int r){
	pushdown(id);
	if(l<=L&&r>=R)return sum[id];
	int M=(L+R)>>1,res=0;
	if(l<=M)res+=query(L,M,id<<1,l,r);
	if(r>M)res+=query(M+1,R,(id<<1)|1,l,r);
	return res;
}

int main(){
	n=read(),m=read();
	build(1,n,1);
	for(int i=1,l,r,op;i<=m;i++){
		op=read();
		l=read(),r=read();
		if(op==0)update(1,n,1,l,r);
		else printf("%d\n",query(1,n,1,l,r));
	}
	return 0;
}
