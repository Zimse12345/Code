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

const int N=1e2+7,Mod=998244353,INF=1e9+7;
int n,a[N],f[N][N],c[N][N];

int main(){
	n=read();
	for(int i=1;i<=n;i++)a[i]=read();
	for(int i=1;i<=n;i++){
		for(int j=i,t=0;j<=n;j++){
			if(a[j]!=j-i)++t;
			c[i][j]=t;
		}
	}
	for(int i=0;i<=n;i++)for(int j=0;j<=n;j++)f[i][j]=INF;
	f[0][0]=0;
	for(int i=1;i<=n;i++){
		for(int j=1;j<=i;j++){
			for(int k=1;k<=n;k++)f[i][k]=min(f[i][k],f[j-1][k-1]+c[j][i]);
		}
	}
	for(int i=1;i<=n;i++)printf("%d\n",f[n][i]);
	return 0;
}
