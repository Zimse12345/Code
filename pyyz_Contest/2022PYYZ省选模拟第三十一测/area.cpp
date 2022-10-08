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

inline int read(){int qrx=0,qry=1;char qrc=getchar();
while(qrc<'0'||qrc>'9'){if(qrc=='-'){qry=-1,qrc=getchar();}else qrc=getchar();}
while(qrc>='0'&&qrc<='9')qrx=qrx*10+qrc-48,qrc=getchar();return qrx*qry;}

const int N=1e5+7,Mod=998244353,INF=1e9+7;
int n;
double x[N],y[N],ans;
inline double dis(int a,int b){return sqrt((x[a]-x[b])*(x[a]-x[b])+(y[a]-y[b])*(y[a]-y[b]));}

signed main(){
	n=read();
	for(int i=1;i<=n;i++)x[i]=read(),y[i]=read();
	if(n<=2){
		printf("0.0\n");
		return 0;
	}
	for(int A=1;A<=n;A++){
		for(int B=A+1;B<=n;B++){
			double D=0,U=0;
			double k=(y[B]-y[A])/(x[B]-x[A]);
			double b=y[A]-x[A]*k;
			for(int C=1;C<=n;C++)if(C!=A&&C!=B){
				double aa=dis(A,B),bb=dis(B,C),cc=dis(C,A);
				double p=(aa+bb+cc)/2;
				double s=sqrt(p*(p-aa)*(p-bb)*(p-cc));
				double v=k*x[C]+b;
				if(v<y[C])D=max(D,s);
				else U=max(U,s);
			}
			ans=max(ans,D+U);
		}
	}
	printf("%.1lf\n",ans);
	return 0;
}

