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

inline int read(){int qrx=0,qry=1;char qrc=getchar();
while(qrc<'0'||qrc>'9'){if(qrc=='-'){qry=-1,qrc=getchar();}else qrc=getchar();}
while(qrc>='0'&&qrc<='9')qrx=qrx*10+qrc-48,qrc=getchar();return qrx*qry;}

const int N=1e3+7,Mod=998244353,INF=1e9+7;
int n,m,a[N],b[N],c[N];

signed main(){
	n=read(),m=read();
	for(int i=0;i<=n;i++)a[i]=read();
	for(int i=0;i<=n+m;i++)c[i]=read();
	for(int i=m;i>=0;i--){
		for(int j=i+1;j<=m;j++)c[i+n]-=b[j]*a[i+n-j];
		b[i]=c[i+n]/a[n];
	}
	for(int i=0;i<=m;i++)printf("%d ",b[i]);
	printf("\n");
	return 0;
}

