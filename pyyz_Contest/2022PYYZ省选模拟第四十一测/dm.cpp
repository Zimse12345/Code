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

const int N=1e2+7,Mod=998244353,INF=1e9+7;
int n,m,q;

signed main(){
	freopen("d.in","w",stdout);
	srand(time(0));
	n=5000,m=n-1+rand()%(n/50),q=n/3;
	printf("%d %d %d\n",n,m,q);
	for(int i=2;i<=n;i++){
		int f=rand()%(i-1)+1;
		printf("%d %d\n",f,i),--m;
	}
	while(m--){
		int u=0,v=0;
		while(u==v)u=rand()%n+1,v=rand()%n+1;
		printf("%d %d\n",u,v);
	}
	return 0;
}

