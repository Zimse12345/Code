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
#define Rid ((id<<1)|1)
#define M ((L+R)>>1)

using namespace std;

int read(){int qrx=0,qry=1;char qrc=getchar();
while(qrc<'0'||qrc>'9'){if(qrc=='-'){qry=-1,qrc=getchar();}else qrc=getchar();}
while(qrc>='0'&&qrc<='9')qrx=qrx*10+qrc-48,qrc=getchar();return qrx*qry;}

const int N=2e5+7,Mod=998244353,INF=1e9+7;
int T,n,m,a[N],sum[N*4],mx[N*4];

void build(int L,int R,int id){
	if(L==R)sum[id]=mx[id]=a[L];
	else{
		build(L,M,Lid),build(M+1,R,Rid);
		sum[id]=sum[Lid]+sum[Rid],mx[id]=max(mx[Lid],mx[Rid]);
	}
	return;
}

void update(int L,int R,int id,int l,int r){
	if(l>R||L>r||mx[id]==1)return;
	if(L==R)sum[id]=mx[id]=a[L]=sqrt(a[L]);
	else{
		update(L,M,Lid,l,r),update(M+1,R,Rid,l,r);
		sum[id]=sum[Lid]+sum[Rid],mx[id]=max(mx[Lid],mx[Rid]);
	}
	return;
}

int query(int L,int R,int id,int l,int r){
	if(l>R||L>r)return 0;
	if(l<=L&&r>=R)return sum[id];
	return query(L,M,Lid,l,r)+query(M+1,R,Rid,l,r);
}

signed main(){
	while(scanf("%lld",&n)==1){
		if(T)printf("\n");
		printf("Case #%lld:\n",++T);
		for(int i=1;i<=n;i++)a[i]=read();
		build(1,n,1);
		m=read();
		for(int i=1,op,l,r;i<=m;i++){
			op=read(),l=read(),r=read();
			if(l>r)swap(l,r);
			if(op)printf("%lld\n",query(1,n,1,l,r));
			else update(1,n,1,l,r);
		}
	}
	return 0;
}

