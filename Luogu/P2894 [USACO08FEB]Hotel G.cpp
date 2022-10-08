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

const int N=2e5+7,Mod=998244353,INF=1e9+7;
int n,m,Lx[N*4],Rx[N*4],Mx[N*4],tag[N*4],len[N*4];

void pushdown(int id){
	if(tag[id]!=0){
		if(tag[id]==-1)Lx[id]=Rx[id]=Mx[id]=len[id];
		else Lx[id]=Rx[id]=Mx[id]=0;
		if(len[id]!=1)tag[Lid]=tag[id],tag[Rid]=tag[id];
		tag[id]=0;
	}
	return;
}

void pushup(int id){
	Lx[id]=Lx[Lid]==len[Lid]?len[Lid]+Lx[Rid]:Lx[Lid];
	Rx[id]=Rx[Rid]==len[Rid]?len[Rid]+Rx[Lid]:Rx[Rid];
	Mx[id]=max(max(Mx[Lid],Mx[Rid]),Rx[Lid]+Lx[Rid]);
	return;
}

void build(int L,int R,int id){
	Lx[id]=Rx[id]=Mx[id]=len[id]=R-L+1;
	if(L!=R){
		int M=(L+R)>>1;
		build(L,M,Lid),build(M+1,R,Rid);
	}
	return;
}

void update(int L,int R,int id,int l,int r,int x){
	pushdown(id);
	if(r<L||l>R)return;
	if(l<=L&&r>=R)tag[id]=x,pushdown(id);
	else{
		int M=(L+R)>>1;
		update(L,M,Lid,l,r,x),update(M+1,R,Rid,l,r,x);
		pushup(id);
	}
	return;
}

int query(int L,int R,int id,int x){
	if(R-L+1<x)return 0;
	pushdown(id);if(L!=R)pushdown(Lid),pushdown(Rid);
	int M=(L+R)>>1;
	if(Mx[Lid]>=x)return query(L,M,Lid,x);
	if(Rx[Lid]+Lx[Rid]>=x){
		int ans=M-Rx[Lid]+1;
		update(1,n,1,ans,ans+x-1,1);
		return ans;
	}
	if(Mx[Rid]>=x)return query(M+1,R,Rid,x);
	return 0;
}

signed main(){
	n=read(),m=read();
	build(1,n,1);
	for(int i=1,op,x,y;i<=m;i++){
		op=read();
		if(op==1){
			x=read();
			printf("%d\n",query(1,n,1,x));
		}
		if(op==2){
			x=read(),y=read();
			update(1,n,1,x,x+y-1,-1);
		}
	}
	return 0;
}

