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

using namespace std;

int read(){int qrx=0,qry=1;char qrc=getchar();
while(qrc<'0'||qrc>'9'){if(qrc=='-'){qry=-1,qrc=getchar();}else qrc=getchar();}
while(qrc>='0'&&qrc<='9')qrx=qrx*10+qrc-48,qrc=getchar();return qrx*qry;}

const int N=1e6+7,INF=1e9+7;
struct query{
	int l,r,id;
	query(int l=0,int r=0,int id=0):l(l),r(r),id(id){}
	bool operator < (const query& A)const{return r<A.r;}
}q[N];
int n,m,a[N],mi[N],ans[N];

void update(int L,int R,int id,int x,int k){
	if(L==R)mi[id]=k;
	else{
		int M=(L+R)>>1;
		if(x<=M)update(L,M,Lid,x,k);
		else update(M+1,R,Rid,x,k);
		mi[id]=min(mi[Lid],mi[Rid]);
	}
	return;
}

int qy(int L,int R,int id,int x){
	if(L==R)return L;
	int M=(L+R)>>1;
	if(mi[Lid]<x)return qy(L,M,Lid,x);
	return qy(M+1,R,Rid,x);
}

signed main(){
	n=read(),m=read();
	for(int i=1;i<=n;i++)a[i]=read();
	for(int i=1,l,r;i<=m;i++)l=read(),r=read(),q[i]=query(l,r,i);
	sort(q+1,q+m+1);
	for(int i=1,l,r,p=0;i<=m;i++){
		l=q[i].l,r=q[i].r;
		while(p<r)++p,update(0,n,1,a[p],p);
		ans[q[i].id]=qy(0,n,1,l);
	}
	for(int i=1;i<=m;i++)printf("%d\n",ans[i]);
	return 0;
}
