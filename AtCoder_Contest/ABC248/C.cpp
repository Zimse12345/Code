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
int n,m,k,f[N][N*N],ans;

signed main(){
	n=read(),m=read(),k=read();
	f[0][0]=1;
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++){
			for(int t=j;t<=k;t++)f[i][t]=(f[i][t]+f[i-1][t-j])%Mod;
		}
	}
	for(int i=1;i<=k;i++)ans=(ans+f[n][i])%Mod;
	printf("%d\n",ans);
	return 0;
}

