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

const int N=1e2+7,Mod=998244353,INF=1e9+7;
int n;

int gcd(int a,int b){
	return b==0?a:gcd(b,a%b);
}

int lcm(int a,int b){
	return a*b/gcd(a,b);
}

signed main(){
	n=read();
	int m=1,k=0;
	for(int i=1;i<=n;i++)m=lcm(m,i);
	for(int i=1;i<=n;i++)k+=m/i;
	k*=n;
	int g=gcd(k,m);
	m/=g,k/=g;//k/m
	int p=k/m;
	k%=m;
	int q=p,w=0,w2=0;
	while(q>0)++w,q/=10;
	q=max(m,k);
	while(q>0)++w2,q/=10;
	if(k==0){
		printf("%lld\n",p);
		return 0;
	}
	for(int i=1;i<=w;i++)printf(" ");
	printf("%lld\n",k);
	printf("%lld",p);
	for(int i=1;i<=w2;i++)printf("-");
	printf("\n");
	for(int i=1;i<=w;i++)printf(" ");
	printf("%lld\n",m);
	return 0;
}
