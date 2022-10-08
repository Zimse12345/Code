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

const int N=5e3+7,Mod=1e9+7,INF=1e9+7;
int n,m,f[N][N],ans;
char s[N];

signed main(){
	n=read();
	scanf("%s",s+1);
	m=strlen(s+1);
	f[0][0]=1;//f[opt][len]
	for(int i=1;i<=n;i++){
		for(int j=0;j<=n;j++){
			if(j!=0)f[i][j]=(f[i-1][j-1]+f[i-1][j+1]*2)%Mod;
			else f[i][j]=(f[i-1][j+1]*2)%Mod;
//			printf("f[%d][%d]=%d\n",i,j,f[i][j]);
		}
		f[i][0]=(f[i][0]+f[i-1][0])%Mod;
	}
//	for(int i=1;i<=n;i++)ans=(ans+f[i][m])%Mod;
	printf("%lld\n",f[n][m]);
	return 0;
}

