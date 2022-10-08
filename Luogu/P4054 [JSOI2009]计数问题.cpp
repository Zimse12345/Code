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

const int N=350,Mod=998244353,INF=1e9+7;
int n,m,q,c[N][N][N],v[N][N];
inline void ub(int& x){x+=(x&(-x));return;}
inline void db(int& x){x-=(x&(-x));return;}

void add(int k,int x,int y,int t){
	for(int i=x;i<=n;ub(i)){
		for(int j=y;j<=m;ub(j))c[k][i][j]+=t;
	}
	return;
}

int query(int k,int x,int y){
	int res=0;
	for(int i=x;i;db(i)){
		for(int j=y;j;db(j))res+=c[k][i][j];
	}
	return res;
}

signed main(){
	n=read(),m=read();
	for(int i=1;i<=n;i++)for(int j=1;j<=m;j++)v[i][j]=read(),add(v[i][j],i,j,1);
	q=read();
	for(int i=1,op;i<=q;i++){
		op=read();
		if(op==1){
			int a=read(),b=read(),x=read();
			add(v[a][b],a,b,-1),add(x,a,b,1),v[a][b]=x;
		}
		else{
			int a1=read(),a2=read(),b1=read(),b2=read(),x=read();
			printf("%d\n",query(x,a2,b2)-query(x,a1-1,b2)-query(x,a2,b1-1)+query(x,a1-1,b1-1));
		}
	}
	return 0;
}

