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

using namespace std;

inline int read(){int qrx=0,qry=1;char qrc=getchar();
while(qrc<'0'||qrc>'9'){if(qrc=='-'){qry=-1,qrc=getchar();}else qrc=getchar();}
while(qrc>='0'&&qrc<='9')qrx=qrx*10+qrc-48,qrc=getchar();return qrx*qry;}

const int N=60,Mod=1e9;
int n,m,a[N][N],s[N][N],f[N][N][N*N],ans;
bool vis[N][N][N*N];

signed main(){
	n=read(),m=read();
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n-i+1;j++)a[i][j]=read(),s[i][j]=a[i][j]+s[i-1][j+1];
	}
	vis[0][0][0]=1;
	for(int i=1;i<=n;i++){
		for(int k=0;k<=m;k++){
			f[i][0][k]=f[i-1][0][k];
			if(vis[i-1][0][k])vis[i][0][k]=1;
		}
		for(int j=1;j<=i;j++){
			for(int k=0;k+j<=m;k++)if(vis[i-1][j-1][k]){
				f[i][j][k+j]=max(f[i][j][k+j],f[i-1][j-1][k]+s[j][i-j+1]);
				vis[i][j][k+j]=1;
			}
			ans=max(ans,f[i][j][m]);
		}
		for(int k=0;k<=m;k++){
			for(int j=i-1;j>=0;j--){
				f[i][j][k]=max(f[i][j][k],f[i][j+1][k]);
				if(vis[i][j+1][k])vis[i][j][k]=1;
			}
		}
	}
	printf("%d\n",ans);
	return 0;
}
