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
int n,m,a[N];
double f[N][N];

signed main(){
	n=read(),m=read();
	for(int i=1;i<=m;i++)a[i]=read();
	f[1][1]=100;
	for(int i=2;i<=n;i++){
		for(int j=1;j<=m;j++){
			int p=a[j]%i;
			if(p==0)p=i;
			for(int k=1;k<=i-1;k++){
				++p;
				if(p>i)p=1;
				f[i][p]+=f[i-1][k];
			}
		}
		for(int j=1;j<=i;j++)f[i][j]/=double(m);
	}
	for(int i=1;i<=n;i++)printf("%.2f",f[n][i]),putchar('%'),putchar(' ');
	putchar(10);
	return 0;
}

