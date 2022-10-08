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

const int N=1e2+7,Mod=1e9+7,INF=1e9+7;
int k,ans;

void exgcd(int a,int b,int& x,int& y){
	if(b==0){x=1,y=0;return;}
	exgcd(b,a%b,x,y);
	int t=x;x=y,y=t-a/b*y;
	return;
}

signed main(){
	k=read();
	int a=1,b=1;
	while(a+b<=k){
		int x,y;
		exgcd(a,b,x,y);
		x=(x*k%b+b)%b,y*=k;
		if(x==0)x=b;
		y=(k-a*x)/b;
		if(y>=0)ans=(ans+(y-1)/a+1)%Mod;
		int t=b;b=a+b,a=t;
	}
	printf("%lld\n",ans);
	return 0;
}
