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

const int N=1e4+7,Mod=998244353,INF=1e9+7;
int T,n,a[N],b[N],ans[N];

signed main(){
	T=read();
	while(T--){
		n=read();
		for(int i=1;i<=n;i++)a[i]=read();
		for(int i=n;i>=1;i--){
			int t=0;
			for(int j=1;j<=i;j++)if(a[j]==i){t=j;break;}
			ans[i]=t%i;
			for(int j=1;j<=t;j++)b[i-t+j]=a[j];
			for(int j=t+1;j<=i;j++)b[j-t]=a[j];
			for(int j=1;j<=i;j++)a[j]=b[j];
		}
		for(int i=1;i<=n;i++)printf("%d ",ans[i]);
		printf("\n");
	}
	return 0;
}

