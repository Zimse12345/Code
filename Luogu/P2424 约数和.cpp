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

inline int read(){int qrx=0,qry=1;char qrc=getchar();
while(qrc<'0'||qrc>'9'){if(qrc=='-')qry=-1;qrc=getchar();}
while(qrc>='0'&&qrc<='9')qrx=qrx*10+qrc-48,qrc=getchar();return qrx*qry;}

const int N=1e2+7,Mod=998244353,INF=1e9+7;

int sol(int x){
	int res=0;
	for(int l=1,r;l<=x;){
		r=x/(x/l);
		res+=(l+r)*(r-l+1)/2*(x/l);
		l=r+1;
	}
	return res;
}

signed main(){
	int l=read(),r=read();
	printf("%lld\n",sol(r)-sol(l-1)); 
	return 0;
}

