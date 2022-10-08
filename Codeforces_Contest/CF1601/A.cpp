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

const int N=2e5+7,Mod=998244353,INF=1e9+7;
int T,n,a[N],t[N],g;

int gcd(int x,int y){
	return y==0?x:gcd(y,x%y);
}

signed main(){
	T=read();
	while(T--){
		n=read(),g=0;
		for(int i=0;i<=30;i++)t[i]=0;
		for(int i=1;i<=n;i++){
			a[i]=read();
			for(int j=0;j<=30;j++)if(a[i]&(1ll<<j))++t[j];
		}
		for(int i=0;i<=30;i++)g=gcd(g,t[i]);
		for(int i=1;i<=n;i++)if(g%i==0)printf("%d ",i);
		printf("\n");
	}
	return 0;
}
