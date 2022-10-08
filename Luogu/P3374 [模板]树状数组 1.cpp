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
#define ull unsigned long long

using namespace std;

int read(){int qrx=0,qry=1;char qrc=getchar();
while(qrc<'0'||qrc>'9'){if(qrc=='-'){qry=-1,qrc=getchar();}else qrc=getchar();}
while(qrc>='0'&&qrc<='9')qrx=qrx*10+qrc-48,qrc=getchar();return qrx*qry;}

const int N=5e5+7,Mod=998244353,INF=1e9+7;
int n,m,a[N];
int sum[N<<2];

void build(int L,int R,int id){
	if(L==R)sum[id]=a[L];
	else{
		int M=(L+R)>>1;
		build(L,M,id<<1),build(M+1,R,(id<<1)|1);
		sum[id]=sum[id<<1]+sum[(id<<1)|1];
	}
	return;
}

void update(int L,int R,int id,int x,int p){
	if(L==R)sum[id]+=p;
	else{
		int M=(L+R)>>1;
		if(x<=M)update(L,M,id<<1,x,p);
		else update(M+1,R,(id<<1)|1,x,p);
		sum[id]=sum[id<<1]+sum[(id<<1)|1]; 
	}
	return;
}

int query(int L,int R,int id,int l,int r){
	if(l<=L&&r>=R)return sum[id];
	int M=(L+R)>>1,res=0;
	if(l<=M)res+=query(L,M,id<<1,l,r);
	if(r>M)res+=query(M+1,R,(id<<1)|1,l,r);
	return res;
}

signed main(){
	n=read(),m=read();
	for(int i=1;i<=n;i++)a[i]=read();
	build(1,n,1);
	for(int i=1,op,l,r;i<=m;i++){
		op=read(),l=read(),r=read();
		if(op==1)update(1,n,1,l,r);
		else printf("%lld\n",query(1,n,1,l,r));
	}
	return 0;
}
