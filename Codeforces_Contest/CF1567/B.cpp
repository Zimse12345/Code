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
while(qrc<'0'||qrc>'9'){if(qrc=='-'){qry=-1,qrc=getchar();}qrc=getchar();}
while(qrc>='0'&&qrc<='9')qrx=qrx*10+qrc-48,qrc=getchar();return qrx*qry;}

const int N=3e5+7,Mod=998244353,INF=1e9+7;
int T,a,b,x[N];

int main(){
	T=read();
	for(int i=1;i<N;i++)x[i]=x[i-1]^i;
	while(T--){
		a=read(),b=read();
		if(x[a-1]==b)printf("%d\n",a);
		else if((x[a-1]^b)!=a)printf("%d\n",a+1);
		else printf("%d\n",a+2);
	}
	return 0;
}

