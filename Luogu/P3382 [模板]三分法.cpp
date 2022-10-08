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
int n;
double L,R,x,LM,RM,a[N];

inline double check(double X){
	double Y=0,s=1;
	for(int i=0;i<=n;i++)Y+=a[i]*s,s*=X;
	return Y;
}

int main(){
	n=read();
	cin>>L>>R;
	for(int i=n;i>=0;i--)cin>>a[i];
	x=L;
	while(L+1e-6<R){
		LM=L+(R-L)/3.0,RM=R-(R-L)/3.0;
		if(check(LM)<=check(RM))L=LM,x=RM;
		else R=RM,x=LM;
	}
	printf("%.6lf",x);
	return 0;
}
