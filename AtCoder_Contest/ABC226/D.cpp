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

const int N=1e3+7,Mod=998244353,INF=1e9+7;
int n,x[N],y[N];
struct node{
	int x,y;
	node(int x=0,int y=0):x(x),y(y){}
	bool operator < (const node& A)const{if(x==A.x)return y<A.y;return x<A.x;}
};
set<node> s;

inline int gcd(int a,int b){
	return b==0?a:gcd(b,a%b);
}

int main(){
	n=read();
	for(int i=1;i<=n;i++)x[i]=read(),y[i]=read();
	for(int i=1;i<=n;i++)for(int j=1;j<=n;j++)if(i!=j){
		int dx=x[i]-x[j],dy=y[i]-y[j];
		int g=gcd(dx,dy);
		dx/=g,dy/=g;
		s.insert(node(dx,dy));
	}
	printf("%d\n",signed(s.size())*2);
	return 0;
}
