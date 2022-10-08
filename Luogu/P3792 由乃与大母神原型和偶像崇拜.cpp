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

const int N=5e5+7,Mod=998244353,INF=1e9+7;
int n,m,a[N],s[25000007];
struct node{int sum,mx,mi;node(int sum=0,int mx=0,int mi=0):sum(sum),mx(mx),mi(mi){}}t[N*4];
inline node merge(node A,node B){return node(A.sum+B.sum,max(A.mx,B.mx),min(A.mi,B.mi));}

void build(int L,int R,int id){
	if(L==R)t[id]=node(a[L]*a[L],a[L],a[L]);
	else{
		build(L,M,Lid),build(M+1,R,Rid);
		t[id]=merge(t[Lid],t[Rid]);
	}
	return;
}

void update(int L,int R,int id,int x,int y){
	if(L==R)t[id]=node(y*y,y,y);
	else{
		if(x<=M)update(L,M,Lid,x,y);
		else update(M+1,R,Rid,x,y);
		t[id]=merge(t[Lid],t[Rid]);
	}
	return;
}

node query(int L,int R,int id,int l,int r){
	if(l>R||L>r)return node(0,-INF,INF);
	if(l<=L&&r>=R)return t[id];
	return merge(query(L,M,Lid,l,r),query(M+1,R,Rid,l,r));
}

signed main(){
	n=read(),m=read();
	for(int i=1;i<=n;i++)a[i]=read();
	for(int i=1;i<=25000000;i++)s[i]=s[i-1]+i*i;
	build(1,n,1);
	for(int i=1,op,x,y;i<=m;i++){
		op=read(),x=read(),y=read();
		if(op==1)update(1,n,1,x,y);
		else{
			node p=query(1,n,1,x,y);
			if(p.mx-p.mi+1==y-x+1&&p.sum==s[p.mx]-s[p.mi-1])printf("damushen\n");
			else printf("yuanxing\n");
		}
	} 
	return 0;
}

