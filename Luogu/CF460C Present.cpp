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
#define Lid (id<<1)
#define Rid ((id<<1)|1)
#define M ((L+R)/2)

using namespace std;

int read(){int qrx=0,qry=1;char qrc=getchar();
while(qrc<'0'||qrc>'9'){if(qrc=='-'){qry=-1,qrc=getchar();}else qrc=getchar();}
while(qrc>='0'&&qrc<='9')qrx=qrx*10+qrc-48,qrc=getchar();return qrx*qry;}

const int N=2e5+7,Mod=998244353,INF=2e9+7;
int n,m,w,a[N],v[N*4];

void build(int L,int R,int id){
	v[id]=0;
	if(L^R)build(L,M,Lid),build(M+1,R,Rid);
	return;
}

void update(int L,int R,int id,int l,int r){
	if(l>R||r<L)return;
	if(l<=L&&r>=R)++v[id];
	else update(L,M,Lid,l,r),update(M+1,R,Rid,l,r);
	return;
}

int query(int L,int R,int id,int x){
	if(L==R)return v[id];
	if(x<=M)return v[id]+query(L,M,Lid,x);
	return v[id]+query(M+1,R,Rid,x);
}

bool check(int x){
	int t=0;
	build(1,n,1);
	for(int i=1;i<=n;i++){
		int v=query(1,n,1,i)+a[i];
		while(v<x&&t<m)++t,++v,update(1,n,1,i,min(i+w-1,n));
		if(v<x)return false;
	}
	return true;
}

signed main(){
	n=read(),m=read(),w=read();
	for(int i=1;i<=n;i++)a[i]=read();
	int L=1,R=INF,ans=0;
	while(L<=R){
		if(check(M))ans=M,L=M+1;
		else R=M-1;
	}
	printf("%lld\n",ans);
	return 0;
}

