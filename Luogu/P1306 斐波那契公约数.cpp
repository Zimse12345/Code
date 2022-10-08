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

const int N=1e2+7,Mod=1e8,INF=1e9+7;
int n;
inline int gcd(int x,int y){return y?gcd(y,x%y):x;}
struct node{int a,b,c,d;node(int a=0,int b=0,int c=0,int d=0):a(a),b(b),c(c),d(d){}};
inline node mul(node a,node b){return node((a.a*b.a+a.b*b.c)%Mod,(a.a*b.b+a.b*b.d)%Mod,(a.c*b.a+a.d*b.c)%Mod,(a.c*b.b+a.d*b.d)%Mod);}

signed main(){
	n=gcd(read(),read())-1;
	node s=node(1,1,1,0),res=node(1,0,0,0);
	while(n){
		if(n&1)res=mul(res,s);
		n>>=1,s=mul(s,s);
	}
	printf("%lld\n",res.a);
	return 0;
}

