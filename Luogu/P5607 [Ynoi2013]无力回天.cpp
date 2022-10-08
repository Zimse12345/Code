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
#define M ((L+R)>>1)

using namespace std;

int read(){int qrx=0,qry=1;char qrc=getchar();
while(qrc<'0'||qrc>'9'){if(qrc=='-'){qry=-1,qrc=getchar();}else qrc=getchar();}
while(qrc>='0'&&qrc<='9')qrx=qrx*10+qrc-48,qrc=getchar();return qrx*qry;}

const int N=1e5+7,Mod=998244353,INF=1e9+7;
int n,m,a[N],d[N*4][32],D[32];

int tr[N];
inline void ub(int& x){x+=(x&(-x));return;}
inline void db(int& x){x-=(x&(-x));return;}
inline void bit_update(int x,int t){for(;x<=n;ub(x))tr[x]^=t;return;}
inline int bit_query(int x){int res=0;for(;x;db(x))res^=tr[x];return res;}

void ins(int id,int x){
	for(int i=30;i>=0;i--)if(x&(1<<i)){
		if(!d[id][i]){
			d[id][i]=x;
			return;
		}
		x^=d[id][i];
	}
	return;
}

void Ins(int x){
	for(int i=30;i>=0;i--)if(x&(1<<i)){
		if(!D[i]){
			D[i]=x;
			return;
		}
		x^=D[i];
	}
	return;
}

inline void pushup(int id){
	for(int i=0;i<=30;i++)d[id][i]=d[Lid][i];
	for(int i=0;i<=30;i++)if(d[Rid][i])ins(id,d[Rid][i]);
	return;
}

void build(int L,int R,int id){
	if(L==R)ins(id,a[L]);
	else build(L,M,Lid),build(M+1,R,Rid),pushup(id);
	return;
}

void update(int L,int R,int id,int x,int y){
	if(L==R){
		for(int i=0;i<=30;i++)d[id][i]=0;
		a[x]^=y,ins(id,a[x]);
	}
	else{
		if(x<=M)update(L,M,Lid,x,y);
		else update(M+1,R,Rid,x,y);
		pushup(id);
	}
	return;
}

void query(int L,int R,int id,int l,int r){
	if(l>R||L>r)return;
	if(l<=L&&r>=R){
		for(int i=0;i<=30;i++)if(d[id][i])Ins(d[id][i]); 
	}
	else query(L,M,Lid,l,r),query(M+1,R,Rid,l,r);
	return;
}

signed main(){
	n=read(),m=read();
	for(int i=1;i<=n;i++)a[i]=read();
	for(int i=n;i>=2;i--)a[i]^=a[i-1],bit_update(i,a[i]);
	bit_update(1,a[1]);
	build(1,n,1);
	int op,l,r,v;
	while(m--){
		op=read(),l=read(),r=read(),v=read();
		if(op==1)update(1,n,1,l,v),update(1,n,1,r+1,v),bit_update(l,v),bit_update(r+1,v);
		else{
			for(int i=0;i<=30;i++)D[i]=0;
			query(1,n,1,l+1,r),Ins(bit_query(l));
			for(int i=30;i>=0;i--)if((v^D[i])>v)v^=D[i];
			printf("%d\n",v);
		}
	}
	return 0;
}

