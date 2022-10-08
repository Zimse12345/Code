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

using namespace std;

inline int read(){int qrx=0,qry=1;char qrc=getchar();
while(qrc<'0'||qrc>'9'){if(qrc=='-'){qry=-1,qrc=getchar();}else qrc=getchar();}
while(qrc>='0'&&qrc<='9')qrx=qrx*10+qrc-48,qrc=getchar();return qrx*qry;}

const int N=2e5+7;
int n,m,P,a[N];
int sum[N*8],po[N*8],ad[N*8];

void push_down(int o,int sz){
	int l=o<<1,r=(o<<1)|1;
	sum[o]=(sum[o]*po[o]+ad[o]*sz)%P;
	po[l]=(po[l]*po[o])%P,po[r]=(po[r]*po[o])%P;
	ad[l]=(ad[l]*po[o]+ad[o])%P,ad[r]=(ad[r]*po[o]+ad[o])%P;
	po[o]=1,ad[o]=0;
	return;
}

int build(int L,int R,int o){
	po[o]=1;
	if(L==R){sum[o]=a[L];return sum[o];}
	int M=(L+R)>>1;
	sum[o]=(build(L,M,o<<1)+build(M+1,R,(o<<1)|1))%P;
	return sum[o];
}

int query(int L,int R,int l,int r,int o){
	push_down(o,R-L+1);
	if(l<=L&&r>=R)return sum[o];
	int M=(L+R)>>1,res=0;
	if(l<=M)res+=query(L,M,l,r,o<<1);
	if(r>M)res+=query(M+1,R,l,r,(o<<1)|1);
	return res%P;
}

void mul(int L,int R,int l,int r,int k,int o){
	push_down(o,R-L+1);
	if(l<=L&&r>=R)po[o]=(po[o]*k)%P,ad[o]=(ad[o]*k)%P;
	else{
		int M=(L+R)>>1;
		if(l<=M)mul(L,M,l,r,k,o<<1);
		if(r>M)mul(M+1,R,l,r,k,(o<<1)|1);
		push_down(o<<1,M-L+1),push_down((o<<1)|1,R-M);
		sum[o]=(sum[o<<1]+sum[(o<<1)|1])%P;
	}
	push_down(o,R-L+1);
	return;
}

void add(int L,int R,int l,int r,int k,int o){
	push_down(o,R-L+1);
	if(l<=L&&r>=R)ad[o]=(ad[o]+k)%P;
	else{
		int M=(L+R)>>1;
		if(l<=M)add(L,M,l,r,k,o<<1);
		if(r>M)add(M+1,R,l,r,k,(o<<1)|1);
		push_down(o<<1,M-L+1),push_down((o<<1)|1,R-M);
		sum[o]=(sum[o<<1]+sum[(o<<1)|1])%P;
	}
	push_down(o,R-L+1);
	return;
}

signed main(){
	n=read(),P=read();
	for(int i=1;i<=n;++i)a[i]=read();
	build(1,n,1);
	m=read();
	while(m--){
		int ty=read(),x=read(),y=read(),k;
		if(ty==3)printf("%lld\n",query(1,n,x,y,1));
		if(ty==1||ty==2){
			k=read();
			if(ty==1)mul(1,n,x,y,k,1);
			if(ty==2)add(1,n,x,y,k,1);
		}
	}
	return 0;
}
