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
while(qrc<'0'||qrc>'9'){if(qrc=='-')qry=-1;qrc=getchar();}
while(qrc>='0'&&qrc<='9')qrx=qrx*10+qrc-48,qrc=getchar();return qrx*qry;}

const int N=2e5+7,Mod=998244353,INF=1e9+7;
int n,k,a[N],b[N];

signed main(){
	n=read(),k=read();
	for(int i=1;i<=n;i++)a[i]=read();
	for(int i=1;i<=k;i++){
		int m=0,t=0;
		for(int j=i;j<=n;j+=k)b[++m]=a[j];
		sort(b+1,b+m+1);
		for(int j=i;j<=n;j+=k)a[j]=b[++t];
	}
	for(int i=1;i<n;i++)if(a[i]>a[i+1]){
		printf("No\n");
		return 0;
	}
	printf("Yes\n");
	return 0;
}

