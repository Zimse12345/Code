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

using namespace std;

int read(){int qrx=0,qry=1;char qrc=getchar();
while(qrc<'0'||qrc>'9'){if(qrc=='-'){qry=-1,qrc=getchar();}else qrc=getchar();}
while(qrc>='0'&&qrc<='9')qrx=qrx*10+qrc-48,qrc=getchar();return qrx*qry;}

const int N=1e6+7,Mod=998244353,INF=1e9+7;
int n,m,ans[N];

int main(){
	n=read(),m=read();
	if(n>1&&m==1)return !printf("-1\n");
	if(1ll*m*m<1ll*n)return !printf("-1\n");
	int p=n-m+1,q=p;
	for(int i=1;i<=n;i++){
		ans[i]=p,++p;
		if(p>=q+m)p=max(q-m,1),q=p;
	}
	for(int i=1;i<=n;i++)printf("%d ",ans[i]);
	printf("\n");
	return 0;
}
