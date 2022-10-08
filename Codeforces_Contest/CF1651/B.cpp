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
int T,n,a[N],p;

signed main(){
	T=read();
	a[1]=p=1;
	for(int i=2;i<=100;i++){
		a[i]=a[i-1]*3;
		if(a[i]>1e9)break;
		p=i;
	}
	while(T--){
		n=read();
		if(n>p){
			printf("NO\n");
		}
		else{
			printf("YES\n");
			for(int i=1;i<=n;i++)printf("%lld ",a[i]);
			printf("\n");
		}
	}
	return 0;
}

