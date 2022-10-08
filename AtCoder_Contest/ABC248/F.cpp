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

const int N=3e3+7,Mod=998244353,INF=1e9+7;
int n,P,f[N][N][2];
inline void add(int& x,int y){(x=(x+y)%P);return;}

signed main(){
	n=read(),P=read();
	f[1][1][0]=1;
	f[1][0][1]=1;
	for(int i=2;i<=n;i++){
		for(int j=0;j<n;j++){
			//from f[i-1][j][1]
			add(f[i][j][1],f[i-1][j][1]);//1111
			add(f[i][j+1][1],3*f[i-1][j][1]);//1011 1101 1110
			add(f[i][j+2][0],2*f[i-1][j][1]);//1001 1100
			//from f[i-1][j][0]
			add(f[i][j][1],f[i-1][j][0]);//0111
			add(f[i][j+1][0],f[i-1][j][0]);//0101
		}
	}
	for(int i=1;i<n;i++)printf("%lld ",f[n][i][1]);
	printf("\n");
	return 0;
}

