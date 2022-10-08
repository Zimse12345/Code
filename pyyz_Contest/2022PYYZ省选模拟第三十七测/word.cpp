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

const int N=2e3+7,Mod=998244353,INF=1e9+7;
int n,m,k,ans,cnt,a[N],b[N],g[N][N],f[N][N],P[2000][20];

signed main(){
	n=read(),m=read(),k=read();
	for(int i=1;i<=m;i++)a[i]=read()-1,b[i]=read()-1;
	for(int i=0;i<(1<<k);i++){
		for(int j=0;j<k;j++){
			P[i][j]=1;
			for(int p=1;p<=m;p++)if((a[p]==j)&&(i&(1<<b[p]))){P[i][j]=0;break;}
		}
	}
	g[0][0]=1;
	for(int i=1,t=1;i<=n;i++,t*=10){
		for(int j=0;j<(1<<k);j++)if(g[i-1][j]){
			for(int v=0;v<k;v++){
				if(!P[j][v])continue;
				f[i][j|(1<<v)]+=(t*(v+1))*g[i-1][j]+f[i-1][j];
				g[i][j|(1<<v)]+=g[i-1][j];
			}
		}
	}
	for(int j=0;j<(1<<k);j++)ans+=f[n][j],cnt+=g[n][j];
	printf("%lld\n%lld\n",cnt,ans);
	return 0;
}
