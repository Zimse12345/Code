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
#define M ((L+R)>>1)
#define Lid (id<<1)
#define Rid (Lid|1)

using namespace std;

inline int read(){int qrx=0,qry=1;char qrc=getchar();
while(qrc<'0'||qrc>'9'){if(qrc=='-')qry=-1;qrc=getchar();}
while(qrc>='0'&&qrc<='9')qrx=qrx*10+qrc-48,qrc=getchar();return qrx*qry;}

const int N=2e5+7,INF=1e15;
int n,m,d[N],h[N],A[N],B[N];

struct node{
	int a,b,ab;
	node(int a=0,int b=0,int ab=0):a(a),b(b),ab(ab){}
}t[N*4];

node merge(const node& A,const node& B){
	return node(max(A.a,B.a),max(A.b,B.b),max(max(A.ab,B.ab),A.a+B.b));
}

void build(int L,int R,int id){
	if(L==R)t[id]=node(A[L],B[L],-INF);
	else{
		build(L,M,Lid),build(M+1,R,Rid);
		t[id]=merge(t[Lid],t[Rid]);
	}
	return;
}

node query(int L,int R,int id,int l,int r){
	if(r<L||R<l)return node(-INF,-INF,-INF);
	if(l<=L&&r>=R)return t[id];
	return merge(query(L,M,Lid,l,r),query(M+1,R,Rid,l,r));
}

signed main(){
	n=read(),m=read();
	for(int i=1;i<=n;i++)d[i]=read();
	for(int i=1;i<=n;i++)h[i]=read();
	for(int i=n+1;i<=n*2;i++)d[i]=d[i-n],h[i]=h[i-n];
	for(int i=2;i<=n*2;i++)d[i]+=d[i-1];
	for(int i=1;i<=n*2;i++)A[i]=d[i-1]+h[i]*2,B[i]=-d[i-1]+h[i]*2,swap(A[i],B[i]);
	build(1,n*2,1);
	while(m--){
		int a=read(),b=read(),l=0,r=0;
		if(a<=b)l=b+1,r=a+n-1;
		else l=b+1,r=a-1;
		printf("%lld\n",query(1,n*2,1,l,r).ab);
	}
	return 0;
}

