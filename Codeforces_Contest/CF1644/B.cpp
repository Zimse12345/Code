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

const int N=1e5+7,Mod=998244353,INF=1e9+7;
int T,n,a[N];

signed main(){
	T=read();
	while(T--){
		n=read();
		for(int i=1;i<=n;i++)a[n-i+1]=i;
		if(n==3){
			printf("%d %d %d\n%d %d %d\n%d %d %d\n",1,3,2,3,1,2,3,2,1);
			continue;
		}
		for(int i=1;i<=n;i++){
			for(int j=i;j<=n;j++)printf("%d ",a[j]);
			for(int j=1;j<i;j++)printf("%d ",a[j]);
			printf("\n");
		}
	}
	return 0;
}

