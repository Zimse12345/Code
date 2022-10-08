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

const int N=1e2+7,Mod=998244353,INF=1e12+7;
int T;
double a,b,s;

signed main(){
	T=read();
	while(T--){
		scanf("%lf%lf%lf",&a,&b,&s);
		if(a*b<s)printf("%.6lf%%\n",0.0);
		else if(s<1e-3)printf("%.6lf%%\n",100.0);
		else printf("%.6lf%%\n",100*(a*b-s*log(a*b/s)-s)/a/b);
	}
	return 0;
}

