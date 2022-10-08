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
while(qrc<'0'||qrc>'9'){if(qrc=='-'){qry=-1,qrc=getchar();}qrc=getchar();}
while(qrc>='0'&&qrc<='9')qrx=qrx*10+qrc-48,qrc=getchar();return qrx*qry;}

const int N=4e5+7,Mod=998244353,INF=1e9+7;
int n,m,a[N],sum[N],L0[N],L1[N],R0[N],R1[N],s0[N],s1[N],tag[N],len[N],lf[N];

void pushup(int id){
	if(lf[id])return;
	int L=id<<1,R=L|1;
	sum[id]=sum[L]+sum[R];
	L0[id]=sum[L]==0?len[L]+L0[R]:L0[L];
	L1[id]=sum[L]==len[L]?len[L]+L1[R]:L1[L];
	R0[id]=sum[R]==0?len[R]+R0[L]:R0[R];
	R1[id]=sum[R]==len[R]?len[R]+R1[L]:R1[R];
	s0[id]=max(max(s0[L],s0[R]),R0[L]+L0[R]);
	s1[id]=max(max(s1[L],s1[R]),R1[L]+L1[R]);
	return;
}

void pushdown(int id){
	int L=id<<1,R=L|1;

	if(tag[id]==0){
		sum[id]=L1[id]=R1[id]=s1[id]=0;
		L0[id]=R0[id]=s0[id]=len[id];
	}
	if(tag[id]==1){
		sum[id]=L1[id]=R1[id]=s1[id]=len[id];
		L0[id]=R0[id]=s0[id]=0;
	}
	if(tag[id]==2){
		int T=0;
		sum[id]=len[id]-sum[id];
		T=L0[id],L0[id]=L1[id],L1[id]=T;
		T=R0[id],R0[id]=R1[id],R1[id]=T;
		T=s0[id],s0[id]=s1[id],s1[id]=T;
	}

	if(tag[id]<=1&&tag[id]>=0)tag[L]=tag[R]=tag[id];
	if(tag[id]==2){
		if(tag[L]==-1)tag[L]=2;
		else if(tag[L]==2)tag[L]=-1;
		else if(tag[L]==0||tag[L]==1)tag[L]=1-tag[L];
		if(tag[R]==-1)tag[R]=2;
		else if(tag[R]==2)tag[R]=-1;
		else if(tag[R]==0||tag[R]==1)tag[R]=1-tag[R];
	}
	tag[id]=-1;
	return;
}

void build(int L,int R,int id){
	len[id]=R-L+1,tag[id]=-1;
	if(L==R){
		lf[id]=1;
		if(a[L])sum[id]=L1[id]=R1[id]=s1[id]=1;
		else L0[id]=R0[id]=s0[id]=1;
	}
	else{
		int M=(L+R)>>1;
		build(L,M,id<<1),build(M+1,R,(id<<1)|1);
		pushup(id);
	}
	return;
}

void update(int L,int R,int id,int l,int r,int op){
	pushdown(id);
	if(L>=l&&R<=r)tag[id]=op;
	else{
		int M=(L+R)>>1;
		if(l<=M)update(L,M,id<<1,l,r,op);
		else pushdown(id<<1);
		if(r>M)update(M+1,R,(id<<1)|1,l,r,op);
		else pushdown((id<<1)|1);
		pushup(id);
	}
	pushdown(id);
	return;
}

int query(int L,int R,int id,int l,int r,int ty){
	pushdown(id);
	if(L>=l&&R<=r){
		if(ty==3)return sum[id];
		else return s1[id];
	}
	int M=(L+R)>>1;
	if(ty==3){
		int res=0;
		if(l<=M)res+=query(L,M,id<<1,l,r,ty);
		if(r>M)res+=query(M+1,R,(id<<1)|1,l,r,ty);
		return res;
	}
	if(ty==4){
		int res=0;
		if(l<=M)res=max(res,query(L,M,id<<1,l,r,ty));
		if(r>M)res=max(res,query(M+1,R,(id<<1)|1,l,r,ty));
		int LL=max(l,M-R1[id<<1]+1),RR=min(r,M+L1[(id<<1)|1]);
		if(l<=M&&r>M)res=max(res,RR-LL+1);
		return res;
	}
	return -1;
}

int main(){
	n=read(),m=read();
	for(int i=1;i<=n;i++)a[i]=read();
	build(1,n,1);
	while(m--){
		int ty=read(),l=read()+1,r=read()+1;
		if(ty<=2)update(1,n,1,l,r,ty);
		else printf("%d\n",query(1,n,1,l,r,ty));
	}
	return 0;
}