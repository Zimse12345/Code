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

inline int read(){int qrx=0,qry=1;char qrc=getchar();
while(qrc<'0'||qrc>'9'){if(qrc=='-'){qry=-1,qrc=getchar();}else qrc=getchar();}
while(qrc>='0'&&qrc<='9')qrx=qrx*10+qrc-48,qrc=getchar();return qrx*qry;}

const int N=1e5+7,Mod=998244353,INF=1e9+7;
int m,n,q,a[N],k,f[3000][3000];

signed main(){
	m=read(),n=read(),q=read();
	f[1][0]=1;
	for(int i=1;i<=n;i++)a[i]=read(),f[1][i]=(f[1][i-1]*a[i])%Mod;
	for(int i=2;i<=m;i++){
		f[i][1]=(f[i-1][1]*a[1])%Mod;
		for(int j=2;j<=n;j++)f[i][j]=(f[i-1][j]+f[i][j-1])*a[j]%Mod;
	}
	while(q--){
		k=read();
		printf("%lld\n",f[k][n]);
	}
	return 0;
}

