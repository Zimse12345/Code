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

const int N=2e5+7,Mod=19940417,INF=1e15;
int n,q,a[N],add[N],rev[N],len[N],c[N][21];

struct node{
	int sum[21];
}t[N];

node merge(node A,node B){
	node res;
	for(int i=0;i<21;i++){
		res.sum[i]=0;
		for(int j=0;j<=i;j++)(res.sum[i]+=A.sum[j]*B.sum[i-j])%=Mod;
	}
	return res;
}

void build(int L,int R,int id){
	len[id]=R-L+1;
	if(L==R){
		t[id].sum[0]=1,t[id].sum[1]=a[L];
	}
	else{
		build(L,M,Lid),build(M+1,R,Rid);
		t[id]=merge(t[Lid],t[Rid]);
	}
	return;
}

void pushdown(int id){
	if(rev[id]){
		for(int i=1;i<21;i+=2)t[id].sum[i]=-t[id].sum[i];
		if(Rid<N)rev[Lid]^=1,add[Lid]=-add[Lid],rev[Rid]^=1,add[Rid]=-add[Rid];
	}
	if(add[id]!=0){
		for(int i=min(len[id],20ll);i;i--){
			for(int j=i-1,x=add[id];j>=0;j--,x=(x*add[id])%Mod){
				(t[id].sum[i]+=x*t[id].sum[j]%Mod*c[len[id]-j][i-j])%=Mod;
			}
		}
		if(Rid<N)(add[Lid]+=add[id])%=Mod,(add[Rid]+=add[id])%=Mod;
	}
	rev[id]=add[id]=0;
	return;
}

void increase(int L,int R,int id,int l,int r,int x){
	pushdown(id);
	if(r<L||R<l)return;
	if(l<=L&&r>=R)add[id]+=x,pushdown(id);
	else{
		increase(L,M,Lid,l,r,x),increase(M+1,R,Rid,l,r,x);
		t[id]=merge(t[Lid],t[Rid]);
	}
	return;
}

void reverse(int L,int R,int id,int l,int r){
	pushdown(id);
	if(r<L||R<l)return;
	if(l<=L&&r>=R)rev[id]^=1,pushdown(id);
	else{
		reverse(L,M,Lid,l,r),reverse(M+1,R,Rid,l,r);
		t[id]=merge(t[Lid],t[Rid]);
	}
	return;
}

node query(int L,int R,int id,int l,int r){
	pushdown(id);
	if(r<L||R<l){
		node res;
		res.sum[0]=1;
		for(int i=1;i<21;i++)res.sum[i]=0;
		return res;
	}
	if(l<=L&&r>=R)return t[id];
	return merge(query(L,M,Lid,l,r),query(M+1,R,Rid,l,r));
}

signed main(){
	n=read(),q=read();
	for(int i=1;i<=n;i++)a[i]=read();
	c[0][0]=1;
	for(int i=1;i<=n;i++){
		c[i][0]=1;
		for(int j=1;j<21;j++)c[i][j]=(c[i-1][j]+c[i-1][j-1])%Mod;
	}
	build(1,n,1);
	while(q--){
		char op=getchar();
		if(op<'A'||op>'Z')op=getchar();
		int l=read(),r=read();
		if(op=='I')increase(1,n,1,l,r,read());
		else if(op=='R')reverse(1,n,1,l,r);
		else printf("%lld\n",(query(1,n,1,l,r).sum[read()]+Mod)%Mod);
	}
	return 0;
}

