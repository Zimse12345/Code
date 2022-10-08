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
#define Rid (Lid|1)
#define M ((L+R)>>1)

using namespace std;

inline int read(){int qrx=0,qry=1;char qrc=getchar();
while(qrc<'0'||qrc>'9'){if(qrc=='-')qry=-1;qrc=getchar();}
while(qrc>='0'&&qrc<='9')qrx=qrx*10+qrc-48,qrc=getchar();return qrx*qry;}

const int Mod=1e9+7,N=1e5+7;
int n,m,a[N];

struct mtr{
	int v[2][2];
	inline void init_e(){v[0][0]=v[1][1]=1,v[0][1]=v[1][0]=0;return;}
}t[N*4],fib,tag[N*4];

mtr mul(mtr A,mtr B){
	mtr res;
	res.v[0][0]=(A.v[0][0]*B.v[0][0]+A.v[0][1]*B.v[1][0])%Mod;
	res.v[0][1]=(A.v[0][0]*B.v[0][1]+A.v[0][1]*B.v[1][1])%Mod;
	res.v[1][0]=(A.v[1][0]*B.v[0][0]+A.v[1][1]*B.v[1][0])%Mod;
	res.v[1][1]=(A.v[1][0]*B.v[0][1]+A.v[1][1]*B.v[1][1])%Mod;
	return res;
}

mtr sum(mtr A,mtr B){
	mtr res;
	res.v[0][0]=(A.v[0][0]+B.v[0][0])%Mod;
	res.v[0][1]=(A.v[0][1]+B.v[0][1])%Mod;
	res.v[1][0]=(A.v[1][0]+B.v[1][0])%Mod;
	res.v[1][1]=(A.v[1][1]+B.v[1][1])%Mod;
	return res;
}

mtr qp(mtr A,int k){
	mtr res;
	res.init_e();
	while(k){
		if(k&1ll)res=mul(res,A);
		A=mul(A,A),k/=2;
	}
	return res;
}

void build(int L,int R,int id){
	tag[id].init_e();
	if(L==R)t[id]=qp(fib,a[L]-1);
	else build(L,M,Lid),build(M+1,R,Rid),t[id]=sum(t[Lid],t[Rid]);
	return;
}

void pushdown(int id){
	t[id]=mul(t[id],tag[id]);
	if(Rid<N*4)tag[Lid]=mul(tag[Lid],tag[id]),tag[Rid]=mul(tag[Rid],tag[id]);
	tag[id].init_e();
	return;
}

void update(int L,int R,int id,int l,int r,mtr x){
	pushdown(id);
	if(r<L||R<l)return;
	if(l<=L&&r>=R)tag[id]=x,pushdown(id);
	else{
		update(L,M,Lid,l,r,x),update(M+1,R,Rid,l,r,x);
		t[id]=sum(t[Lid],t[Rid]);
	}
	return;
}

int query(int L,int R,int id,int l,int r){
	pushdown(id);
	if(r<L||R<l)return 0;
	if(l<=L&&r>=R)return t[id].v[0][0];
	return (query(L,M,Lid,l,r)+query(M+1,R,Rid,l,r))%Mod;
}

signed main(){
	fib.v[0][0]=fib.v[0][1]=fib.v[1][0]=1;
	n=read(),m=read();
	for(int i=1;i<=n;i++)a[i]=read();
	build(1,n,1);
	while(m--){
		int op=read(),l=read(),r=read();
		if(op==1)update(1,n,1,l,r,qp(fib,read()));
		else printf("%lld\n",query(1,n,1,l,r));
	}
	return 0;
}

