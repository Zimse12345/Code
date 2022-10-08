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

const int N=1e5+7,Mod=998244353,INF=1e9+7;
int n,a,r;
struct line{
	int a,b;
	line(int a=0,int b=0):a(a),b(b){}
	bool operator < (const line& A)const{
		if(a!=A.a)return a<A.a;
		return b<A.b;
	}
}s[N];

inline int gcd(int a,int b){
	return b==0?a:gcd(b,a%b);
}

int main(){
	n=read();
	for(int i=1,a,b,g;i<=n;i++){
		a=read(),b=read(),g=read();
		g=gcd(a,b),a/=g,b/=g;
		s[i]=line(a,b);
	}
	sort(s+1,s+n+1);
	for(int i=1;i<=n;i++){
		if(s[i].a==s[i-1].a&&s[i].b==s[i-1].b)++r;
		else a=max(a,r),r=1;
	}
	a=max(a,r);
	printf("%d\n",n-a);
	return 0;
}
