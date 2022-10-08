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

const int N=1e2+7,Mod=998244353,INF=1e9+7;
int n,C,a[N][N],det=1;
inline int ldl(int x,int k=Mod-2){int res=1;while(k){if(k&1ll)res=(res*x)%Mod;x=(x*x)%Mod,k/=2;}return res;}

void see(){
	printf("\n");
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++)printf("%lld ",a[i][j]);
		printf("\n");
	}
	printf("\n\n");
}

signed main(){
	n=read(),C=read();
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++){
			if(i==j)a[i][j]=1;
			else if(j%i==0)a[i][j]=0;
			else a[i][j]=C;
		}
	}
	for(int i=1;i<=n;i++){
		int t=0;
		for(int j=i;j<=n;j++)if(a[j][i]){t=j;break;}
		if(!t){
			printf("0\n");
			return 0;
		}
		for(int j=1;j<=n;j++)swap(a[i][j],a[t][j]);
		det=(det*a[i][i])%Mod;
		for(int j=1;j<=n;j++)if(i^j)(a[i][j]*=ldl(a[i][i]))%=Mod;
		a[i][i]=1;
		for(int j=1;j<=n;j++)if(i^j){
			for(int k=1;k<=n;k++)if(i^k)(a[j][k]-=a[i][k]*a[j][i])%=Mod;
			a[j][i]=0;
		}
	}
	det=(det+Mod)%Mod;
	printf("%lld\n",det);
	return 0;
}

