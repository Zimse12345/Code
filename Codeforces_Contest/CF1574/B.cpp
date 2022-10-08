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
#define mod 998244353
#define Mul int _; for(cin >> _; _; _ --)

using namespace std;

int read(){int qrx=0,qry=1;char qrc=getchar();
while(qrc<'0'||qrc>'9'){if(qrc=='-'){qry=-1,qrc=getchar();}qrc=getchar();}
while(qrc>='0'&&qrc<='9')qrx=qrx*10+qrc-48,qrc=getchar();return qrx*qry;}

int n, k, m, a[1000005];
int x, y, z, s, t, u, v, w;

signed main() {
	Mul {
		x=read(),y=read(),z=read(),m=read();
		if(x - 1 + y - 1 + z - 1 < m) {
			puts("No");
			continue;
		}
		int M = max(max(x, y), z);
		if(M - 1 - (x + y + z - M) > m) {//z-1-x-y>m
			puts("No");
			continue;
		}
		puts("Yes");
	}
	return 0;
}
