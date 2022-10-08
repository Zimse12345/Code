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
const double E=1e-6;
int n,m;
double d,a1,an,f[N][N];
inline double Abs(double x){return x<0?-x:x;}

void Gauss(){
	for(int i=1;i<=n;i++){
		int t=i;
		for(int j=i+1;j<=n;j++)if(Abs(f[j][i])>=Abs(f[t][i]))t=j;
		for(int k=1;k<=n+1;k++)swap(f[i][k],f[t][k]);
		double p=f[i][i];
		for(int j=1;j<=n+1;j++)f[i][j]/=p;
		for(int j=1;j<=n;j++)if(j!=i){
			p=f[j][i]/f[i][i];
			for(int k=1;k<=n+1;k++)f[j][k]-=f[i][k]*p;
		}
	}
	return;
}

int main(){
	scanf("%d%d%lf%lf%lf",&n,&m,&d,&a1,&an);
	f[1][n+1]=a1,f[1][1]=1.0,f[n][n+1]=an,f[n][n]=1.0;
	for(int i=2;i<n;i++)f[i][i-1]=-0.5,f[i][i+1]=0.5,f[i][i]=1.0,f[i][n+1]=d;
	Gauss();
	printf("%.3lf",f[m][n+1]);
	return 0;
}
