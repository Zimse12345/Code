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

const int N=1e6+7,Mod=998244353,INF=1e9+7;
int T,n,p[N];

void sol(int x){
	if(x<0)return;
	int y=0;
	while(y*y<x)++y;
	int k=y*y-x,X=x;
	while(k<=X)p[x]=k,--x,++k;
	sol(x);
	return;
}

signed main(){
	T=read();
	while(T--){
		n=read();
		int x=0;
		while(x*x<n)++x;
		if(x*x==n){
			printf("0 ");
			for(int i=n-1;i>=1;i--)printf("%d ",i);
			printf("\n");
		}
		else{
			sol(n-1);
			for(int i=0;i<n;i++)printf("%d ",p[i]);
			printf("\n");
		}
	}
	return 0;
}

