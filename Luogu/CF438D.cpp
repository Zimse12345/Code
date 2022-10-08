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

const int N=1e5+7,Mod=998244353,INF=1e9+7;
int n,m,a[N];
int sum[N<<2],mx[N<<2];

void pushup(int id){
	int Lid=id<<1,Rid=Lid|1;
	sum[id]=sum[Lid]+sum[Rid],mx[id]=max(mx[Lid],mx[Rid]);
	return;
}

void build(int L,int R,int id){
	if(L==R)sum[id]=mx[id]=a[L];
	else{
		int M=(L+R)>>1;
		build(L,M,id<<1),build(M+1,R,(id<<1)|1);
		pushup(id);
	}
	return;
}

void mod(int L,int R,int id,int l,int r,int p){
	if(L==R)a[L]%=p,sum[id]=mx[id]=a[L];
	else{
		int M=(L+R)>>1,Lid=id<<1,Rid=Lid|1;
		if(l<=M&&mx[Lid]>=p)mod(L,M,Lid,l,r,p);
		if(r>M&&mx[Rid]>=p)mod(M+1,R,Rid,l,r,p);
		pushup(id);
	}
	return;
}

void chg(int L,int R,int id,int x,int p){
	if(L==R)a[L]=p,sum[id]=mx[id]=a[L];
	else{
		int M=(L+R)>>1;
		if(x<=M)chg(L,M,id<<1,x,p);
		else chg(M+1,R,(id<<1)|1,x,p);
		pushup(id);
	}
	return;
}

int query(int L,int R,int id,int l,int r){
	if(l<=L&&r>=R)return sum[id];
	int res=0,M=(L+R)>>1;
	if(l<=M)res+=query(L,M,id<<1,l,r);
	if(r>M)res+=query(M+1,R,(id<<1)|1,l,r);
	return res;
}

signed main(){
	n=read(),m=read();
	for(int i=1;i<=n;i++)a[i]=read();
	build(1,n,1);
	for(int i=1,op,l,r,x,p;i<=m;i++){
		op=read();
		if(op==1){
			l=read(),r=read();
			printf("%lld\n",query(1,n,1,l,r));
		}
		if(op==2){
			l=read(),r=read(),p=read();
			mod(1,n,1,l,r,p);
		}
		if(op==3){
			x=read(),p=read();
			chg(1,n,1,x,p);
		}
	}
	return 0;
}
