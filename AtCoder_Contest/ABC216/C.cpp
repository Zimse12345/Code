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
while(qrc<'0'||qrc>'9'){if(qrc=='-'){qry=-1,qrc=getchar();}qrc=getchar();}
while(qrc>='0'&&qrc<='9')qrx=qrx*10+qrc-48,qrc=getchar();return qrx*qry;}

const int N=1e2+7,Mod=998244353,INF=1e9+7;
int T,n,a[N];

int mk(int x){
	if(x==0)return 0;
	if(x%2==0){
		mk(x/2);
		printf("B");
	}
	else{
		mk(x/2);
		if(x!=1)printf("B");
		printf("A");
	}
	return 0;
}

signed main(){
	n=read();
	mk(n);
	printf("\n");
	return 0;
}

