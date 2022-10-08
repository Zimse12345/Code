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
int n,m;
int sum[N<<2],L0[N<<2],R0[N<<2],s0[N<<2],tag0[N<<2],tag1[N<<2],len[N<<2];

void pushup(int id){
	int Lid=id<<1,Rid=Lid|1;
	sum[id]=sum[Lid]+sum[Rid],L0[id]=L0[Lid],R0[id]=R0[Rid];
	if(sum[Lid]==0)L0[id]=len[Lid]+L0[Rid];
	if(sum[Rid]==0)R0[id]=len[Rid]+R0[Lid];
	s0[id]=max(max(s0[Lid],s0[Rid]),R0[Lid]+L0[Rid]);
	return;
}

void pushdown(int id){
	int Lid=id<<1,Rid=Lid|1;
	if(tag0[id]==1){
		sum[id]=0,L0[id]=R0[id]=s0[id]=len[id];
		tag0[Lid]=tag0[Rid]=1,tag1[Lid]=tag1[Rid]=0,tag0[id]=0;
	}
	if(tag1[id]==1){
		sum[id]=len[id],L0[id]=R0[id]=s0[id]=0;
		tag0[Lid]=tag0[Rid]=0,tag1[Lid]=tag1[Rid]=1,tag1[id]=0;
	}
	return;
}

void build(int L,int R,int id){
	len[id]=R-L+1;
	if(L==R)sum[id]=1;
	else{
		int M=(L+R)>>1;
		build(L,M,id<<1),build(M+1,R,(id<<1)|1);
		pushup(id);
	}
	return;
}

void dig(int L,int R,int id,int l,int r){
	pushdown(id);
	if(l<=L&&r>=R)tag0[id]=1,pushdown(id);
	else{
		int M=(L+R)>>1;
		if(l<=M)dig(L,M,id<<1,l,r);
		if(r>M)dig(M+1,R,(id<<1)|1,l,r);
		pushdown(id<<1),pushdown((id<<1)|1);
		pushup(id);
	}
	return;
}

int digout(int L,int R,int id,int l,int r){
	pushdown(id);
	int res=0;
	if(l<=L&&r>=R)res=sum[id];
	else{
		int M=(L+R)>>1;
		if(l<=M)res+=digout(L,M,id<<1,l,r);
		if(r>M)res+=digout(M+1,R,(id<<1)|1,l,r);
	}
	return res;
}

int treat(int L,int R,int id,int l,int r,int x){
	pushdown(id);
	if(l<=L&&r>=R){
		if(len[id]-sum[id]<=x)x-=len[id]-sum[id],tag1[id]=1,pushdown(id);
		else{
			int M=(L+R)>>1;
			x=treat(L,M,id<<1,l,r,x);
			if(x>0)x=treat(M+1,R,(id<<1)|1,l,r,x);
			pushdown(id<<1),pushdown((id<<1)|1);
			pushup(id);
		}
	}
	else{
		int M=(L+R)>>1;
		if(l<=M)x=treat(L,M,id<<1,l,r,x);
		if(r>M&&x>0)x=treat(M+1,R,(id<<1)|1,l,r,x);
		pushdown(id<<1),pushdown((id<<1)|1);
		pushup(id);
	}
	return x;
}

int query(int L,int R,int id,int l,int r){
	pushdown(id);
	int res=0;
	if(l<=L&&r>=R)res=s0[id];
	else{
		int M=(L+R)>>1;
		if(l<=M)res=max(res,query(L,M,id<<1,l,r));
		if(r>M)res=max(res,query(M+1,R,(id<<1)|1,l,r));
		if(l<=M&&r>M){
			int Lo=M-R0[id<<1]+1,Ro=M+L0[(id<<1)|1];
			Lo=max(Lo,l),Ro=min(Ro,r);
			res=max(res,Ro-Lo+1);
		}
	}
	return res;
}

int main(){
	n=read(),m=read();
	build(1,n,1);
	for(int i=1,op,l,r,l0,r0;i<=m;i++){
		op=read(),l=read(),r=read();
		if(op==0)dig(1,n,1,l,r);
		if(op==1){
			l0=read(),r0=read();
			int x=digout(1,n,1,l,r);
			dig(1,n,1,l,r);
			if(x>0)treat(1,n,1,l0,r0,x);
		}
		if(op==2)printf("%d\n",query(1,n,1,l,r));
	}
	return 0;
}
