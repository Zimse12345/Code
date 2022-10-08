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

const int N=1e3+7,Mod=998244353,INF=1e9,EPS=1e-9;
int d,n;
double f[N][N],a[N][N],val[N];

signed main(){
//	freopen("d.in","r",stdin);
//	freopen("d.out","w",stdout);
	
	d=read(),n=read();
	for(int i=1;i<=n;i++){
		for(int j=1;j<=d;j++)scanf("%lf",&f[i][j]);
		scanf("%lf",&f[i][0]);
	}
	for(int i=1;i<n;i++){
		a[i][0]=f[i][0]*f[i][0]-f[i+1][0]*f[i+1][0];
		for(int j=1;j<=d;j++){
			a[i][0]+=-f[i][j]*f[i][j]+f[i+1][j]*f[i+1][j];
			a[i][j]=-2.0*f[i][j]+2.0*f[i+1][j];
		}
	}
	--n;
	for(int i=1,t,p=1;i<=d;i++){
		t=0;
		for(int j=p;j<=n;j++)if(abs(a[j][i])>EPS){t=j;break;}
		for(int j=0;j<=d;j++)swap(a[p][j],a[t][j]);
		if(!t)continue;
		for(int j=0;j<=d;j++)if(j!=i)a[p][j]/=a[p][i];a[p][i]=1;
		for(int j=1;j<=n;j++)if(j!=p){
			for(int k=0;k<=d;k++)if(k!=i)a[j][k]-=a[p][k]*a[j][i];
			a[j][i]=0;
		}
		++p;
	}
	for(int i=1;i<=d;i++){
		for(int j=1;j<=n;j++)if(abs(a[j][i]-1.0)<0.001){val[i]=a[j][0];break;}
	}
	for(int i=1;i<=d;i++)printf("%.9lf ",val[i]);
	return 0;
}

