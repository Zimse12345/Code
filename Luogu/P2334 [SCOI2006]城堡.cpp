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
while(qrc<'0'||qrc>'9'){if(qrc=='-'){qry=-1,qrc=getchar();}else qrc=getchar();}
while(qrc>='0'&&qrc<='9')qrx=qrx*10+qrc-48,qrc=getchar();return qrx*qry;}

const int N=1e3+7,Mod=998244353,INF=1e9+7;
int n,h[N][20],c[N],f[10007][N],ans=INF;

int main(){
	n=read();
	c[0]=c[n+1]=1;
	for(int i=1;i<=n;i++){
		c[i]=read();
		for(int j=0;j<c[i];j++)h[i][j]=read();
	}
	for(int i=1;i<=n+2;i++)f[0][i]=INF;
	for(int t=1;t<=10000;t++){
		f[t][n+2]=INF;
		for(int i=1;i<=n+1;i++){
			f[t][i]=min(f[t-1][i],
			min(f[t-1][i-1],f[t-1][i+1]))+h[i][t%c[i]];
		}
	}
	for(int i=0;i<=10000;i++)ans=min(ans,f[i][n+1]);
	printf("%d\n",ans);
	return 0;
}

