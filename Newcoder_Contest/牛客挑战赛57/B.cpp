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
#define ull unsigned long long

using namespace std;

int read(){int qrx=0,qry=1;char qrc=getchar();
while(qrc<'0'||qrc>'9'){if(qrc=='-'){qry=-1,qrc=getchar();}else qrc=getchar();}
while(qrc>='0'&&qrc<='9')qrx=qrx*10+qrc-48,qrc=getchar();return qrx*qry;}

const int N=1e2+7,Mod=998244353,INF=1e9+7;
int n,m;

signed main(){
	n=read(),m=read();
	if(n==1&&m==1){
		printf("1 1 1 1 1\n");
		return 0;
	}
	int a=n*m,t=1;
	while(t*2<=a)t*=2;
	if(t%m==1||m==1){
		int x=t/m+1;
		if(t%m==0)--x;
		printf("%lld %lld %lld %lld %lld\n",t*2-1,x-1,1ll,x,m);
	}
	else{
		int x=t/m+1;
		if(t%m==0)--x;
		int y=t-(x-1)*m;
		printf("%lld %lld %lld %lld %lld\n",t*2-1,x,y-1,x,y);
	}
	return 0;
}

