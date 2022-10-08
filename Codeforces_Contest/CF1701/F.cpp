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
#define M ((L+R)/2)

using namespace std;

inline int read(){int qrx=0,qry=1;char qrc=getchar();
while(qrc<'0'||qrc>'9'){if(qrc=='-')qry=-1;qrc=getchar();}
while(qrc>='0'&&qrc<='9')qrx=qrx*10+qrc-48,qrc=getchar();return qrx*qry;}

const int N=4e6+7,Mod=998244353,INF=1e9+7;
int n,d,ans,vis[N],cnt[N],sum[N],tag[N];

struct node{
	int x,y;
	node(int x=0,int y=0):x(x),y(y){}
	node operator + (const node& A){
		return node(x+A.x,y+A.y);
	}
};

void pushdown(int id){
	tag[Lid]+=tag[id],tag[Rid]+=tag[id];
	sum[id]+=cnt[id]*tag[id],tag[id]=0;
	return;
}

node query(int L,int R,int id,int l,int r){
	pushdown(id);
	if(r<L||R<l)return node(0,0);
	if(l<=L&&r>=R)return node(cnt[id],sum[id]);
	return query(L,M,Lid,l,r)+query(M+1,R,Rid,l,r);
}

void add1(int L,int R,int id,int x,int y){
	pushdown(id);
	cnt[id]+=y;
	if(L!=R){
		if(x<=M)add1(L,M,Lid,x,y);
		else add1(M+1,R,Rid,x,y);
	}
	return;
}

void add2(int L,int R,int id,int l,int r,int k){
	pushdown(id);
	if(r<L||R<l)return;
	if(l<=L&&r>=R)tag[id]+=k,pushdown(id);
	else{
		add2(L,M,Lid,l,r,k),add2(M+1,R,Rid,l,r,k);
		sum[id]=sum[Lid]+sum[Rid];
	}
	return;
}

signed main(){
	n=read(),d=read();
	while(n--){
		int x=read();
		
		if(vis[x]){
			vis[x]=0;
			add2(1,400000,1,x-d,x-1,-1);
			ans-=query(1,400000,1,x-d,x-1).y;
			int r=query(1,400000,1,x+1,x+d).x;
			ans-=r*(r-1)/2;
			
			add2(1,400000,1,x,x,-r);
			add1(1,400000,1,x,-1);
		}
		else{
			vis[x]=1;
			ans+=query(1,400000,1,x-d,x-1).y;
			int r=query(1,400000,1,x+1,x+d).x;
			ans+=r*(r-1)/2;
			add2(1,400000,1,x-d,x-1,1);
			add1(1,400000,1,x,1);
			add2(1,400000,1,x,x,r);
		}
		printf("%lld\n",ans);
	}
	return 0;
}

