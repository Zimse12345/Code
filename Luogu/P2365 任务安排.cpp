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

const int N=3e5+7,Mod=998244353,INF=1e9+7;
int n,s,c[N],t[N],q[N],f[N],l,r;

int X(int id){return c[id];}
int Y(int id){return f[id]-s*c[id];}

signed main(){
	n=read(),s=read();
	for(int i=1;i<=n;i++)t[i]=read()+t[i-1],c[i]=read()+c[i-1];
	l=r=1;
	for(int i=1;i<=n;i++){
		while(l<r&&(Y(q[l+1])-Y(q[l]))<t[i]*(X(q[l+1])-X(q[l])))++l;
		int b=Y(q[l])-t[i]*X(q[l]);
		f[i]=b+t[i]*c[i]+s*c[n];
		while(l<r&&(Y(i)-Y(q[r]))*(X(q[r])-X(q[r-1]))<(Y(q[r])-Y(q[r-1]))*(X(i)-X(q[r])))--r;
		q[++r]=i;
	}
	printf("%lld\n",f[n]);
	return 0;
}
