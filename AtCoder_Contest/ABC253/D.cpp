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
while(qrc<'0'||qrc>'9'){if(qrc=='-'){qry=-1,qrc=getchar();}else qrc=getchar();}
while(qrc>='0'&&qrc<='9')qrx=qrx*10+qrc-48,qrc=getchar();return qrx*qry;}

const int N=4e5+7,Mod=998244353,INF=1e9+7;
int n,a,b;
int gcd(int x,int y){return y?gcd(y,x%y):x;}

signed main(){
	n=read(),a=read(),b=read();
	int ans=n*(n+1)/2;
	ans-=a*(n/a)*(n/a+1)/2;
	ans-=b*(n/b)*(n/b+1)/2;
	int g=a*b/gcd(a,b);
	ans+=g*(n/g)*(n/g+1)/2;
	printf("%lld\n",ans);
	return 0;
}

