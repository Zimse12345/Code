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
while(qrc>='0'&&qrc<='9')qrx=(qrx*10+qrc-48)%19260817,qrc=getchar();return qrx*qry;}

const int N=1e2+7,Mod=19260817,INF=1e9+7;
int a,b;

int qp(int x,int k){
	int res=1;
	while(k){
		if(k&1ll)res=(res*x)%Mod;
		x=(x*x)%Mod,k/=2;
	}
	return res;
}

signed main(){
	a=read(),b=read();
	printf("%lld\n",(a*qp(b,Mod-2))%Mod);
	return 0;
}
