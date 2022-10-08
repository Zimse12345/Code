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
int n,k,a[N],b[N],f[N][2];

signed main(){
	n=read(),k=read();
	for(int i=1;i<=n;i++)a[i]=read();
	for(int i=1;i<=n;i++)b[i]=read();
	f[1][0]=f[1][1]=1;
	for(int i=2;i<=n;i++){
		if(abs(a[i]-a[i-1])<=k)f[i][0]|=f[i-1][0];
		if(abs(a[i]-b[i-1])<=k)f[i][0]|=f[i-1][1];
		if(abs(b[i]-a[i-1])<=k)f[i][1]|=f[i-1][0];
		if(abs(b[i]-b[i-1])<=k)f[i][1]|=f[i-1][1];
	}
	if(f[n][0]||f[n][1])printf("Yes\n");
	else printf("No\n");
	return 0;
}

