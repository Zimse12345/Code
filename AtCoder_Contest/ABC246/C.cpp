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

const int N=1e6+7,Mod=998244353,INF=1e9+7;
int n,k,x,a[N];
ll sum;

signed main(){
	n=read(),k=read(),x=read();
	for(int i=1;i<=n;i++){
		a[i]=read();
		int t=a[i]/x;
		if(t<=k)k-=t,a[i]%=x;
		else a[i]-=k*x,k=0;
	}
	sort(a+1,a+n+1);
	for(int i=n;i>=n-k+1;i--){
		if(i<1)break;
		a[i]=max(0,a[i]-x);
	}
	for(int i=1;i<=n;i++)sum+=a[i];
	printf("%lld\n",sum);
	return 0;
}

