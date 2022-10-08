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
#define int unsigned long long

using namespace std;

int read(){int qrx=0,qry=1;char qrc=getchar();
while(qrc<'0'||qrc>'9'){if(qrc=='-'){qry=-1,qrc=getchar();}qrc=getchar();}
while(qrc>='0'&&qrc<='9')qrx=qrx*10+qrc-48,qrc=getchar();return qrx*qry;}

const int N=1e6+7,Mod=998244353,INF=1e9+7;
int n,k,a[N];

signed main(){
	n=read(),k=read();
	int p=0;
	for(int i=1;i<=n;i++)a[i]=read(),p^=a[i];
	int u=1;
	int q=(u)<<(k);
	q=q-1;if(k==64)q=18446744073709551615; 
	p=max(p,q-p);
	
	printf("%llu\n",p);
	return 0;
}