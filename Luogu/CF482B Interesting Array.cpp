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

#define int unsigned
#define Lid (id<<1)
#define Rid ((id<<1)|1)
#define M ((L+R)>>1)

using namespace std;

int read(){int qrx=0,qry=1;char qrc=getchar();
while(qrc<'0'||qrc>'9'){if(qrc=='-'){qry=-1,qrc=getchar();}else qrc=getchar();}
while(qrc>='0'&&qrc<='9')qrx=qrx*10+qrc-48,qrc=getchar();return qrx*qry;}

const int N=2e5+7,Mod=998244353,INF=1e9+7;
int n,q,tag[N*4],ans=1,ql[N],qr[N],qx[N];

void update(int L,int R,int id,int l,int r,int x){
	tag[Lid]|=tag[id],tag[Rid]|=tag[id];
	if(r<L||l>R)return;
	if(l<=L&&r>=R)tag[id]|=x;
	else{
		update(L,M,Lid,l,r,x),update(M+1,R,Rid,l,r,x);
		tag[id]=tag[Lid]&tag[Rid];
	}
	return;
}

int query(int L,int R,int id,int l,int r){
	tag[Lid]|=tag[id],tag[Rid]|=tag[id];
	if(r<L||l>R)return 2147483647;
	if(l<=L&&r>=R)return tag[id];
	return query(L,M,Lid,l,r)&query(M+1,R,Rid,l,r);
}

signed main(){
	n=read(),q=read();
	for(int i=1,l,r,x;i<=q;i++){
		l=read(),r=read(),x=read();
		update(1,n,1,l,r,x);
		ql[i]=l,qr[i]=r,qx[i]=x;
	}
	for(int i=1;i<=q;i++){
		if(query(1,n,1,ql[i],qr[i])^qx[i]){
			printf("NO\n");
			return 0;
		}
	}
	printf("YES\n");
	for(int i=1;i<=n;i++)printf("%u ",query(1,n,1,i,i));
	printf("\n");
	return 0;
}

