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

using namespace std;

ll read(){ll qrx=0,qry=1;char qrc=getchar();
while(qrc<'0'||qrc>'9'){if(qrc=='-'){qry=-1,qrc=getchar();}else qrc=getchar();}
while(qrc>='0'&&qrc<='9')qrx=qrx*10+qrc-48,qrc=getchar();return qrx*qry;}
inline void write(ll x){if(x<0){putchar('-'),x=-x;}if(x>9)write(x/10);putchar(x%10+'0');}

const int N=1e3+7,Mod=998244353,INF=1e9+7;
int n,m,sum[N][N][2][2];
inline void ub(int& x){x+=(x&(-x));return;}
inline void db(int& x){x-=(x&(-x));return;}

void update(int x,int y,int w){
	for(int i=x;i<=n;ub(i)){
		for(int j=y;j<=n;ub(j))sum[i][j][x&1][y&1]^=w;
	}
	return;
}

int query(int x,int y){
	int res=0;
	for(int i=x;i;db(i)){
		for(int j=y;j;db(j))res^=sum[i][j][x&1][y&1];
	}
	return res;
}

signed main(){
	n=read(),m=read();
	for(int i=1,op,lx,ly,rx,ry,w;i<=m;i++){
		op=read(),lx=read(),ly=read(),rx=read(),ry=read();
		if(op==2)w=read(),update(lx,ly,w),update(lx,ry+1,w),update(rx+1,ly,w),update(rx+1,ry+1,w);
		else write(query(rx,ry)^query(lx-1,ry)^query(rx,ly-1)^query(lx-1,ly-1)),putchar(10);
	}
	return 0;
}

