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

using namespace std;

inline int read(){int qrx=0,qry=1;char qrc=getchar();
while(qrc<'0'||qrc>'9'){if(qrc=='-'){qry=-1,qrc=getchar();}else qrc=getchar();}
while(qrc>='0'&&qrc<='9')qrx=qrx*10+qrc-48,qrc=getchar();return qrx*qry;}
inline void write(int x){if(x>9)write(x/10);putchar(x%10+'0');return;}

const int N=100,Mod=1e9;
int n,T,x,y,p,a[N][N],b[N][N],f[2][N][N];

signed main(){
	n=read()+1,T=read(),x=read(),y=read();
	for(int i=2;i<=n;i++)for(int j=2;j<=n;j++)a[i][j]=read();
	f[p][x+1][y+1]=1;
	for(int t=1;t<=T;t++){
		p^=1;
		for(int i=2;i<=n;i++)for(int j=2;j<=n;j++){
			++b[i][j];
			if(a[i][j]==b[i][j]){
				b[i][j]=0;
				f[p][i][j]=f[p^1][i-2][j-1]|f[p^1][i-1][j-2]
						  |f[p^1][i+1][j-2]|f[p^1][i+2][j-1]
						  |f[p^1][i-1][j+2]|f[p^1][i-2][j+1]
						  |f[p^1][i+1][j+2]|f[p^1][i+2][j+1];
			}
			else f[p][i][j]=0;
		}
	}
	int tot=0;
	for(int i=2;i<=n;i++)for(int j=2;j<=n;j++)if(f[p][i][j])++tot;
	printf("%lld\n",tot);
	for(int i=2;i<=n;i++)for(int j=2;j<=n;j++)if(f[p][i][j]){
		write(i-1),putchar(' '),write(j-1),putchar('\n');
	}
	return 0;
}
