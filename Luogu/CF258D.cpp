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

#define ll long long
#define ull unsigned long long

using namespace std;

int read(){int qrx=0,qry=1;char qrc=getchar();
while(qrc<'0'||qrc>'9'){if(qrc=='-'){qry=-1,qrc=getchar();}qrc=getchar();}
while(qrc>='0'&&qrc<='9')qrx=qrx*10+qrc-48,qrc=getchar();return qrx*qry;}

const int N=1e3+7,Mod=998244353,INF=1e9+7;
int n,m,a[N];
double f[N][N],ans;

int main(){
	n=read(),m=read();
	for(int i=1;i<=n;i++)a[i]=read();
	for(int i=1;i<=n;i++)for(int j=1;j<=n;j++)f[i][j]=a[i]>a[j]?1:0;
	for(int i=1,x,y;i<=m;i++){
		x=read(),y=read();
		for(int t=1;t<=n;t++){
			f[t][x]=f[t][y]=0.5*(f[t][x]+f[t][y]);
			f[x][t]=f[y][t]=1.0-f[t][x];
		}
		f[x][y]=f[y][x]=0.5;
	}
	for(int i=1;i<=n;i++)for(int j=i+1;j<=n;j++)ans+=f[i][j];
	printf("%.7f\n",ans);
	return 0;
}