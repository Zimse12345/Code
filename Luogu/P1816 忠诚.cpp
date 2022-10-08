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
#define ull unsigned long long

using namespace std;

int read(){int qrx=0,qry=1;char qrc=getchar();
while(qrc<'0'||qrc>'9'){if(qrc=='-'){qry=-1,qrc=getchar();}else qrc=getchar();}
while(qrc>='0'&&qrc<='9')qrx=qrx*10+qrc-48,qrc=getchar();return qrx*qry;}

const int N=1e5+7,Mod=998244353,INF=1e9+7;
int n,m,a[N];
int ans[N<<2];

void build(int L,int R,int id){
	if(L==R)ans[id]=a[L];
	else{
		int M=(L+R)>>1;
		build(L,M,id<<1),build(M+1,R,(id<<1)|1);
		ans[id]=min(ans[id<<1],ans[(id<<1)|1]);
	}
	return;
}

int query(int L,int R,int id,int l,int r){
	if(l<=L&&r>=R)return ans[id];
	int M=(L+R)>>1,res=INF;
	if(l<=M)res=min(res,query(L,M,id<<1,l,r));
	if(r>M)res=min(res,query(M+1,R,(id<<1)|1,l,r));
	return res;
}

int main(){
	n=read(),m=read();
	for(int i=1;i<=n;i++)a[i]=read();
	build(1,n,1);
	for(int i=1,l,r;i<=m;i++){
		l=read(),r=read();
		printf("%d ",query(1,n,1,l,r));
	}
	return 0;
}
