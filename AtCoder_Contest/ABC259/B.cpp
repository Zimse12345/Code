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
while(qrc<'0'||qrc>'9'){if(qrc=='-')qry=-1;qrc=getchar();}
while(qrc>='0'&&qrc<='9')qrx=qrx*10+qrc-48,qrc=getchar();return qrx*qry;}

const int N=1e2+7,Mod=998244353,INF=1e9+7;
const double e=0.000000001;
long double x,y,d;

signed main(){
	x = read(), y = read(), d = read();
	d =  d / 180.0 * acos(-1);
	long double x_ = x * cos(d) - y * sin(d);
	long double y_ = x * sin(d) + y * cos(d);
	printf("%.7Lf %.7Lf\n",x_, y_);
	return 0;
}

