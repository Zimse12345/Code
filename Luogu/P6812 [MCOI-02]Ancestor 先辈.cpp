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
#define ull unsigned long long

using namespace std;

int read(){int qrx=0,qry=1;char qrc=getchar();
while(qrc<'0'||qrc>'9'){if(qrc=='-'){qry=-1,qrc=getchar();}else qrc=getchar();}
while(qrc>='0'&&qrc<='9')qrx=qrx*10+qrc-48,qrc=getchar();return qrx*qry;}

const int N=1e6+7,Mod=998244353,INF=1e9+7;
int n,m,a[N];
int is[N<<2],tag[N<<2],lv[N<<2],rv[N<<2];

void pushup(int id){
	int Lid=id<<1,Rid=Lid|1;
	if(is[Lid]&&is[Rid]&&rv[Lid]<=lv[Rid])is[id]=1;
	else is[id]=0;
	lv[id]=lv[Lid],rv[id]=rv[Rid];
	return;
}

void pushdown(int id){
	if(tag[id]){
		int Lid=id<<1,Rid=Lid|1;
		lv[id]+=tag[id],rv[id]+=tag[id];
		tag[Lid]+=tag[id],tag[Rid]+=tag[id],tag[id]=0;
	}
	return;
}

void build(int L,int R,int id){
	if(L==R)lv[id]=rv[id]=a[L],is[id]=1;
	else{
		int M=(L+R)>>1;
		build(L,M,id<<1);
		build(M+1,R,(id<<1)|1);
		pushup(id);
	}
	return;
}

void update(int L,int R,int id,int l,int r,int x){
	pushdown(id);
	if(l<=L&&r>=R)tag[id]=x,pushdown(id);
	else{
		int M=(L+R)>>1;
		if(l<=M)update(L,M,id<<1,l,r,x);
		if(r>M)update(M+1,R,(id<<1)|1,l,r,x);
		pushdown(id<<1),pushdown((id<<1)|1);
		pushup(id);
	}
	return;
}

int query(int L,int R,int id,int l,int r){
	pushdown(id);
	if(l<=L&&r>=R)return is[id];
	int M=(L+R)>>1;
	if(l<=M&&query(L,M,id<<1,l,r)==0)return 0;
	if(r>M&&query(M+1,R,(id<<1)|1,l,r)==0)return 0;
	pushdown(id<<1),pushdown((id<<1)|1);
	if(l<=M&&r>M&&rv[id<<1]>lv[(id<<1)|1])return 0;
	return 1;
}

signed main(){
	n=read(),m=read();
	for(int i=1;i<=n;i++)a[i]=read();
	build(1,n,1);
	for(int i=1,op,l,r;i<=m;i++){
		op=read(),l=read(),r=read();
		if(op==1)update(1,n,1,l,r,read());
		else{
			if(query(1,n,1,l,r)==1)printf("Yes\n");
			else printf("No\n");
		}
	}
	return 0;
}
