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

const int N=2e5+7,Mod=998244353,INF=1e9+7;
inline int gcd(int x,int y){return y?gcd(y,x%y):x;}
struct node{int g,c;node(int g=0,int c=0):g(g),c(c){}}t[N*4];
int n,m,a[N];

node merge(node l,node r){
	node res=node(gcd(l.g,r.g),0);
	if(res.g==l.g)res.c+=l.c;
	if(res.g==r.g)res.c+=r.c;
	return res;
} 

void build(int L,int R,int id){
	if(L==R)t[id]=node(a[L],1);
	else{
		build(L,M,Lid),build(M+1,R,Rid);
		t[id]=merge(t[Lid],t[Rid]);
	}
	return;
}

node query(int L,int R,int id,int l,int r){
	if(l>R||r<L)return node(0,0);
	if(l<=L&&r>=R)return t[id];
	return merge(query(L,M,Lid,l,r),query(M+1,R,Rid,l,r));
}

signed main(){
	n=read();
	for(int i=1;i<=n;i++)a[i]=read();
	build(1,n,1);
	m=read();
	for(int i=1,l,r;i<=m;i++){
		l=read(),r=read();
		printf("%d\n",r-l+1-query(1,n,1,l,r).c);
	}
	return 0;
}

