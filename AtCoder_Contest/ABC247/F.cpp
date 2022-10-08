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

const int N=1e6+7,Mod=998244353,INF=1e9+7;
int n,a[N],b[N],vis[N],f[2][N][2];
int ans=1;

signed main(){
	n=read();
	f[0][1][0]=f[1][1][1]=1;
	for(int i=0;i<2;i++){
		for(int j=2;j<=n;j++){
			f[i][j][0]=f[i][j-1][1];
			f[i][j][1]=(f[i][j-1][0]+f[i][j-1][1])%Mod;
		}
	}
	for(int i=1;i<=n;i++)a[i]=read();
	for(int i=1;i<=n;i++)b[a[i]]=read();
	for(int i=1;i<=n;i++)if(!vis[i]){
		int p=i,c=1;
		if(b[p]==p)continue;
		while(b[p]!=i&&b[p]!=p)p=b[p],++c,vis[p]=1;
		if(b[p]==i){
			ans=(ans*(f[1][c][1]+f[1][c][0]+f[0][c][1]))%Mod;
		}
		if(b[p]==p){
			ans=(ans*(f[0][c][1]+f[1][c][1]))%Mod;
		}
	}
	printf("%lld\n",ans);
	return 0;
}

