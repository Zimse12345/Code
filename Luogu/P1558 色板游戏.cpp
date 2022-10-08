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

const int N=1e5+7,Mod=998244353,INF=1e9+7;
int n,t,q,val[N];
int Or[N<<2],tag[N<<2];
char op;

void pushdown(int id){
	if(tag[id]){
		Or[id]=tag[id];
		tag[id<<1]=tag[(id<<1)|1]=tag[id],tag[id]=0;
	}
	return;
}

void pushup(int id){
	Or[id]=Or[id<<1]|Or[(id<<1)|1];
	return;
}

void build(int L,int R,int id){
	if(L==R)Or[id]=val[L];
	else{
		int M=(L+R)>>1;
		build(L,M,id<<1),build(M+1,R,(id<<1)|1);
		pushup(id);
	}
	return;
}

void update(int L,int R,int id,int l,int r,int x){
	pushdown(id);
	if(l<=L&&r>=R)tag[id]=x,pushdown(id);
	else{
		int M=(L+R)>>1;
		if(l<=M)update(L,M,id<<1,l,r,x);
		if(r>M)update(M+1,R,(id<<1)|1,l,r,x);
		pushdown(id<<1),pushdown((id<<1)|1);
		pushup(id);
	}
	return;
}

int query(int L,int R,int id,int l,int r){
	pushdown(id);
	if(l<=L&&r>=R)return Or[id];
	int res=0,M=(L+R)>>1;
	if(l<=M)res=res|query(L,M,id<<1,l,r);
	if(r>M)res=res|query(M+1,R,(id<<1)|1,l,r);
	return res;
}
 
int main(){
	n=read(),t=read(),q=read();
	for(int i=1;i<=n;i++)val[i]=1;
	build(1,n,1);
	for(int i=1,l,r,x,ans;i<=q;i++){
		op=getchar();
		while((op!='C')&&(op!='P'))op=getchar();
		l=read(),r=read();
		if(l>r){int T=l;l=r,r=T;}
		if(op=='C'){
			x=read();
			update(1,n,1,l,r,1<<(x-1));
		}
		if(op=='P'){
			x=query(1,n,1,l,r),ans=0;
			for(int j=0;j<t;j++)if(x&(1<<j))++ans;
			printf("%d\n",ans);
		}
	}
	return 0;
}
