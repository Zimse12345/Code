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

const int N=30,Mod=998244353,INF=1e9+7;
int n,t,f[N][5][5][N][N],ans;
inline void add(int& x,int y){x+=y;return;}

signed main(){
	n=read(),t=read();
	for(int i=1;i<=4;i++)for(int j=1;j<=4;j++)if(i^j)f[2][i][j][0][0]=1;
	for(int i=2;i<n;i++){
		for(int a=1;a<=4;a++){
			for(int b=1;b<=4;b++)if(a^b){
				for(int c=1;c<=4;c++)if(b^c){
					for(int x=0,_x;x<=t;x++){
						_x=x;
						if(a<b&&b>c)++_x;
						for(int y=0,_y;y<=t;y++){
							_y=y;
							if(a>b&&b<c)++_y;
							add(f[i+1][b][c][_x][_y],f[i][a][b][x][y]);
						}
					}
				}
			}
		}
	}
	for(int i=1;i<=4;i++)for(int j=1;j<=4;j++)add(ans,f[n][i][j][t][t-1]);
	printf("%lld\n",ans);
	return 0;
}

