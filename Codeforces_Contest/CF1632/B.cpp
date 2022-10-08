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

const int N=2e5+7,Mod=998244353,INF=1e9+7;
int T,n,p[N],t;

signed main(){
	T=read();
	while(T--){
		n=read(),t=0;
		int k=0,h=n;
		for(int i=1;n>(1<<i);i++)k=i;
		for(int i=n-1;i>=0;i--){
			if(i>=(1<<k))p[++t]=i,h=i;
			else break;
		}
		for(int i=0;i<h;i++)p[++t]=i;
		for(int i=1;i<=n;i++)printf("%d ",p[i]);
		printf("\n");
	}
	return 0;
}

