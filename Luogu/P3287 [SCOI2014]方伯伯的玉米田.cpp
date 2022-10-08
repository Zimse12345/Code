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

const int N=1e4+7,Mod=998244353,INF=1e9+7;
int n,k,a[N],mx[6010][1010];

inline void db(int& x){x-=(x&(-x));return;}
inline void ub(int& x){x+=(x&(-x));return;}
inline void upt(int x,int y,int t){++x,++y;for(int i=x;i<6000;ub(i))for(int j=y;j<1000;ub(j))mx[i][j]=max(mx[i][j],t);return;}
inline int qmax(int x,int y){++x,++y;int res=0;for(int i=x;i;db(i))for(int j=y;j;db(j))res=max(res,mx[i][j]);return res;}

signed main(){
	n=read(),k=read();
	for(int i=1;i<=n;i++){
		a[i]=read();
		for(int j=k;j>=0;j--)upt(a[i]+j,j,qmax(a[i]+j,j)+1);
	}
	printf("%d\n",qmax(6000,1000));
	return 0;
}

