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

int read(){int qrx=0,qry=1;char qrc=getchar();
while(qrc<'0'||qrc>'9'){if(qrc=='-'){qry=-1,qrc=getchar();}else qrc=getchar();}
while(qrc>='0'&&qrc<='9')qrx=qrx*10+qrc-48,qrc=getchar();return qrx*qry;}

const int N=3e3+7,Mod=998244353,INF=1e9+7;
int n,a[N],b[N],f[N][N],ans;

signed main(){
	n=read();
	for(int i=1;i<=n;i++)a[i]=read();
	for(int i=1;i<=n;i++)b[i]=read();
	f[0][0]=1;
	for(int i=1;i<=n;i++){
		int sum=0;
		for(int j=0;j<=b[i];j++){
			sum=(sum+f[i-1][j])%Mod;
			if(j>=a[i])f[i][j]=sum;
		}
	}
	for(int i=a[n];i<=b[n];i++)ans=(ans+f[n][i])%Mod;
	printf("%lld\n",ans);
	return 0;
}

