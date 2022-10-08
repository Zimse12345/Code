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

const int N=5e4+7,Mod=998244353,INF=1e9+7;
int n,m,d[N*4][32],D[32];

void ins(int id,int x){
	for(int i=30;i>=0;i--)if(x&(1<<i)){
		if(!d[id][i]){
			d[id][i]=x;
			return;
		}
		x^=d[id][i];
	}
	return;
}

void Ins(int x){
	for(int i=30;i>=0;i--)if(x&(1<<i)){
		if(!D[i]){
			D[i]=x;
			return;
		}
		x^=D[i];
	}
	return;
}

void update(int L,int R,int id,int x,int y){
	ins(id,y);
	if(L^R){
		if(x<=M)update(L,M,Lid,x,y);
		else update(M+1,R,Rid,x,y);
	}
	return;
}

void query(int L,int R,int id,int l,int r){
	if(l>R||L>r)return;
	if(l<=L&&r>=R){
		for(int i=30;i>=0;i--)if(d[id][i])Ins(d[id][i]);
	}
	else query(L,M,Lid,l,r),query(M+1,R,Rid,l,r);
	return;
}

signed main(){
	m=read(),n=read();
	int op,x,y,ans;
	while(m--){
		op=read(),x=read(),y=read();
		if(op==1)update(1,n,1,x,y);
		else{
			for(int i=0;i<=30;i++)D[i]=0;
			ans=0,query(1,n,1,x,y);
			for(int i=30;i>=0;i--)if((ans^D[i])>ans)ans^=D[i];
			printf("%d\n",ans);
		}
	}
	return 0;
}

