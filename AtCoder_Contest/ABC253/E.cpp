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

const int N=4e5+7,Mod=998244353,INF=1e9+7;
int n,m,k,f[1100][5100],ans;
inline void add(int& x,int y){(x+=y)%=Mod;return;}

signed main(){
	n=read(),m=read(),k=read();
	for(int i=1;i<=m;i++)f[1][i]=1;
	for(int i=2;i<=n;i++){
		if(k==0){
			int s=0;
			for(int j=1;j<=m;j++)add(s,f[i-1][j]);
			for(int j=1;j<=m;j++)f[i][j]=s;
			continue;
		}
		int s=0;
		for(int j=k;j<=m;j++)add(s,f[i-1][j]);
		for(int j=1;j<=m;j++){
			if(j+k-1<=m)add(s,-f[i-1][j+k-1]);
			if(j-k>=1)add(s,f[i-1][j-k]);
			f[i][j]=s;
		}
	}
	for(int i=1;i<=m;i++)add(ans,f[n][i]);
	add(ans,Mod);
	printf("%lld\n",ans);
	return 0;
}

