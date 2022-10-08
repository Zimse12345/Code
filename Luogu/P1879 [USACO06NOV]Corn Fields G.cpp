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

const int N=1e2+7,Mod=100000000,INF=1e9+7;
int n,m,z,a[N][N],f[N][N*N],ans=0;

signed main(){
	n=read(),m=read(),z=(1<<m);
	f[0][0]=1;
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++)a[i][j]=read();
		for(int x=0;x<z;x++){
			int tag=1;
			for(int j=0;j<m;j++)if((x&(1<<j))&&(a[i][j+1]==0||(j>0&&(x&(1<<(j-1)))))){tag=0;break;}
			if(tag==0)continue;
			for(int y=0;y<z;y++){
				int tagg=1;
				if(x&y)continue; 
				for(int j=0;j<m;j++)if((y&(1<<j))&&(a[i-1][j+1]==0||(j>0&&(y&(1<<(j-1)))))){tagg=0;break;}
				if(tagg==0)continue;
				f[i][x]=(f[i][x]+f[i-1][y])%Mod;
			}
		}
	}
	for(int x=0;x<z;x++)ans=(ans+f[n][x])%Mod;
	printf("%lld\n",ans);
	return 0;
}
