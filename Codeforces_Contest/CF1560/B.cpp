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

using namespace std;

int read(){int qrx=0,qry=1;char qrc=getchar();
while(qrc<'0'||qrc>'9'){if(qrc=='-'){qry=-1,qrc=getchar();}qrc=getchar();}
while(qrc>='0'&&qrc<='9')qrx=qrx*10+qrc-48,qrc=getchar();return qrx*qry;}

const int N=1e2+7,Mod=998244353,INF=1e9+7;
int T,a,b,k,t;

int main(){
	T=read();
	while(T--){
		a=read(),b=read(),k=read();
		if(a==b){
			printf("-1\n");
			continue;
		}
		if(a>b)t=a,a=b,b=t;
		int c=(b-a);
		if(b>c*2||k>c*2){
			printf("-1\n");
			continue;
		}
		if(k<=c)k+=c;
		else k-=c;
		printf("%d\n",k);
	}
	return 0;
}
