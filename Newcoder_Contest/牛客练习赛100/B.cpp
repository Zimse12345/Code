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
while(qrc<'0'||qrc>'9'){if(qrc=='-')qry=-1;qrc=getchar();}
while(qrc>='0'&&qrc<='9')qrx=qrx*10+qrc-48,qrc=getchar();return qrx*qry;}

const int N=2e5+7,Mod=998244353,INF=1e9+7;
int n,a[N],f[2][2];
char s[N];

signed main(){
	n=read();
	for(int i=1;i<=n;i++)a[i]=read();
	scanf("%s",s+1);
	for(int i=1;i<=n;i++){
		int x=(a[i]&1)?0:1;
		int y=(s[i]=='R')?0:1;
		f[x][y]=max(f[x][y],f[x^1][y^1]+a[i]);
	}
	printf("%lld\n",max(max(f[0][0],f[0][1]),max(f[1][0],f[1][1])));
	return 0;
}

